/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <memory>
#include <sstream>

#include "greentop/DummyRequest.h"
#include "greentop/ExchangeApi.h"
#include "greentop/HttpCookie.h"

namespace greentop {

const std::string ExchangeApi::LOGIN_END_POINT_GLOBAL = "https://identitysso.betfair.com/api/login";
const std::string ExchangeApi::LOGIN_END_POINT_ITALY = "https://identitysso.betfair.it/api/login";
const std::string ExchangeApi::LOGIN_END_POINT_SPAIN = "https://identitysso.betfair.es/api/login";
const std::string ExchangeApi::LOGIN_END_POINT_ROMANIA = "https://identitysso.betfair.ro/api/login";

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
    // use global end point by default
    loginEndPoint = LOGIN_END_POINT_GLOBAL;
}

void ExchangeApi::setLoginEndPoint(const std::string& loginEndPoint) {
    this->loginEndPoint = loginEndPoint;
}

bool ExchangeApi::login(const std::string& username, const std::string& password) {
    bool success = false;

    std::unique_ptr<CURL, void(*)(CURL*)> curl(curl_easy_init(), curl_easy_cleanup);

    if (curl.get()) {
        curl_easy_setopt(curl.get(), CURLOPT_URL, loginEndPoint.c_str());
        curl_easy_setopt(curl.get(), CURLOPT_USE_SSL, CURLUSESSL_ALL);

        SList chunk;
        std::string header = "Accept: application/json";
        chunk.append(header);
        header = "X-Application: " + applicationKey;
        chunk.append(header);
        header = "Content-Type: application/x-www-form-urlencoded";
        chunk.append(header);
        curl_easy_setopt(curl.get(), CURLOPT_HTTPHEADER, chunk.get());

        std::string postFields = "username=" + username + "&password=" + password;
        curl_easy_setopt(curl.get(), CURLOPT_POSTFIELDS, postFields.c_str());

        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &result);

        curl_easy_setopt(curl.get(), CURLOPT_NOSIGNAL, 1);
        char errorBuffer[CURL_ERROR_SIZE];
        curl_easy_setopt(curl.get(), CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;
        CURLcode curlResult = curl_easy_perform(curl.get());

        if (curlResult == CURLE_OK) {
            Json::Value json;
            result >> json;

            if (json["status"].asString() == "SUCCESS") {
                ssoid = json["token"].asString();
                success = true;
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

void ExchangeApi::setSsoid(const std::string& ssoid) {
    this->ssoid = ssoid;
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

ListEventTypesResponse
ExchangeApi::listEventTypes(const Exchange exchange,
        const ListEventTypesRequest& request) const {
    ListEventTypesResponse response;
    performRequest(exchange, Api::BETTING, "listEventTypes", request, response);
    return response;
}

ListCompetitionsResponse
ExchangeApi::listCompetitions(const Exchange exchange,
        const ListCompetitionsRequest& request) const {
    ListCompetitionsResponse response;
    performRequest(exchange, Api::BETTING, "listCompetitions", request, response);
    return response;
}

ListTimeRangesResponse
ExchangeApi::listTimeRanges(const Exchange exchange,
        const ListTimeRangesRequest& request) const {
    ListTimeRangesResponse response;
    performRequest(exchange, Api::BETTING, "listTimeRanges", request, response);
    return response;
}

ListEventsResponse
ExchangeApi::listEvents(const Exchange exchange,
        const ListEventsRequest& request) const {
    ListEventsResponse response;
    performRequest(exchange, Api::BETTING, "listEvents", request, response);
    return response;
}

ListMarketTypesResponse
ExchangeApi::listMarketTypes(const Exchange exchange,
        const ListMarketTypesRequest& request) const {
    ListMarketTypesResponse response;
    performRequest(exchange, Api::BETTING, "listMarketTypes", request, response);
    return response;
}

ListCountriesResponse
ExchangeApi::listCountries(const Exchange exchange,
        const ListCountriesRequest& request) const {
    ListCountriesResponse response;
    performRequest(exchange, Api::BETTING, "listCountries", request, response);
    return response;
}

ListVenuesResponse
ExchangeApi::listVenues(const Exchange exchange,
        const ListVenuesRequest& request) const {
    ListVenuesResponse response;
    performRequest(exchange, Api::BETTING, "listVenues", request, response);
    return response;
}

ListMarketCatalogueResponse
ExchangeApi::listMarketCatalogue(const Exchange exchange,
        const ListMarketCatalogueRequest& request) const {
    ListMarketCatalogueResponse response;
    performRequest(exchange, Api::BETTING, "listMarketCatalogue", request, response);
    return response;
}

ListMarketBookResponse
ExchangeApi::listMarketBook(const Exchange exchange,
        const ListMarketBookRequest& request) const {
    ListMarketBookResponse response;
    performRequest(exchange, Api::BETTING, "listMarketBook", request, response);
    return response;
}

CurrentOrderSummaryReport
ExchangeApi::listCurrentOrders(const Exchange exchange,
        const ListCurrentOrdersRequest& request) const {
    CurrentOrderSummaryReport response;
    performRequest(exchange, Api::BETTING, "listCurrentOrders", request, response);
    return response;
}

ClearedOrderSummaryReport
ExchangeApi::listClearedOrders(const Exchange exchange,
        const ListClearedOrdersRequest& request) const {
    ClearedOrderSummaryReport response;
    performRequest(exchange, Api::BETTING, "listClearedOrders", request, response);
    return response;
}

PlaceExecutionReport
ExchangeApi::placeOrders(const Exchange exchange,
        const PlaceOrdersRequest& request) const {
    PlaceExecutionReport response;
    performRequest(exchange, Api::BETTING, "placeOrders", request, response);
    return response;
}

CancelExecutionReport
ExchangeApi::cancelOrders(const Exchange exchange,
        const CancelOrdersRequest& request) const {
    CancelExecutionReport response;
    performRequest(exchange, Api::BETTING, "cancelOrders", request, response);
    return response;
}

ReplaceExecutionReport
ExchangeApi::replaceOrders(const Exchange exchange,
        const ReplaceOrdersRequest& request) const {
    ReplaceExecutionReport response;
    performRequest(exchange, Api::BETTING, "replaceOrders", request, response);
    return response;
}

UpdateExecutionReport
ExchangeApi::updateOrders(const Exchange exchange,
        const UpdateOrdersRequest& request) const {
    UpdateExecutionReport response;
    performRequest(exchange, Api::BETTING, "updateOrders", request, response);
    return response;
}

ListMarketProfitAndLossResponse
ExchangeApi::listMarketProfitAndLoss(const Exchange exchange,
        const ListMarketProfitAndLossRequest& request) const {
    ListMarketProfitAndLossResponse response;
    performRequest(exchange, Api::BETTING, "listMarketProfitAndLoss", request, response);
    return response;
}

DeveloperApp
ExchangeApi::createDeveloperAppKeys(const Exchange exchange,
        const CreateDeveloperAppKeysRequest& request) const {
    DeveloperApp response;
    performRequest(exchange, Api::ACCOUNT, "createDeveloperAppKeys", request, response);
    return response;
}

GetDeveloperAppKeysResponse
ExchangeApi::getDeveloperAppKeys(const Exchange exchange) const {
    DummyRequest request;
    GetDeveloperAppKeysResponse response;
    performRequest(exchange, Api::ACCOUNT, "getDeveloperAppKeys", request, response);
    return response;
}

AccountFundsResponse
ExchangeApi::getAccountFunds(const Exchange exchange,
        const GetAccountFundsRequest& request) const {
    AccountFundsResponse response;
    performRequest(exchange, Api::ACCOUNT, "getAccountFunds", request, response);
    return response;
}

TransferResponse
ExchangeApi::transferFunds(const Exchange exchange,
        const TransferFundsRequest& request) const {
    TransferResponse response;
    performRequest(exchange, Api::ACCOUNT, "transferFunds", request, response);
    return response;
}

AccountDetailsResponse
ExchangeApi::getAccountDetails(const Exchange exchange) const {
    DummyRequest request;
    AccountDetailsResponse response;
    performRequest(exchange, Api::ACCOUNT, "getAccountDetails", request, response);
    return response;
}

GetVendorClientIdResponse
ExchangeApi::getVendorClientId(const Exchange exchange) const {
    DummyRequest request;
    GetVendorClientIdResponse response;
    performRequest(exchange, Api::ACCOUNT, "getVendorClientId", request, response);
    return response;
}

GetApplicationSubscriptionTokenResponse
ExchangeApi::getApplicationSubscriptionToken(const Exchange exchange,
        const GetApplicationSubscriptionTokenRequest& request) const {
    GetApplicationSubscriptionTokenResponse response;
    performRequest(exchange, Api::ACCOUNT, "getApplicationSubscriptionToken", request, response);
    return response;
}

ActivateApplicationSubscriptionResponse
ExchangeApi::activateApplicationSubscription(const Exchange exchange,
        const ActivateApplicationSubscriptionRequest& request) const {
    ActivateApplicationSubscriptionResponse response;
    performRequest(exchange, Api::ACCOUNT, "activateApplicationSubscription", request, response);
    return response;
}

CancelApplicationSubscriptionResponse
ExchangeApi::cancelApplicationSubscription(const Exchange exchange,
        const CancelApplicationSubscriptionRequest& request) const {
    CancelApplicationSubscriptionResponse response;
    performRequest(exchange, Api::ACCOUNT, "cancelApplicationSubscription", request, response);
    return response;
}

UpdateApplicationSubscriptionResponse
ExchangeApi::updateApplicationSubscription(const Exchange exchange,
        const UpdateApplicationSubscriptionRequest& request) const {
    UpdateApplicationSubscriptionResponse response;
    performRequest(exchange, Api::ACCOUNT, "updateApplicationSubscription", request, response);
    return response;
}

ListApplicationSubscriptionTokensResponse
ExchangeApi::listApplicationSubscriptionTokens(const Exchange exchange,
        const ListApplicationSubscriptionTokensRequest& request) const {
    ListApplicationSubscriptionTokensResponse response;
    performRequest(exchange, Api::ACCOUNT, "listApplicationSubscriptionTokens", request, response);
    return response;
}

ListAccountSubscriptionTokensResponse
ExchangeApi::listAccountSubscriptionTokens(const Exchange exchange) const {
    DummyRequest request;
    ListAccountSubscriptionTokensResponse response;
    performRequest(exchange, Api::ACCOUNT, "listAccountSubscriptionTokens", request, response);
    return response;
}

GetApplicationSubscriptionHistoryResponse
ExchangeApi::getApplicationSubscriptionHistory(const Exchange exchange,
        const GetApplicationSubscriptionHistoryRequest& request) const {
    GetApplicationSubscriptionHistoryResponse response;
    performRequest(exchange, Api::ACCOUNT, "getApplicationSubscriptionHistory", request, response);
    return response;
}

AccountStatementReport
ExchangeApi::getAccountStatement(const Exchange exchange,
        const GetAccountStatementRequest& request) const {
    AccountStatementReport response;
    performRequest(exchange, Api::ACCOUNT, "getAccountStatement", request, response);
    return response;
}

ListCurrencyRatesResponse
ExchangeApi::listCurrencyRates(const Exchange exchange,
        const ListCurrencyRatesRequest& request) const {
    ListCurrencyRatesResponse response;
    performRequest(exchange, Api::ACCOUNT, "listCurrencyRates", request, response);
    return response;
}

HeartbeatReport
ExchangeApi::heartbeat(const Exchange exchange,
        const HeartbeatRequest& request) const {
    HeartbeatReport response;
    performRequest(exchange, Api::HEARTBEAT, "heartbeat", request, response);
    return response;
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
