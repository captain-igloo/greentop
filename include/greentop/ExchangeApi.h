/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXCHANGEAPI_H
#define EXCHANGEAPI_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>

#include "greentop/JsonRequest.h"
#include "greentop/JsonResponse.h"

#include "greentop/account/AccountDetailsResponse.h"
#include "greentop/account/AccountFundsResponse.h"
#include "greentop/account/AccountStatementReport.h"
#include "greentop/account/ActivateApplicationSubscriptionRequest.h"
#include "greentop/account/ActivateApplicationSubscriptionResponse.h"
#include "greentop/account/CreateDeveloperAppKeysRequest.h"
#include "greentop/account/DeveloperApp.h"
#include "greentop/account/GetAccountStatementRequest.h"
#include "greentop/account/GetDeveloperAppKeysResponse.h"

#include "greentop/betting/CancelExecutionReport.h"
#include "greentop/betting/CancelOrdersRequest.h"
#include "greentop/betting/CancelInstruction.h"
#include "greentop/betting/ClearedOrderSummaryReport.h"
#include "greentop/betting/Competition.h"
#include "greentop/betting/CurrentOrderSummaryReport.h"
#include "greentop/betting/EventResult.h"
#include "greentop/betting/EventTypeResult.h"
#include "greentop/betting/GetAccountFundsRequest.h"
#include "greentop/betting/ListClearedOrdersRequest.h"
#include "greentop/betting/ListCompetitionsRequest.h"
#include "greentop/betting/ListCompetitionsResponse.h"
#include "greentop/betting/ListCountriesRequest.h"
#include "greentop/betting/ListCountriesResponse.h"
#include "greentop/betting/ListCurrencyRatesRequest.h"
#include "greentop/betting/ListCurrencyRatesResponse.h"
#include "greentop/betting/ListCurrentOrdersRequest.h"
#include "greentop/betting/ListEventsRequest.h"
#include "greentop/betting/ListEventsResponse.h"
#include "greentop/betting/ListEventTypesRequest.h"
#include "greentop/betting/ListEventTypesResponse.h"
#include "greentop/betting/ListMarketBookResponse.h"
#include "greentop/betting/ListMarketCatalogueRequest.h"
#include "greentop/betting/ListMarketCatalogueResponse.h"
#include "greentop/betting/ListMarketBookRequest.h"
#include "greentop/betting/ListMarketProfitAndLossRequest.h"
#include "greentop/betting/ListMarketProfitAndLossResponse.h"
#include "greentop/betting/MarketBook.h"
#include "greentop/betting/MarketCatalogue.h"
#include "greentop/betting/MarketProfitAndLoss.h"
#include "greentop/betting/PlaceExecutionReport.h"
#include "greentop/betting/PlaceInstruction.h"
#include "greentop/betting/PlaceOrdersRequest.h"
#include "greentop/betting/ReplaceExecutionReport.h"
#include "greentop/betting/ReplaceInstruction.h"
#include "greentop/betting/ReplaceOrdersRequest.h"
#include "greentop/betting/TransferFundsRequest.h"
#include "greentop/betting/TransferResponse.h"

#include "greentop/heartbeat/HeartbeatReport.h"
#include "greentop/heartbeat/HeartbeatRequest.h"

namespace greentop {

class ExchangeApi {

    public:

        enum class Api {ACCOUNT, BETTING, HEARTBEAT};
        enum class Exchange { UK = 1, AUS = 2};

        ExchangeApi(const std::string& applicationKey = "");

        bool login(std::string username, std::string password);

        void logout();

        ListCompetitionsResponse
        listCompetitions(const Exchange exchange,
            const ListCompetitionsRequest& listCompetitionsRequest) const;

        ListCountriesResponse
        listCountries(const Exchange exchange,
            const ListCountriesRequest& listCountriesRequest) const;

        CurrentOrderSummaryReport
        listCurrentOrders(const Exchange exchange,
            const ListCurrentOrdersRequest& listCurrentOrdersRequest) const;

        ClearedOrderSummaryReport
        listClearedOrders(const Exchange exchange,
            const ListClearedOrdersRequest& listClearedOrdersRequest) const;

        ListEventTypesResponse
        listEventTypes(const Exchange exchange,
            const ListEventTypesRequest& listEventTypesRequest) const;

        ListEventsResponse
        listEvents(const Exchange exchange,
            const ListEventsRequest& listEventsRequest) const;

        ListMarketCatalogueResponse
        listMarketCatalogue(const Exchange exchange,
            const ListMarketCatalogueRequest& listMarketCatalogueRequest) const;

        ListMarketBookResponse
        listMarketBook(const Exchange exchange,
            const ListMarketBookRequest& listMarketBookRequest) const;

        PlaceExecutionReport
        placeOrders(const Exchange exchange,
            const PlaceOrdersRequest& placeOrdersRequest) const;

        CancelExecutionReport
        cancelOrders(const Exchange exchange,
            const CancelOrdersRequest& cancelOrdersRequest) const;

        ListMarketProfitAndLossResponse
        listMarketProfitAndLoss(const Exchange exchange,
            const ListMarketProfitAndLossRequest& listMarketProfitAndLossRequest) const;

        ReplaceExecutionReport
        replaceOrders(const Exchange exchange,
            const ReplaceOrdersRequest& replaceOrdersRequest) const;

        AccountFundsResponse
        getAccountFunds(const Exchange exchange,
            const GetAccountFundsRequest& getAccountFundsRequest) const;

        AccountDetailsResponse
        getAccountDetails(const Exchange exchange) const;

        TransferResponse
        transferFunds(const Exchange exchange,
            const TransferFundsRequest& transferFundsRequest) const;

        DeveloperApp
        createDeveloperAppKeys(const Exchange exchange,
            const CreateDeveloperAppKeysRequest& createDeveloperAppKeysRequest) const;

        GetDeveloperAppKeysResponse
        getDeveloperAppKeys(const Exchange exchange) const;

        AccountStatementReport
        getAccountStatement(const Exchange exchange,
            const GetAccountStatementRequest& getAccountStatementRequest) const;

        ListCurrencyRatesResponse
        listCurrencyRates(const Exchange exchange,
            const ListCurrencyRatesRequest& listCurrencyRatesRequest) const;

        HeartbeatReport
        heartbeat(const Exchange exchange,
            const HeartbeatRequest& heartbeatRequest) const;

        ActivateApplicationSubscriptionResponse
        activateApplicationSubscription(const Exchange exchange,
            const ActivateApplicationSubscriptionRequest& activateApplicationSubscriptionRequest) const;

    private:

        static const std::string LOGIN_END_POINT;
        static const std::string HOST_UK;
        static const std::string HOST_AUS;

        std::string ssoid;
        std::string applicationKey;

        bool initRequest(const Exchange exchange,
            const Api api,
            const std::string method, curlpp::Easy &request) const;

        bool performRequest(const Exchange exchange,
            const Api api,
            const std::string& method, const JsonRequest& jsonRequest,
            JsonResponse& jsonResponse) const;

        std::string buildUri(const Exchange exchange, const Api api, const std::string method) const;
};

}

#endif // EXCHANGEAPI_H
