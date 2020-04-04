/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTRUNNERBOOKREQUEST_H
#define SPORT_LISTRUNNERBOOKREQUEST_H

#include <ctime>
#include <json/json.h>
#include <set>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/PriceProjection.h"
#include "greentop/sport/enum/MatchProjection.h"
#include "greentop/sport/enum/OrderProjection.h"

namespace greentop {
namespace sport {

class ListRunnerBookRequest : public JsonRequest {
    public:
        ListRunnerBookRequest();

        ListRunnerBookRequest(const std::string& marketId,
            const Optional<int64_t>& selectionId,
            const Optional<double>& handicap = Optional<double>(),
            const PriceProjection& priceProjection = PriceProjection(),
            const OrderProjection& orderProjection = OrderProjection(),
            const MatchProjection& matchProjection = MatchProjection(),
            const Optional<bool>& includeOverallPosition = Optional<bool>(),
            const Optional<bool>& partitionMatchedByStrategyRef = Optional<bool>(),
            const std::set<std::string>& customerStrategyRefs = std::set<std::string>(),
            const std::string& currencyCode = std::string(),
            const std::string& locale = std::string(),
            const std::tm& matchedSince = std::tm(),
            const std::set<std::string>& betIds = std::set<std::string>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const Optional<int64_t>& getSelectionId() const;
        void setSelectionId(const Optional<int64_t>& selectionId);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);

        const PriceProjection& getPriceProjection() const;
        void setPriceProjection(const PriceProjection& priceProjection);

        const OrderProjection& getOrderProjection() const;
        void setOrderProjection(const OrderProjection& orderProjection);

        const MatchProjection& getMatchProjection() const;
        void setMatchProjection(const MatchProjection& matchProjection);

        const Optional<bool>& getIncludeOverallPosition() const;
        void setIncludeOverallPosition(const Optional<bool>& includeOverallPosition);

        const Optional<bool>& getPartitionMatchedByStrategyRef() const;
        void setPartitionMatchedByStrategyRef(const Optional<bool>& partitionMatchedByStrategyRef);

        const std::set<std::string>& getCustomerStrategyRefs() const;
        void setCustomerStrategyRefs(const std::set<std::string>& customerStrategyRefs);

        const std::string& getCurrencyCode() const;
        void setCurrencyCode(const std::string& currencyCode);

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);

        const std::tm& getMatchedSince() const;
        void setMatchedSince(const std::tm& matchedSince);

        const std::set<std::string>& getBetIds() const;
        void setBetIds(const std::set<std::string>& betIds);


    private:
        /**
         * The unique id for the market.
         */
        std::string marketId;
        /**
         * The unique id for the selection in the market.
         */
        Optional<int64_t> selectionId;
        /**
         * If specified, the handicap is used in conjunction with the selectionId to pick which
         * runner to return prices for
         */
        Optional<double> handicap;
        /**
         * The projection of price data you want to receive in the response.
         */
        PriceProjection priceProjection;
        /**
         * The orders you want to receive in the response.
         */
        OrderProjection orderProjection;
        /**
         * If you ask for orders, specifies the representation of matches.
         */
        MatchProjection matchProjection;
        /**
         * If you ask for orders, returns matches for each selection. Defaults to true if
         * unspecified.
         */
        Optional<bool> includeOverallPosition;
        /**
         * If you ask for orders, returns the breakdown of matches by strategy for each selection.
         * Groups matches with no strategy in an empty string bucket. Defaults to false if
         * unspecified.
         */
        Optional<bool> partitionMatchedByStrategyRef;
        /**
         * If you ask for orders, restricts the results to orders matching any of the specified set
         * of customer defined strategies. Also filters which matches by strategy for runners are
         * returned, if partitionMatchedByStrategyRef is true. An empty set will be treated as if
         * the parameter has been omitted (or null passed).
         */
        std::set<std::string> customerStrategyRefs;
        /**
         * A Betfair standard currency code. If not specified, the default currency code is used.
         */
        std::string currencyCode;
        /**
         * The language used for the response. If not specified, the default is returned.
         */
        std::string locale;
        /**
         * If you ask for orders, restricts the results to orders that have at least one fragment
         * matched since the specified date (all matched fragments of such an order will be
         * returned even if some were matched before the specified date). All EXECUTABLE orders
         * will be returned regardless of matched date.
         */
        std::tm matchedSince;
        /**
         * If you ask for orders, restricts the results to orders with the specified bet IDs.
         */
        std::set<std::string> betIds;
};

}
}

#endif // SPORT_LISTRUNNERBOOKREQUEST_H
