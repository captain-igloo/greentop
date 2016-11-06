/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXCHANGEAPI_H
#define EXCHANGEAPI_H

#include <curl/curl.h>
#include <set>
#include <string>
#include <vector>

#include "greentop/account/AccountDetailsResponse.h"
#include "greentop/account/AccountFundsResponse.h"
#include "greentop/account/AccountStatementReport.h"
#include "greentop/account/ActivateApplicationSubscriptionRequest.h"
#include "greentop/account/ActivateApplicationSubscriptionResponse.h"
#include "greentop/account/CancelApplicationSubscriptionRequest.h"
#include "greentop/account/CancelApplicationSubscriptionResponse.h"
#include "greentop/account/CreateDeveloperAppKeysRequest.h"
#include "greentop/account/DeveloperApp.h"
#include "greentop/account/GetAccountFundsRequest.h"
#include "greentop/account/GetAccountStatementRequest.h"
#include "greentop/account/GetApplicationSubscriptionHistoryRequest.h"
#include "greentop/account/GetApplicationSubscriptionHistoryResponse.h"
#include "greentop/account/GetApplicationSubscriptionTokenRequest.h"
#include "greentop/account/GetApplicationSubscriptionTokenResponse.h"
#include "greentop/account/GetDeveloperAppKeysResponse.h"
#include "greentop/account/GetVendorClientIdResponse.h"
#include "greentop/account/ListAccountSubscriptionTokensResponse.h"
#include "greentop/account/ListApplicationSubscriptionTokensRequest.h"
#include "greentop/account/ListApplicationSubscriptionTokensResponse.h"
#include "greentop/account/ListCurrencyRatesRequest.h"
#include "greentop/account/ListCurrencyRatesResponse.h"
#include "greentop/account/TransferFundsRequest.h"
#include "greentop/account/TransferResponse.h"
#include "greentop/account/UpdateApplicationSubscriptionRequest.h"
#include "greentop/account/UpdateApplicationSubscriptionResponse.h"

#include "greentop/heartbeat/HeartbeatRequest.h"
#include "greentop/heartbeat/HeartbeatReport.h"

#include "greentop/sport/CancelExecutionReport.h"
#include "greentop/sport/CancelOrdersRequest.h"
#include "greentop/sport/ClearedOrderSummaryReport.h"
#include "greentop/sport/CurrentOrderSummaryReport.h"
#include "greentop/sport/ListClearedOrdersRequest.h"
#include "greentop/sport/ListCompetitionsRequest.h"
#include "greentop/sport/ListCompetitionsResponse.h"
#include "greentop/sport/ListCountriesRequest.h"
#include "greentop/sport/ListCountriesResponse.h"
#include "greentop/sport/ListCurrentOrdersRequest.h"
#include "greentop/sport/ListEventsRequest.h"
#include "greentop/sport/ListEventsResponse.h"
#include "greentop/sport/ListEventTypesRequest.h"
#include "greentop/sport/ListEventTypesResponse.h"
#include "greentop/sport/ListMarketBookRequest.h"
#include "greentop/sport/ListMarketBookResponse.h"
#include "greentop/sport/ListMarketCatalogueRequest.h"
#include "greentop/sport/ListMarketCatalogueResponse.h"
#include "greentop/sport/ListMarketProfitAndLossRequest.h"
#include "greentop/sport/ListMarketProfitAndLossResponse.h"
#include "greentop/sport/ListMarketTypesRequest.h"
#include "greentop/sport/ListMarketTypesResponse.h"
#include "greentop/sport/ListTimeRangesRequest.h"
#include "greentop/sport/ListTimeRangesResponse.h"
#include "greentop/sport/ListVenuesRequest.h"
#include "greentop/sport/ListVenuesResponse.h"
#include "greentop/sport/PlaceExecutionReport.h"
#include "greentop/sport/PlaceOrdersRequest.h"
#include "greentop/sport/ReplaceExecutionReport.h"
#include "greentop/sport/ReplaceOrdersRequest.h"
#include "greentop/sport/UpdateExecutionReport.h"
#include "greentop/sport/UpdateOrdersRequest.h"

#include "greentop/JsonRequest.h"
#include "greentop/JsonResponse.h"
#include "greentop/curl/SList.h"
#include "greentop/Exchange.h"
#include "greentop/menu/Menu.h"

namespace greentop {

class ExchangeApi {

    public:

        static const std::string LOGIN_END_POINT_GLOBAL;
        static const std::string LOGIN_END_POINT_ITALY;
        static const std::string LOGIN_END_POINT_SPAIN;
        static const std::string LOGIN_END_POINT_ROMANIA;
        static const std::string LOGIN_END_POINT_GLOBAL_CERT;

        enum class Api {ACCOUNT, BETTING, HEARTBEAT};

        ExchangeApi(const std::string& applicationKey = "");

        void setLoginEndPoint(const std::string& loginEndPoint);

