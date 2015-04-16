#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#include <sstream>

#include "greentop/ExchangeApi.h"
#include "greentop/DummyRequest.h"
#include "greentop/HttpCookie.h"

namespace greentop {

const std::string ExchangeApi::LOGIN_END_POINT = "https://identitysso.betfair.com/api/login";
const std::string ExchangeApi::HOST_UK = "https://api.betfair.com";
const std::string ExchangeApi::HOST_AUS = "https://api-au.betfair.com";

ExchangeApi::ExchangeApi(const std::string& applicationKey) {
    ssoid = "";
    this->applicationKey = applicationKey;
}

bool ExchangeApi::login(std::string username, std::string password) {

    bool success = false;

    curlpp::Cleanup myCleanup;
    curlpp::Easy loginRequest;

    loginRequest.setOpt(new curlpp::options::Url(std::string(LOGIN_END_POINT)));
    loginRequest.setOpt(new curlpp::options::SslEngineDefault());

    loginRequest.setOpt(new curlpp::options::CookieList(std::string("Set-Cookie: loggedIn=false; expires=Sun, 17-Jan-2038 19:14:07 GMT; path=/; domain=.betfair.com")));

    loginRequest.setOpt(new curlpp::options::PostFields("username=" + username +
        "&password=" + password +
        "&login=true&redirectMethod=POST&product=tsF2F5fsw0cPmwgh&url=https://www.betfair.com/"));

    std::stringstream result;
    loginRequest.setOpt(new curlpp::options::WriteStream(&result));

    loginRequest.perform();

    std::list<std::string> cookies;
    curlpp::infos::CookieList::get(loginRequest, cookies);

    for (std::list<std::string>::const_iterator it = cookies.begin(); it != cookies.end(); ++it) {
        HttpCookie cookie(*it);

        if (cookie.name == "ssoid") {
            ssoid = cookie.value;
        } else if (cookie.name == "loggedIn" && cookie.value == "true") {
            success = true;
        }
    }

    return success;

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

    curlpp::Cleanup myCleanup;
    curlpp::Easy curlRequest;

    initRequest(exchange, api, method, curlRequest);

    std::string request = jsonRequest.toString();

    if (request != "") {
        curlRequest.setOpt(new curlpp::options::PostFields(request));
    }

    std::stringstream result;
    curlRequest.setOpt(new curlpp::options::WriteStream(&result));
    curlRequest.perform();

    result >> jsonResponse;

    return jsonResponse.isSuccess();

}

bool ExchangeApi::initRequest(const Exchange exchange,
        const Api api,
        const std::string method, curlpp::Easy &request) const {

    request.setOpt(new curlpp::options::Url(buildUri(exchange, api, method)));

    request.setOpt(new curlpp::options::SslEngineDefault());
    request.setOpt(new curlpp::options::NoSignal(1));

    std::list<std::string> header;

    header.push_back("X-Application: " + applicationKey);
    header.push_back("X-Authentication: " + ssoid);
    header.push_back("content-type: application/json");
    request.setOpt(new curlpp::options::HttpHeader(header));

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

}
