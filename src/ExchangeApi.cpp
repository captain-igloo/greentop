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

namespace greentop {

const std::string ExchangeApi::LOGIN_END_POINT_GLOBAL = "https://identitysso.betfair.com/api/login";
const std::string ExchangeApi::LOGIN_END_POINT_ITALY = "https://identitysso.betfair.it/api/login";
const std::string ExchangeApi::LOGIN_END_POINT_SPAIN = "https://identitysso.betfair.es/api/login";
const std::string ExchangeApi::LOGIN_END_POINT_ROMANIA = "https://identitysso.betfair.ro/api/login";

const std::string ExchangeApi::LOGIN_END_POINT_GLOBAL_CERT = "https://identitysso.betfair.com/api/certlogin";

const std::string ExchangeApi::HOST_UK = "https://api.betfair.com";
// const std::string ExchangeApi::HOST_AUS = "https://api-au.betfair.com";

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
    loginEndPointCert = LOGIN_END_POINT_GLOBAL_CERT;
}

void ExchangeApi::setLoginEndPoint(const std::string& loginEndPoint) {
    this->loginEndPoint = loginEndPoint;
}

bool ExchangeApi::login(const std::string& username, const std::string& password,
    const std::string& certFilename, const std::string& keyFilename) {

    bool success = false;
    bool loginWithCert = false;
    std::string endPoint = loginEndPoint;
    std::string xApplicationHeader = applicationKey;
    std::string statusKey = "status";
    std::string tokenKey = "token";

    if (certFilename != "" && keyFilename != "") {
        loginWithCert = true;
        endPoint = loginEndPointCert;
        xApplicationHeader = "greentop";
        statusKey = "loginStatus";
        tokenKey = "sessionToken";
    }

    std::unique_ptr<CURL, void(*)(CURL*)> curl(curl_easy_init(), curl_easy_cleanup);

    if (curl.get()) {
        curl_easy_setopt(curl.get(), CURLOPT_URL, endPoint.c_str());
        curl_easy_setopt(curl.get(), CURLOPT_USE_SSL, CURLUSESSL_ALL);

        SList chunk;
        std::string header = "Accept: application/json";
        chunk.append(header);
        header = "X-Application: " + xApplicationHeader;
        chunk.append(header);
        header = "Content-Type: application/x-www-form-urlencoded";
        chunk.append(header);
        curl_easy_setopt(curl.get(), CURLOPT_HTTPHEADER, chunk.get());

        if (loginWithCert) {
            curl_easy_setopt(curl.get(), CURLOPT_SSLCERT, certFilename.c_str());
            curl_easy_setopt(curl.get(), CURLOPT_SSLKEY, keyFilename.c_str());
        }

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

            if (json[statusKey].asString() == "SUCCESS") {
                ssoid = json[tokenKey].asString();
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

bool ExchangeApi::refreshMenu(const std::string& cacheFilename) {
    bool refreshResult = false;

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
            if (json.isMember("children")) {
                menu.fromJson(json);
                refreshResult = true;
            } // else error, might not be logged in.

        } else {
            throw std::runtime_error(errorBuffer);
        }
    }
    return refreshResult;
}

menu::Menu& ExchangeApi::getMenu() {
    return menu;
}

ListEventTypesResponse
ExchangeApi::listEventTypes(const ListEventTypesRequest& request) const {
    ListEventTypesResponse response;
    performRequest(Api::BETTING, "listEventTypes", request, response);
    return response;
}

ListCompetitionsResponse
ExchangeApi::listCompetitions(const ListCompetitionsRequest& request) const {
    ListCompetitionsResponse response;
    performRequest(Api::BETTING, "listCompetitions", request, response);
    return response;
}

ListTimeRangesResponse
ExchangeApi::listTimeRanges(const ListTimeRangesRequest& request) const {
    ListTimeRangesResponse response;
    performRequest(Api::BETTING, "listTimeRanges", request, response);
    return response;
}

ListEventsResponse
ExchangeApi::listEvents(const ListEventsRequest& request) const {
    ListEventsResponse response;
    performRequest(Api::BETTING, "listEvents", request, response);
    return response;
}

ListMarketTypesResponse
ExchangeApi::listMarketTypes(const ListMarketTypesRequest& request) const {
    ListMarketTypesResponse response;
    performRequest(Api::BETTING, "listMarketTypes", request, response);
    return response;
}

ListCountriesResponse
ExchangeApi::listCountries(const ListCountriesRequest& request) const {
    ListCountriesResponse response;
    performRequest(Api::BETTING, "listCountries", request, response);
    return response;
}

ListVenuesResponse
ExchangeApi::listVenues(const ListVenuesRequest& request) const {
    ListVenuesResponse response;
    performRequest(Api::BETTING, "listVenues", request, response);
    return response;
}

ListMarketCatalogueResponse
ExchangeApi::listMarketCatalogue(const ListMarketCatalogueRequest& request) const {
    ListMarketCatalogueResponse response;
    performRequest(Api::BETTING, "listMarketCatalogue", request, response);
    return response;
}

ListMarketBookResponse
ExchangeApi::listMarketBook(const ListMarketBookRequest& request) const {
    ListMarketBookResponse response;
    performRequest(Api::BETTING, "listMarketBook", request, response);
    return response;
}

ListRunnerBookResponse
ExchangeApi::listRunnerBook(const ListRunnerBookRequest& request) const {
    ListRunnerBookResponse response;
    performRequest(Api::BETTING, "listRunnerBook", request, response);
    return response;
}

CurrentOrderSummaryReport
ExchangeApi::listCurrentOrders(const ListCurrentOrdersRequest& request) const {
    CurrentOrderSummaryReport response;
    performRequest(Api::BETTING, "listCurrentOrders", request, response);
    return response;
}

ClearedOrderSummaryReport
ExchangeApi::listClearedOrders(const ListClearedOrdersRequest& request) const {
    ClearedOrderSummaryReport response;
    performRequest(Api::BETTING, "listClearedOrders", request, response);
    return response;
}

PlaceExecutionReport
ExchangeApi::placeOrders(const PlaceOrdersRequest& request) const {
    PlaceExecutionReport response;
    performRequest(Api::BETTING, "placeOrders", request, response);
    return response;
}

CancelExecutionReport
ExchangeApi::cancelOrders(const CancelOrdersRequest& request) const {
    CancelExecutionReport response;
    performRequest(Api::BETTING, "cancelOrders", request, response);
    return response;
}

ReplaceExecutionReport
ExchangeApi::replaceOrders(const ReplaceOrdersRequest& request) const {
    ReplaceExecutionReport response;
    performRequest(Api::BETTING, "replaceOrders", request, response);
    return response;
}

UpdateExecutionReport
ExchangeApi::updateOrders(const UpdateOrdersRequest& request) const {
    UpdateExecutionReport response;
    performRequest(Api::BETTING, "updateOrders", request, response);
    return response;
}

ListMarketProfitAndLossResponse
ExchangeApi::listMarketProfitAndLoss(const ListMarketProfitAndLossRequest& request) const {
    ListMarketProfitAndLossResponse response;
    performRequest(Api::BETTING, "listMarketProfitAndLoss", request, response);
    return response;
}

DeveloperApp
ExchangeApi::createDeveloperAppKeys(const CreateDeveloperAppKeysRequest& request) const {
    DeveloperApp response;
    performRequest(Api::ACCOUNT, "createDeveloperAppKeys", request, response);
    return response;
}

GetDeveloperAppKeysResponse
ExchangeApi::getDeveloperAppKeys() const {
    DummyRequest request;
    GetDeveloperAppKeysResponse response;
    performRequest(Api::ACCOUNT, "getDeveloperAppKeys", request, response);
    return response;
}

AccountFundsResponse
ExchangeApi::getAccountFunds(const GetAccountFundsRequest& request) const {
    AccountFundsResponse response;
    performRequest(Api::ACCOUNT, "getAccountFunds", request, response);
    return response;
}

TransferResponse
ExchangeApi::transferFunds(const TransferFundsRequest& request) const {
    TransferResponse response;
    performRequest(Api::ACCOUNT, "transferFunds", request, response);
    return response;
}

AccountDetailsResponse
ExchangeApi::getAccountDetails() const {
    DummyRequest request;
    AccountDetailsResponse response;
    performRequest(Api::ACCOUNT, "getAccountDetails", request, response);
    return response;
}

GetVendorClientIdResponse
ExchangeApi::getVendorClientId() const {
    DummyRequest request;
    GetVendorClientIdResponse response;
    performRequest(Api::ACCOUNT, "getVendorClientId", request, response);
    return response;
}

GetApplicationSubscriptionTokenResponse
ExchangeApi::getApplicationSubscriptionToken(const GetApplicationSubscriptionTokenRequest& request) const {
    GetApplicationSubscriptionTokenResponse response;
    performRequest(Api::ACCOUNT, "getApplicationSubscriptionToken", request, response);
    return response;
}

ActivateApplicationSubscriptionResponse
ExchangeApi::activateApplicationSubscription(const ActivateApplicationSubscriptionRequest& request) const {
    ActivateApplicationSubscriptionResponse response;
    performRequest(Api::ACCOUNT, "activateApplicationSubscription", request, response);
    return response;
}

CancelApplicationSubscriptionResponse
ExchangeApi::cancelApplicationSubscription(const CancelApplicationSubscriptionRequest& request) const {
    CancelApplicationSubscriptionResponse response;
    performRequest(Api::ACCOUNT, "cancelApplicationSubscription", request, response);
    return response;
}

UpdateApplicationSubscriptionResponse
ExchangeApi::updateApplicationSubscription(const UpdateApplicationSubscriptionRequest& request) const {
    UpdateApplicationSubscriptionResponse response;
    performRequest(Api::ACCOUNT, "updateApplicationSubscription", request, response);
    return response;
}

ListApplicationSubscriptionTokensResponse
ExchangeApi::listApplicationSubscriptionTokens(const ListApplicationSubscriptionTokensRequest& request) const {
    ListApplicationSubscriptionTokensResponse response;
    performRequest(Api::ACCOUNT, "listApplicationSubscriptionTokens", request, response);
    return response;
}

ListAccountSubscriptionTokensResponse
ExchangeApi::listAccountSubscriptionTokens() const {
    DummyRequest request;
    ListAccountSubscriptionTokensResponse response;
    performRequest(Api::ACCOUNT, "listAccountSubscriptionTokens", request, response);
    return response;
}

GetApplicationSubscriptionHistoryResponse
ExchangeApi::getApplicationSubscriptionHistory(const GetApplicationSubscriptionHistoryRequest& request) const {
    GetApplicationSubscriptionHistoryResponse response;
    performRequest(Api::ACCOUNT, "getApplicationSubscriptionHistory", request, response);
    return response;
}

AccountStatementReport
ExchangeApi::getAccountStatement(const GetAccountStatementRequest& request) const {
    AccountStatementReport response;
    performRequest(Api::ACCOUNT, "getAccountStatement", request, response);
    return response;
}

ListCurrencyRatesResponse
ExchangeApi::listCurrencyRates(const ListCurrencyRatesRequest& request) const {
    ListCurrencyRatesResponse response;
    performRequest(Api::ACCOUNT, "listCurrencyRates", request, response);
    return response;
}

AuthorisationResponse
ExchangeApi::getAuthorisationCode(const GetAuthorisationCodeRequest& request) const {
    AuthorisationResponse response;
    performRequest(Api::ACCOUNT, "getAuthorisationCode", request, response);
    return response;
}

VendorAccessTokenInfo
ExchangeApi::token(const TokenRequest& request) const {
    VendorAccessTokenInfo response;
    performRequest(Api::ACCOUNT, "token", request, response);
    return response;
}

VendorDetails
ExchangeApi::getVendorDetails(const GetVendorDetailsRequest& request) const {
    VendorDetails response;
    performRequest(Api::ACCOUNT, "getVendorDetails", request, response);
    return response;
}

RevokeAccessToWebAppResponse
ExchangeApi::revokeAccessToWebApp(const RevokeAccessToWebAppRequest& request) const {
    RevokeAccessToWebAppResponse response;
    performRequest(Api::ACCOUNT, "revokeAccessToWebApp", request, response);
    return response;
}

ListAuthorizedWebAppsResponse
ExchangeApi::listAuthorizedWebApps() const {
    DummyRequest request;
    ListAuthorizedWebAppsResponse response;
    performRequest(Api::ACCOUNT, "listAuthorizedWebApps", request, response);
    return response;
}

IsAccountSubscribedToWebAppResponse
ExchangeApi::isAccountSubscribedToWebApp(const IsAccountSubscribedToWebAppRequest& request) const {
    IsAccountSubscribedToWebAppResponse response;
    performRequest(Api::ACCOUNT, "listAuthorizedWebApps", request, response);
    return response;
}

GetAffiliateRelationResponse
ExchangeApi::getAffiliateRelation(const GetAffiliateRelationRequest& request) const {
    GetAffiliateRelationResponse response;
    performRequest(Api::ACCOUNT, "getAffiliateRelation", request, response);
    return response;
}

HeartbeatReport
ExchangeApi::heartbeat(const HeartbeatRequest& request) const {
    HeartbeatReport response;
    performRequest(Api::HEARTBEAT, "heartbeat", request, response);
    return response;
}

bool ExchangeApi::performRequest(const Api api,
        const std::string& method,
        const JsonRequest& jsonRequest,
        JsonResponse& jsonResponse) const {

    std::unique_ptr<CURL, void(*)(CURL*)> curl(curl_easy_init(), &curl_easy_cleanup);

    if (curl.get()) {

        SList headers;
        initRequest(api, method, curl.get(), headers);

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

bool ExchangeApi::initRequest(const Api api, const std::string method, CURL* curl, SList& headers) const {

    curl_easy_setopt(curl, CURLOPT_URL, buildUri(api, method).c_str());
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

std::string ExchangeApi::buildUri(const Api api, const std::string method) const {

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

    return HOST_UK + "/exchange/" + apiString + "/rest/v1.0/" + method + "/";
}

ExchangeApi::~ExchangeApi() {
    curl_global_cleanup();
}

}