        bool login(const std::string& username, const std::string& password,
            const std::string& certFilename = "", const std::string& keyFilename = "");

        void logout();

        void setApplicationKey(const std::string& appKey);

        void setSsoid(const std::string& ssoid);

        void refreshMenu(const std::string& cacheFilename = "");

        menu::Menu& getMenu();

        /**
         * Returns a list of Event Types (i.e. Sports) associated with the markets selected by the
         * MarketFilter.
         */
        ListEventTypesResponse listEventTypes(const Exchange exchange,
            const ListEventTypesRequest& request) const;

        /**
         * Returns a list of Competitions (i.e., World Cup 2013) associated with the markets
         * selected by the MarketFilter. Currently only Football markets have an associated
         * competition.
         */
        ListCompetitionsResponse listCompetitions(const Exchange exchange,
            const ListCompetitionsRequest& request) const;

        /**
         * Returns a list of time ranges in the granularity specified in the request (i.e. 3PM to
         * 4PM, Aug 14th to Aug 15th) associated with the markets selected by the MarketFilter.
         */
        ListTimeRangesResponse listTimeRanges(const Exchange exchange,
            const ListTimeRangesRequest& request) const;

        /**
         * Returns a list of Events (i.e, Reading vs. Man United) associated with the markets
         * selected by the MarketFilter.
         */
        ListEventsResponse listEvents(const Exchange exchange,
            const ListEventsRequest& request) const;

        /**
         * Returns a list of market types (i.e. MATCH_ODDS, NEXT_GOAL) associated with the markets
         * selected by the MarketFilter. The market types are always the same, regardless of
         * locale.
         */
        ListMarketTypesResponse listMarketTypes(const Exchange exchange,
            const ListMarketTypesRequest& request) const;

        /**
         * Returns a list of Countries associated with the markets selected by the MarketFilter.
         */
        ListCountriesResponse listCountries(const Exchange exchange,
            const ListCountriesRequest& request) const;

        /**
         * Returns a list of Venues (i.e. Cheltenham, Ascot) associated with the markets selected
         * by the MarketFilter. Currently, only Horse Racing markets are associated with a Venue.
         */
        ListVenuesResponse listVenues(const Exchange exchange,
            const ListVenuesRequest& request) const;

        /**
         * Returns a list of information about markets that does not change (or changes very
         * rarely). You use listMarketCatalogue to retrieve the name of the market, the names of
         * selections and other information about markets.
         */
        ListMarketCatalogueResponse listMarketCatalogue(const Exchange exchange,
            const ListMarketCatalogueRequest& request) const;

        /**
         * Returns a list of dynamic data about markets. Dynamic data includes prices, the status
         * of the market, the status of selections, the traded volume, and the status of any orders
         * you have placed in the market.
         */
        ListMarketBookResponse listMarketBook(const Exchange exchange,
            const ListMarketBookRequest& request) const;

        /**
         * Returns a list of your current orders. Optionally you can filter and sort your current
         * orders using the various parameters, setting none of the parameters will return all of
         * your current orders, up to a maximum of 1000 bets, ordered BY_BET and sorted
         * EARLIEST_TO_LATEST. To retrieve more than 1000 orders, you need to make use of the
         * fromRecord and recordCount parameters.
         */
        CurrentOrderSummaryReport listCurrentOrders(const Exchange exchange,
            const ListCurrentOrdersRequest& request) const;

        /**
         * Returns a List of bets based on the bet status, ordered by settled date.
         */
        ClearedOrderSummaryReport listClearedOrders(const Exchange exchange,
            const ListClearedOrdersRequest& request) const;

        /**
         * Place new orders into market. LIMIT orders below the minimum bet size are allowed if
         * there is an unmatched bet at the same price in the market. This operation is atomic in
         * that all orders will be placed or none will be placed.
         */
        PlaceExecutionReport placeOrders(const Exchange exchange,
            const PlaceOrdersRequest& request) const;

        /**
         * Cancel all bets OR cancel all bets on a market OR fully or partially cancel particular
         * orders on a market. Only LIMIT orders an be cancelled or partially cancelled once
         * placed.
         */
        CancelExecutionReport cancelOrders(const Exchange exchange,
            const CancelOrdersRequest& request) const;

        /**
         * This operation is logically a bulk cancel followed by a bulk place. The cancel is
         * completed first then the new orders are placed. The new orders will be placed atomically
         * in that they will all be placed or none will be placed.
         * In the case where the new orders cannot be placed the cancellations will not be rolled
         * back.
         * See ReplaceInstruction.
         */
        ReplaceExecutionReport replaceOrders(const Exchange exchange,
            const ReplaceOrdersRequest& request) const;

        /**
         * Update non-exposure changing fields.
         */
        UpdateExecutionReport updateOrders(const Exchange exchange,
            const UpdateOrdersRequest& request) const;

