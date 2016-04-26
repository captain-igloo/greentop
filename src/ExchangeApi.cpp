/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include <curl/curl.h>
#include <fstream>
#include <memory>
#include <sstream>

#include "greentop/curl/SList.h"
#include "greentop/DummyRequest.h"
#include "greentop/ExchangeApi.h"
#include "greentop/HttpCookie.h"

namespace greentop {

const std::string ExchangeApi::LOGIN_END_POINT = "https://identitysso.betfair.com/api/login";
const std::string ExchangeApi::HOST_UK = "https://api.betfair.com";
const std::string ExchangeApi::HOST_AUS = "https://api-au.betfair.com";

size_t writeToStream(char* buffer, size_t size, size_t nitems, std::ostream* stream) {

    size_t realwrote = size * nitems;
    stream->write(buffer, static_cast<std::streamsize>(realwrote));
    if (!(*stream)) {
        realwrote = 0;
    }

    return realwrote;
}

ExchangeApi::ExchangeApi(const std::string& applicationKey) {
    curl_global_init(CURL_GLOBAL_ALL);
    ssoid = "";
    this->applicationKey = applicationKey;
}

bool ExchangeApi::login(std::string username, std::string password) {

    bool success = false;

    std::unique_ptr<CURL, void(*)(CURL*)> curl(curl_easy_init(), curl_easy_cleanup);

    if (curl.get()) {
        curl_easy_setopt(curl.get(), CURLOPT_URL, LOGIN_END_POINT.c_str());
        curl_easy_setopt(curl.get(), CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl.get(), CURLOPT_COOKIE, "loggedIn=false; expires=Sun, 17-Jan-2038 19:14:07 GMT; path=/; domain=.betfair.com");

        std::string postFields = "username=" + username + "&password=" + password +
            "&login=true&redirectMethod=POST&product=" + applicationKey
            + "&url=https://www.betfair.com/";

        curl_easy_setopt(curl.get(), CURLOPT_POSTFIELDS, postFields.c_str());
        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl.get(), CURLOPT_COOKIEFILE, "");
        curl_easy_setopt(curl.get(), CURLOPT_NOSIGNAL, 1);
        char errorBuffer[CURL_ERROR_SIZE];
        curl_easy_setopt(curl.get(), CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;
        CURLcode curlResult = curl_easy_perform(curl.get());

        if (curlResult == CURLE_OK) {

            curl_slist* slist;
            curl_easy_getinfo(curl.get(), CURLINFO_COOKIELIST, &slist);
            SList cookies(slist);

            while (cookies.get()) {
                HttpCookie cookie(cookies.get()->data);
                cookies.set(cookies.get()->next);

                if (cookie.name == "ssoid") {
                    ssoid = cookie.value;
                } else if (cookie.name == "loggedIn" && cookie.value == "true") {
                    success = true;
                }

            }

        } else {
            throw std::runtime_error(errorBuffer);
        }

    }

    return success;

}

void ExchangeApi::logout() {
    ssoid = "";
}

void ExchangeApi::setApplicationKey(const std::string& appKey) {
    applicationKey = appKey;
}

void ExchangeApi::refreshMenu(const std::string& cacheFilename) {

    std::unique_ptr<CURL, void(*)(CURL*)> curl(curl_easy_init(), curl_easy_cleanup);

    if (curl.get()) {
        std::string url = ExchangeApi::HOST_UK + "/exchange/betting/rest/v1/en/navigation/menu.json";

        curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl.get(), CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl.get(), CURLOPT_ACCEPT_ENCODING, "gzip");
        curl_easy_setopt(curl.get(), CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &result);

        char errorBuffer[CURL_ERROR_SIZE];
        curl_easy_setopt(curl.get(), CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;

        SList chunk;
        std::string header = "X-Application: " + applicationKey;
        chunk.append(header);
        header = "X-Authentication: " + ssoid;
        chunk.append(header);
        curl_easy_setopt(curl.get(), CURLOPT_HTTPHEADER, chunk.get());

        CURLcode curlResult = curl_easy_perform(curl.get());

        if (curlResult == CURLE_OK) {

            if (cacheFilename != "") {
                std::fstream fs;
                fs.open(cacheFilename,  std::fstream::out);
                fs << result.str();
            }

            Json::Value json;
            result >> json;
            menu.fromJson(json);

        } else {
            throw std::runtime_error(errorBuffer);
        }
    }
}

menu::Menu& ExchangeApi::getMenu() {
    return menu;
}

ListCompetitionsResponse
ExchangeApi::listCompetitions(const Exchange exchange,
        const ListCompetitionsRequest& listCompetitionsRequest) const {
    ListCompetitionsResponse listCompetitionsResponse;
    performRequest(exchange, Api::BETTING, "listCompetitions", listCompetitionsRequest, listCompetitionsResponse);
    return listCompetitionsResponse;
}

ListCountriesResponse
ExchangeApi::listCountries(const Exchange exchange,
        const ListCountriesRequest& listCountriesRequest) const {
    ListCountriesResponse listCountriesResponse;
    performRequest(exchange, Api::BETTING, "listCountries", listCountriesRequest, listCountriesResponse);
    return listCountriesResponse;
}

CurrentOrderSummaryReport
ExchangeApi::listCurrentOrders(const Exchange exchange,
        const ListCurrentOrdersRequest& listCurrentOrdersRequest) const {
    CurrentOrderSummaryReport currentOrderSummaryReport;
    performRequest(exchange, Api::BETTING, "listCurrentOrders", listCurrentOrdersRequest, currentOrderSummaryReport);
    return currentOrderSummaryReport;
}

ClearedOrderSummaryReport
ExchangeApi::listClearedOrders(const Exchange exchange,
        const ListClearedOrdersRequest& listClearedOrdersRequest) const {
    ClearedOrderSummaryReport clearedOrderSummaryReport;
    performRequest(exchange, Api::BETTING, "listClearedOrders", listClearedOrdersRequest, clearedOrderSummaryReport);
    return clearedOrderSummaryReport;
}

ListEventTypesResponse
ExchangeApi::listEventTypes(const Exchange exchange,
        const ListEventTypesRequest& listEventTypesRequest) const {
    ListEventTypesResponse listEventTypesResponse;
    performRequest(exchange, Api::BETTING, "listEventTypes", listEventTypesRequest, listEventTypesResponse);
    return listEventTypesResponse;
}

ListEventsResponse
ExchangeApi::listEvents(const Exchange exchange,
        const ListEventsRequest& listEventsRequest) const {
    ListEventsResponse listEventsResponse;
    performRequest(exchange, Api::BETTING, "listEvents", listEventsRequest, listEventsResponse);
    return listEventsResponse;
}

ListMarketCatalogueResponse
ExchangeApi::listMarketCatalogue(const Exchange exchange,
        const ListMarketCatalogueRequest& listMarketCatalogueRequest) const {
    ListMarketCatalogueResponse listMarketCatalogueResponse;
    performRequest(exchange, Api::BETTING, "listMarketCatalogue", listMarketCatalogueRequest, listMarketCatalogueResponse);
    return listMarketCatalogueResponse;
}

ListMarketBookResponse
ExchangeApi::listMarketBook(const Exchange exchange,
        const ListMarketBookRequest& listMarketBookRequest) const {
    ListMarketBookResponse listMarketBookResponse;
    performRequest(exchange, Api::BETTING, "listMarketBook", listMarketBookRequest, listMarketBookResponse);
    return listMarketBookResponse;
}

PlaceExecutionReport
ExchangeApi::placeOrders(const Exchange exchange,
        const PlaceOrdersRequest& placeOrdersRequest) const {
    PlaceExecutionReport placeExecutionReport;
    performRequest(exchange, Api::BETTING, "placeOrders", placeOrdersRequest, placeExecutionReport);
    return placeExecutionReport;
}

CancelExecutionReport
ExchangeApi::cancelOrders(const Exchange exchange,
        const CancelOrdersRequest& cancelOrdersRequest) const {
    CancelExecutionReport cancelExecutionReport;
    performRequest(exchange, Api::BETTING, "cancelOrders", cancelOrdersRequest, cancelExecutionReport);
    return cancelExecutionReport;
}

ListMarketProfitAndLossResponse
ExchangeApi::listMarketProfitAndLoss(const Exchange exchange,
        const ListMarketProfitAndLossRequest& listMarketProfitAndLossRequest) const {
    ListMarketProfitAndLossResponse listMarketProfitAndLossResponse;
    performRequest(exchange, Api::BETTING, "listMarketProfitAndLoss", listMarketProfitAndLossRequest, listMarketProfitAndLossResponse);
    return listMarketProfitAndLossResponse;
}


ReplaceExecutionReport
ExchangeApi::replaceOrders(const Exchange exchange,
        const ReplaceOrdersRequest& replaceOrdersRequest) const {
    ReplaceExecutionReport replaceExecutionReport;
    performRequest(exchange, Api::BETTING, "replaceOrders", replaceOrdersRequest, replaceExecutionReport);
    return replaceExecutionReport;
}

AccountFundsResponse
ExchangeApi::getAccountFunds(const Exchange exchange,
        const GetAccountFundsRequest& getAccountFundsRequest) const {
    AccountFundsResponse accountFundsResponse;
    performRequest(exchange, Api::ACCOUNT, "getAccountFunds", getAccountFundsRequest, accountFundsResponse);
    return accountFundsResponse;
}

AccountDetailsResponse
ExchangeApi::getAccountDetails(const Exchange exchange) const {
    DummyRequest dummyRequest;
    AccountDetailsResponse accountDetailsResponse;
    performRequest(exchange, Api::ACCOUNT, "getAccountDetails", dummyRequest, accountDetailsResponse);
    return accountDetailsResponse;
}

TransferResponse
ExchangeApi::transferFunds(const Exchange exchange,
        const TransferFundsRequest& transferFundsRequest) const {
    TransferResponse transferResponse;
    performRequest(exchange, Api::ACCOUNT, "transferFunds", transferFundsRequest, transferResponse);
    return transferResponse;
}

DeveloperApp
ExchangeApi::createDeveloperAppKeys(const Exchange exchange,
        const CreateDeveloperAppKeysRequest& createDeveloperAppKeysRequest) const {
    DeveloperApp developerApp;
    performRequest(exchange, Api::ACCOUNT, "createDeveloperAppKeys", createDeveloperAppKeysRequest, developerApp);
    return developerApp;
}

GetDeveloperAppKeysResponse
ExchangeApi::getDeveloperAppKeys(const Exchange exchange) const {
    DummyRequest dummyRequest;
    GetDeveloperAppKeysResponse getDeveloperAppKeysResponse;
    performRequest(exchange, Api::ACCOUNT, "getDeveloperAppKeys", dummyRequest, getDeveloperAppKeysResponse);
    return getDeveloperAppKeysResponse;
}

AccountStatementReport
ExchangeApi::getAccountStatement(const Exchange exchange,
        const GetAccountStatementRequest& getAccountStatementRequest) const {
    AccountStatementReport accountStatementReport;
    performRequest(exchange, Api::ACCOUNT, "getAccountStatement", getAccountStatementRequest, accountStatementReport);
    return accountStatementReport;
}

ListCurrencyRatesResponse
ExchangeApi::listCurrencyRates(const Exchange exchange,
        const ListCurrencyRatesRequest& listCurrencyRatesRequest) const {
    ListCurrencyRatesResponse listCurrencyRatesResponse;
    performRequest(exchange, Api::ACCOUNT, "listCurrencyRates", listCurrencyRatesRequest, listCurrencyRatesResponse);
    return listCurrencyRatesResponse;
}

HeartbeatReport
ExchangeApi::heartbeat(const Exchange exchange,
        const HeartbeatRequest& heartbeatRequest) const {
    HeartbeatReport heartbeatReport;
    performRequest(exchange, Api::HEARTBEAT, "heartbeat", heartbeatRequest, heartbeatReport);
    return heartbeatReport;
}

ActivateApplicationSubscriptionResponse
ExchangeApi::activateApplicationSubscription(const Exchange exchange,
        const ActivateApplicationSubscriptionRequest& activateApplicationSubscriptionRequest) const {
    ActivateApplicationSubscriptionResponse activateApplicationSubscriptionResponse;
    performRequest(exchange, Api::ACCOUNT, "activateApplicationSubscription", activateApplicationSubscriptionRequest,
        activateApplicationSubscriptionResponse);
    return activateApplicationSubscriptionResponse;
}


bool ExchangeApi::performRequest(const Exchange exchange,
        const Api api,
        const std::string& method,
        const JsonRequest& jsonRequest, JsonResponse& jsonResponse) const {

    std::unique_ptr<CURL, void(*)(CURL*)> curl(curl_easy_init(), &curl_easy_cleanup);

    if (curl.get()) {

        SList headers;
        initRequest(exchange, api, method, curl.get(), headers);

        std::string request = jsonRequest.toString();

        if (request != "") {
            curl_easy_setopt(curl.get(), CURLOPT_POSTFIELDS, request.c_str());
        }

        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &result);

        char errorBuffer[CURL_ERROR_SIZE];
        curl_easy_setopt(curl.get(), CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;

        CURLcode curlResult = curl_easy_perform(curl.get());
        if (curlResult == CURLE_OK) {
            result >> jsonResponse;
        } else {
            throw std::runtime_error(errorBuffer);
        }

        return jsonResponse.isSuccess();
    }

    return false;
}

bool ExchangeApi::initRequest(const Exchange exchange, const Api api,
        const std::string method, CURL* curl, SList& headers) const {

    curl_easy_setopt(curl, CURLOPT_URL, buildUri(exchange, api, method).c_str());
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

    std::string header = "X-Application: " + applicationKey;
    headers.append(header);
    header = "X-Authentication: " + ssoid;
    headers.append(header);
    headers.append("content-type: application/json");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers.get());

    return true;
}

std::string ExchangeApi::buildUri(const Exchange exchange, const Api api, const std::string method) const {

    std::string apiString;
    switch (api) {
        case Api::ACCOUNT:
            apiString = "account";
            break;
        case Api::BETTING:
            apiString = "betting";
            break;
        case Api::HEARTBEAT:
            apiString = "heartbeat";
            break;
        default:
            throw std::runtime_error("invalid API");
    }

    switch (exchange) {
        case Exchange::UK:
            return HOST_UK + "/exchange/" + apiString + "/rest/v1.0/" + method + "/";
        case Exchange::AUS:
            return HOST_AUS + "/exchange/" + apiString + "/rest/v1.0/" + method + "/";
        default:
            throw std::runtime_error("invalid exchange");
    }

}

ExchangeApi::~ExchangeApi() {
    curl_global_cleanup();
}

}
