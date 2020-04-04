/**
 * Copyright 2018 Colin Doig.  Distributed under the MIT license.
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

size_t writeToStream(char* buffer, size_t size, size_t nitems, std::ostream* stream) {

    size_t realwrote = size * nitems;
    stream->write(buffer, static_cast<std::streamsize>(realwrote));
    if (!(*stream)) {
        realwrote = 0;
    }

    return realwrote;
}

ExchangeApi::ExchangeApi(const std::string& applicationKey, std::unique_ptr<ICurl>&& curl) : curl(std::move(curl)) {
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

    CurlHandle handle = curl->easyInit();

    if (handle.get()) {
        curl->easySetopt(handle, CURLOPT_URL, endPoint.c_str());
        curl->easySetopt(handle, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        SList chunk;
        std::string header = "Accept: application/json";
        chunk.append(header);
        header = "X-Application: " + xApplicationHeader;
        chunk.append(header);
        header = "Content-Type: application/x-www-form-urlencoded";
        chunk.append(header);
        curl->easySetopt(handle, CURLOPT_HTTPHEADER, chunk.get());

        if (loginWithCert) {
            curl->easySetopt(handle, CURLOPT_SSLCERT, certFilename.c_str());
            curl->easySetopt(handle, CURLOPT_SSLKEY, keyFilename.c_str());
        }

        std::string postFields = "username=" + username + "&password=" + password;
        curl->easySetopt(handle, CURLOPT_POSTFIELDS, postFields.c_str());

        curl->easySetopt(handle, CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl->easySetopt(handle, CURLOPT_WRITEDATA, &result);

        curl->easySetopt(handle, CURLOPT_NOSIGNAL, 1);
        char errorBuffer[CURL_ERROR_SIZE];
        curl->easySetopt(handle, CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;
        CURLcode curlResult = curl->easyPerform(handle);

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

const std::string& ExchangeApi::getSsoid() const {
    return ssoid;
}

bool ExchangeApi::retrieveMenu(const std::string& cacheFilename) {
    pendingMenuJson = Json::Value();
    bool refreshResult = false;

    CurlHandle handle = curl->easyInit();

    if (handle.get()) {
        std::string url = ExchangeApi::HOST_UK + "/exchange/betting/rest/v1/en/navigation/menu.json";

        curl->easySetopt(handle, CURLOPT_URL, url.c_str());
        curl->easySetopt(handle, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl->easySetopt(handle, CURLOPT_ACCEPT_ENCODING, "gzip");
        curl->easySetopt(handle, CURLOPT_NOSIGNAL, 1);
        curl->easySetopt(handle, CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl->easySetopt(handle, CURLOPT_WRITEDATA, &result);

        char errorBuffer[CURL_ERROR_SIZE];
        curl->easySetopt(handle, CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;

        SList chunk;
        std::string header = "X-Application: " + applicationKey;
        chunk.append(header);
        header = "X-Authentication: " + ssoid;
        chunk.append(header);
        curl->easySetopt(handle, CURLOPT_HTTPHEADER, chunk.get());

        CURLcode curlResult = curl->easyPerform(handle);

        if (curlResult == CURLE_OK) {

            if (cacheFilename != "") {
                std::fstream fs;
                fs.open(cacheFilename,  std::fstream::out);
                fs << result.str();
            }

            result >> pendingMenuJson;
            if (pendingMenuJson.isMember("children")) {
                refreshResult = true;
            } // else error, might not be logged in.

        } else {
            throw std::runtime_error(errorBuffer);
        }
    }
    return refreshResult;
}

bool ExchangeApi::parseMenu() {
    if (pendingMenuJson.isMember("children")) {
        menu.fromJson(pendingMenuJson);
        pendingMenuJson = Json::Value();
        return true;
    }
    return false;
}

bool ExchangeApi::refreshMenu(const std::string& cacheFilename) {
    return retrieveMenu(cacheFilename) && parseMenu();
}

menu::Menu& ExchangeApi::getMenu() {
    return menu;
}

sport::ListEventTypesResponse
ExchangeApi::listEventTypes(const sport::ListEventTypesRequest& request) const {
    sport::ListEventTypesResponse response;
    performRequest(Api::BETTING, "listEventTypes", request, response);
    return response;
}

sport::ListCompetitionsResponse
ExchangeApi::listCompetitions(const sport::ListCompetitionsRequest& request) const {
    sport::ListCompetitionsResponse response;
    performRequest(Api::BETTING, "listCompetitions", request, response);
    return response;
}

sport::ListTimeRangesResponse
ExchangeApi::listTimeRanges(const sport::ListTimeRangesRequest& request) const {
    sport::ListTimeRangesResponse response;
    performRequest(Api::BETTING, "listTimeRanges", request, response);
    return response;
}

sport::ListEventsResponse
ExchangeApi::listEvents(const sport::ListEventsRequest& request) const {
    sport::ListEventsResponse response;
    performRequest(Api::BETTING, "listEvents", request, response);
    return response;
}

sport::ListMarketTypesResponse
ExchangeApi::listMarketTypes(const sport::ListMarketTypesRequest& request) const {
    sport::ListMarketTypesResponse response;
    performRequest(Api::BETTING, "listMarketTypes", request, response);
    return response;
}

sport::ListCountriesResponse
ExchangeApi::listCountries(const sport::ListCountriesRequest& request) const {
    sport::ListCountriesResponse response;
    performRequest(Api::BETTING, "listCountries", request, response);
    return response;
}

sport::ListVenuesResponse
ExchangeApi::listVenues(const sport::ListVenuesRequest& request) const {
    sport::ListVenuesResponse response;
    performRequest(Api::BETTING, "listVenues", request, response);
    return response;
}

sport::ListMarketCatalogueResponse
ExchangeApi::listMarketCatalogue(const sport::ListMarketCatalogueRequest& request) const {
    sport::ListMarketCatalogueResponse response;
    performRequest(Api::BETTING, "listMarketCatalogue", request, response);
    return response;
}

sport::ListMarketBookResponse
ExchangeApi::listMarketBook(const sport::ListMarketBookRequest& request) const {
    sport::ListMarketBookResponse response;
    performRequest(Api::BETTING, "listMarketBook", request, response);
    return response;
}

sport::ListRunnerBookResponse
ExchangeApi::listRunnerBook(const sport::ListRunnerBookRequest& request) const {
    sport::ListRunnerBookResponse response;
    performRequest(Api::BETTING, "listRunnerBook", request, response);
    return response;
}

sport::CurrentOrderSummaryReport
ExchangeApi::listCurrentOrders(const sport::ListCurrentOrdersRequest& request) const {
    sport::CurrentOrderSummaryReport response;
    performRequest(Api::BETTING, "listCurrentOrders", request, response);
    return response;
}

sport::ClearedOrderSummaryReport
ExchangeApi::listClearedOrders(const sport::ListClearedOrdersRequest& request) const {
    sport::ClearedOrderSummaryReport response;
    performRequest(Api::BETTING, "listClearedOrders", request, response);
    return response;
}

sport::PlaceExecutionReport
ExchangeApi::placeOrders(const sport::PlaceOrdersRequest& request) const {
    sport::PlaceExecutionReport response;
    performRequest(Api::BETTING, "placeOrders", request, response);
    return response;
}

sport::CancelExecutionReport
ExchangeApi::cancelOrders(const sport::CancelOrdersRequest& request) const {
    sport::CancelExecutionReport response;
    performRequest(Api::BETTING, "cancelOrders", request, response);
    return response;
}

sport::ReplaceExecutionReport
ExchangeApi::replaceOrders(const sport::ReplaceOrdersRequest& request) const {
    sport::ReplaceExecutionReport response;
    performRequest(Api::BETTING, "replaceOrders", request, response);
    return response;
}

sport::UpdateExecutionReport
ExchangeApi::updateOrders(const sport::UpdateOrdersRequest& request) const {
    sport::UpdateExecutionReport response;
    performRequest(Api::BETTING, "updateOrders", request, response);
    return response;
}

sport::ListMarketProfitAndLossResponse
ExchangeApi::listMarketProfitAndLoss(const sport::ListMarketProfitAndLossRequest& request) const {
    sport::ListMarketProfitAndLossResponse response;
    performRequest(Api::BETTING, "listMarketProfitAndLoss", request, response);
    return response;
}

sport::SetDefaultExposureLimitForMarketGroupsResponse
ExchangeApi::setDefaultExposureLimitForMarketGroups(const sport::SetDefaultExposureLimitForMarketGroupsRequest& request) const {
    sport::SetDefaultExposureLimitForMarketGroupsResponse response;
    performRequest(Api::BETTING, "setDefaultExposureLimitForMarketGroups", request, response);
    return response;
}

sport::SetExposureLimitForMarketGroupResponse
ExchangeApi::setExposureLimitForMarketGroup(const sport::SetExposureLimitForMarketGroupRequest& request) const {
    sport::SetExposureLimitForMarketGroupResponse response;
    performRequest(Api::BETTING, "setExposureLimitForMarketGroup", request, response);
    return response;
}

sport::RemoveDefaultExposureLimitForMarketGroupsResponse
ExchangeApi::removeDefaultExposureLimitForMarketGroups(const sport::RemoveDefaultExposureLimitForMarketGroupsRequest& request) const {
    sport::RemoveDefaultExposureLimitForMarketGroupsResponse response;
    performRequest(Api::BETTING, "removeDefaultExposureLimitForMarketGroups", request, response);
    return response;
}

sport::RemoveExposureLimitForMarketGroupResponse
ExchangeApi::removeExposureLimitForMarketGroup(const sport::RemoveExposureLimitForMarketGroupRequest& request) const {
    sport::RemoveExposureLimitForMarketGroupResponse response;
    performRequest(Api::BETTING, "removeExposureLimitForMarketGroup", request, response);
    return response;
}

sport::ListExposureLimitsForMarketGroupsResponse
ExchangeApi::listExposureLimitsForMarketGroups(const sport::ListExposureLimitsForMarketGroupsRequest& request) const {
    sport::ListExposureLimitsForMarketGroupsResponse response;
    performRequest(Api::BETTING, "listExposureLimitsForMarketGroups", request, response);
    return response;
}

sport::UnblockMarketGroupResponse
ExchangeApi::unblockMarketGroup(const sport::UnblockMarketGroupRequest& request) const {
    sport::UnblockMarketGroupResponse response;
    performRequest(Api::BETTING, "unblockMarketGroup", request, response);
    return response;
}

sport::GetExposureReuseEnabledEventsResponse
ExchangeApi::getExposureReuseEnabledEvents() const {
    DummyRequest request;
    sport::GetExposureReuseEnabledEventsResponse response;
    performRequest(Api::BETTING, "getExposureReuseEnabledEvents", request, response);
    return response;
}

sport::AddExposureReuseEnabledEventsResponse
ExchangeApi::addExposureReuseEnabledEvents(const sport::AddExposureReuseEnabledEventsRequest& request) const {
    sport::AddExposureReuseEnabledEventsResponse response;
    performRequest(Api::BETTING, "addExposureReuseEnabledEvents", request, response);
    return response;
}

sport::RemoveExposureReuseEnabledEventsResponse
ExchangeApi::removeExposureReuseEnabledEvents(const sport::RemoveExposureReuseEnabledEventsRequest& request) const {
    sport::RemoveExposureReuseEnabledEventsResponse response;
    performRequest(Api::BETTING, "removeExposureReuseEnabledEvents", request, response);
    return response;
}

account::DeveloperApp
ExchangeApi::createDeveloperAppKeys(const account::CreateDeveloperAppKeysRequest& request) const {
    account::DeveloperApp response;
    performRequest(Api::ACCOUNT, "createDeveloperAppKeys", request, response);
    return response;
}

account::GetDeveloperAppKeysResponse
ExchangeApi::getDeveloperAppKeys() const {
    DummyRequest request;
    account::GetDeveloperAppKeysResponse response;
    performRequest(Api::ACCOUNT, "getDeveloperAppKeys", request, response);
    return response;
}

account::AccountFundsResponse
ExchangeApi::getAccountFunds(const account::GetAccountFundsRequest& request) const {
    account::AccountFundsResponse response;
    performRequest(Api::ACCOUNT, "getAccountFunds", request, response);
    return response;
}

account::TransferResponse
ExchangeApi::transferFunds(const account::TransferFundsRequest& request) const {
    account::TransferResponse response;
    performRequest(Api::ACCOUNT, "transferFunds", request, response);
    return response;
}

account::AccountDetailsResponse
ExchangeApi::getAccountDetails() const {
    DummyRequest request;
    account::AccountDetailsResponse response;
    performRequest(Api::ACCOUNT, "getAccountDetails", request, response);
    return response;
}

account::GetVendorClientIdResponse
ExchangeApi::getVendorClientId() const {
    DummyRequest request;
    account::GetVendorClientIdResponse response;
    performRequest(Api::ACCOUNT, "getVendorClientId", request, response);
    return response;
}

account::GetApplicationSubscriptionTokenResponse
ExchangeApi::getApplicationSubscriptionToken(const account::GetApplicationSubscriptionTokenRequest& request) const {
    account::GetApplicationSubscriptionTokenResponse response;
    performRequest(Api::ACCOUNT, "getApplicationSubscriptionToken", request, response);
    return response;
}

account::ActivateApplicationSubscriptionResponse
ExchangeApi::activateApplicationSubscription(const account::ActivateApplicationSubscriptionRequest& request) const {
    account::ActivateApplicationSubscriptionResponse response;
    performRequest(Api::ACCOUNT, "activateApplicationSubscription", request, response);
    return response;
}

account::CancelApplicationSubscriptionResponse
ExchangeApi::cancelApplicationSubscription(const account::CancelApplicationSubscriptionRequest& request) const {
    account::CancelApplicationSubscriptionResponse response;
    performRequest(Api::ACCOUNT, "cancelApplicationSubscription", request, response);
    return response;
}

account::UpdateApplicationSubscriptionResponse
ExchangeApi::updateApplicationSubscription(const account::UpdateApplicationSubscriptionRequest& request) const {
    account::UpdateApplicationSubscriptionResponse response;
    performRequest(Api::ACCOUNT, "updateApplicationSubscription", request, response);
    return response;
}

account::ListApplicationSubscriptionTokensResponse
ExchangeApi::listApplicationSubscriptionTokens(const account::ListApplicationSubscriptionTokensRequest& request) const {
    account::ListApplicationSubscriptionTokensResponse response;
    performRequest(Api::ACCOUNT, "listApplicationSubscriptionTokens", request, response);
    return response;
}

account::ListAccountSubscriptionTokensResponse
ExchangeApi::listAccountSubscriptionTokens() const {
    DummyRequest request;
    account::ListAccountSubscriptionTokensResponse response;
    performRequest(Api::ACCOUNT, "listAccountSubscriptionTokens", request, response);
    return response;
}

account::GetApplicationSubscriptionHistoryResponse
ExchangeApi::getApplicationSubscriptionHistory(const account::GetApplicationSubscriptionHistoryRequest& request) const {
    account::GetApplicationSubscriptionHistoryResponse response;
    performRequest(Api::ACCOUNT, "getApplicationSubscriptionHistory", request, response);
    return response;
}

account::AccountStatementReport
ExchangeApi::getAccountStatement(const account::GetAccountStatementRequest& request) const {
    account::AccountStatementReport response;
    performRequest(Api::ACCOUNT, "getAccountStatement", request, response);
    return response;
}

account::ListCurrencyRatesResponse
ExchangeApi::listCurrencyRates(const account::ListCurrencyRatesRequest& request) const {
    account::ListCurrencyRatesResponse response;
    performRequest(Api::ACCOUNT, "listCurrencyRates", request, response);
    return response;
}

account::AuthorisationResponse
ExchangeApi::getAuthorisationCode(const account::GetAuthorisationCodeRequest& request) const {
    account::AuthorisationResponse response;
    performRequest(Api::ACCOUNT, "getAuthorisationCode", request, response);
    return response;
}

account::VendorAccessTokenInfo
ExchangeApi::token(const account::TokenRequest& request) const {
    account::VendorAccessTokenInfo response;
    performRequest(Api::ACCOUNT, "token", request, response);
    return response;
}

account::VendorDetails
ExchangeApi::getVendorDetails(const account::GetVendorDetailsRequest& request) const {
    account::VendorDetails response;
    performRequest(Api::ACCOUNT, "getVendorDetails", request, response);
    return response;
}

account::RevokeAccessToWebAppResponse
ExchangeApi::revokeAccessToWebApp(const account::RevokeAccessToWebAppRequest& request) const {
    account::RevokeAccessToWebAppResponse response;
    performRequest(Api::ACCOUNT, "revokeAccessToWebApp", request, response);
    return response;
}

account::ListAuthorizedWebAppsResponse
ExchangeApi::listAuthorizedWebApps() const {
    DummyRequest request;
    account::ListAuthorizedWebAppsResponse response;
    performRequest(Api::ACCOUNT, "listAuthorizedWebApps", request, response);
    return response;
}

account::IsAccountSubscribedToWebAppResponse
ExchangeApi::isAccountSubscribedToWebApp(const account::IsAccountSubscribedToWebAppRequest& request) const {
    account::IsAccountSubscribedToWebAppResponse response;
    performRequest(Api::ACCOUNT, "listAuthorizedWebApps", request, response);
    return response;
}

account::GetAffiliateRelationResponse
ExchangeApi::getAffiliateRelation(const account::GetAffiliateRelationRequest& request) const {
    account::GetAffiliateRelationResponse response;
    performRequest(Api::ACCOUNT, "getAffiliateRelation", request, response);
    return response;
}

heartbeat::HeartbeatReport
ExchangeApi::heartbeat(const heartbeat::HeartbeatRequest& request) const {
    heartbeat::HeartbeatReport response;
    performRequest(Api::HEARTBEAT, "heartbeat", request, response);
    return response;
}

bool ExchangeApi::performRequest(const Api api,
        const std::string& method,
        const JsonRequest& jsonRequest,
        JsonResponse& jsonResponse) const {
    CurlHandle handle = curl->easyInit();

    if (handle.get()) {

        SList headers;
        initRequest(api, method, handle, headers);

        std::string request = jsonRequest.toString();

        if (request != "") {
            curl->easySetopt(handle, CURLOPT_POSTFIELDS, request.c_str());
        }

        curl->easySetopt(handle, CURLOPT_WRITEFUNCTION, writeToStream);
        std::stringstream result;
        curl->easySetopt(handle, CURLOPT_WRITEDATA, &result);

        char errorBuffer[CURL_ERROR_SIZE];
        curl->easySetopt(handle, CURLOPT_ERRORBUFFER, errorBuffer);
        errorBuffer[0] = 0;

        CURLcode curlResult = curl->easyPerform(handle);
        if (curlResult == CURLE_OK) {
            result >> jsonResponse;
        } else {
            throw std::runtime_error(errorBuffer);
        }

        return jsonResponse.isSuccess();
    }

    return false;
}

bool ExchangeApi::initRequest(const Api api, const std::string method, const CurlHandle& handle, SList& headers) const {
    curl->easySetopt(handle, CURLOPT_URL, buildUri(api, method).c_str());
    curl->easySetopt(handle, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl->easySetopt(handle, CURLOPT_ACCEPT_ENCODING, "gzip");
    curl->easySetopt(handle, CURLOPT_NOSIGNAL, 1);

    std::string header = "X-Application: " + applicationKey;
    headers.append(header);
    header = "X-Authentication: " + ssoid;
    headers.append(header);
    headers.append("content-type: application/json");

    curl->easySetopt(handle, CURLOPT_HTTPHEADER, headers.get());

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

}