        /**
         * Retrieve profit and loss for a given list of markets. The values are calculated using
         * matched bets and optionally settled bets. Only odds markets are implemented, markets of
         * other types are silently ignored.
         */
        ListMarketProfitAndLossResponse listMarketProfitAndLoss(const Exchange exchange,
            const ListMarketProfitAndLossRequest& request) const;

        /**
         * Create 2 application keys for given user; one active and the other delayed.
         */
        DeveloperApp createDeveloperAppKeys(const Exchange exchange,
            const CreateDeveloperAppKeysRequest& request) const;

        /**
         * Get all application keys owned by the given developer/vendor.
         */
        GetDeveloperAppKeysResponse getDeveloperAppKeys(const Exchange exchange) const;

        /**
         * Get available to bet amount.
         */
        AccountFundsResponse getAccountFunds(const Exchange exchange,
            const GetAccountFundsRequest& request) const;

        /**
         * Transfer funds between wallets.
         */
        TransferResponse transferFunds(const Exchange exchange,
            const TransferFundsRequest& request) const;

        /**
         * Get Account details.
         */
        AccountDetailsResponse getAccountDetails(const Exchange exchange) const;

        /**
         * Get vendor client id for customer account.
         */
        GetVendorClientIdResponse getVendorClientId(const Exchange exchange) const;

        /**
         * Returns the newly generate subscription token.
         */
        GetApplicationSubscriptionTokenResponse getApplicationSubscriptionToken(const Exchange exchange,
            const GetApplicationSubscriptionTokenRequest& request) const;

        /**
         * Activate the subscription token for the customer.
         */
        ActivateApplicationSubscriptionResponse activateApplicationSubscription(const Exchange exchange,
            const ActivateApplicationSubscriptionRequest& request) const;

        /**
         * Cancel application subscription.
         */
        CancelApplicationSubscriptionResponse cancelApplicationSubscription(const Exchange exchange,
            const CancelApplicationSubscriptionRequest& request) const;

        /**
         * Update an application subscription with a new expiry date.
         */
        UpdateApplicationSubscriptionResponse updateApplicationSubscription(const Exchange exchange,
            const UpdateApplicationSubscriptionRequest& request) const;

        /**
         * List of subscription tokens for an application.
         */
        ListApplicationSubscriptionTokensResponse listApplicationSubscriptionTokens(const Exchange exchange,
            const ListApplicationSubscriptionTokensRequest& request) const;

        /**
         * List of subscription tokens associated with the account.
         */
        ListAccountSubscriptionTokensResponse listAccountSubscriptionTokens(const Exchange exchange) const;

        /**
         * Identify all subscriptions, regardless of status, for a single client for a single
         * application key. The operation may be called by either the application key owner or a client.
         */
        GetApplicationSubscriptionHistoryResponse getApplicationSubscriptionHistory(const Exchange exchange,
            const GetApplicationSubscriptionHistoryRequest& request) const;

        /**
         * Get account statement.
         */
        AccountStatementReport getAccountStatement(const Exchange exchange,
            const GetAccountStatementRequest& request) const;

        /**
         * Returns a list of currency rates based on given currency.
         */
        ListCurrencyRatesResponse listCurrencyRates(const Exchange exchange,
            const ListCurrencyRatesRequest& listCurrencyRatesRequest) const;

        /**
         * This heartbeat operation is provided to help customers have their positions managed
         * automatically in the event of their API clients losing connectivity with the Betfair
         * API.
         *
         * If a heartbeat request is not received within a prescribed time period, then Betfair
         * will attempt to cancel all 'LIMIT' type bets for the given customer on the given
         * exchange.
         *
         * There is no guarantee that this service will result in all bets being cancelled as
         * there are a number of circumstances where bets are unable to be cancelled. Manual
         * intervention is strongly advised in the event of a loss of connectivity to ensure that
         * positions are correctly managed.
         *
         * If this service becomes unavailable for any reason, then your heartbeat will be
         * unregistered automatically to avoid bets being inadvertently cancelled upon resumption
         * of service. You should manage your position manually until the service is resumed.
         *
         * Heartbeat data may also be lost in the unlikely event of  nodes failing within the
         * cluster, which may result in your position not being managed until a subsequent
         * heartbeat request is received.
         */
        HeartbeatReport heartbeat(const Exchange exchange,
            const HeartbeatRequest& request) const;

        ~ExchangeApi();

    private:
        static const std::string HOST_UK;
        static const std::string HOST_AUS;

        std::string loginEndPoint;
        std::string loginEndPointCert;
        std::string ssoid;
        std::string applicationKey;
        menu::Menu menu;

        bool initRequest(const Exchange exchange, const Api api,
            const std::string method, CURL* curl, SList& headers) const;

        bool performRequest(const Exchange exchange,
            const Api api,
            const std::string& method, const JsonRequest& jsonRequest,
            JsonResponse& jsonResponse) const;

        std::string buildUri(const Exchange exchange, const Api api, const std::string method) const;
};

}

#endif // EXCHANGEAPI_H
