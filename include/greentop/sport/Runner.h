/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNER_H
#define RUNNER_H

#include <ctime>
#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/ExchangePrices.h"
#include "greentop/sport/Match.h"
#include "greentop/sport/Order.h"
#include "greentop/sport/StartingPrices.h"

namespace greentop {

/**
 * The dynamic data about runners in a market
 */
class Runner : public JsonMember {
    public:
        Runner();

        Runner(const int64_t selectionId,
            const double handicap,
            const std::string& status,
            const double adjustmentFactor,
            const Optional<double>& lastPriceTraded = Optional<double>(),
            const Optional<double>& totalMatched = Optional<double>(),
            const std::tm& removalDate = std::tm(),
            const StartingPrices& sp = StartingPrices(),
            const ExchangePrices& ex = ExchangePrices(),
            const std::vector<Order>& orders = std::vector<Order>(),
            const std::vector<Match>& matches = std::vector<Match>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const int64_t getSelectionId() const;
        void setSelectionId(const int64_t selectionId);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const double getAdjustmentFactor() const;
        void setAdjustmentFactor(const double adjustmentFactor);

        const Optional<double>& getLastPriceTraded() const;
        void setLastPriceTraded(const Optional<double>& lastPriceTraded);

        const Optional<double>& getTotalMatched() const;
        void setTotalMatched(const Optional<double>& totalMatched);

        const std::tm& getRemovalDate() const;
        void setRemovalDate(const std::tm& removalDate);

        const StartingPrices& getSp() const;
        void setSp(const StartingPrices& sp);

        const ExchangePrices& getEx() const;
        void setEx(const ExchangePrices& ex);

        const std::vector<Order>& getOrders() const;
        void setOrders(const std::vector<Order>& orders);

        const std::vector<Match>& getMatches() const;
        void setMatches(const std::vector<Match>& matches);


    private:
        /**
         * The unique id of the runner (selection)
         */
        int64_t selectionId;
        /**
         * The handicap
         */
        double handicap;
        /**
         * The status of the selection (i.e., ACTIVE, REMOVED, WINNER, LOSER)
         */
        std::string status;
        /**
         * The adjustment factor applied if the selection is removed
         */
        double adjustmentFactor;
        /**
         * The price of the most recent bet matched on this selection
         */
        Optional<double> lastPriceTraded;
        /**
         * The total amount matched on this runner. This value is truncated at 2dp.
         */
        Optional<double> totalMatched;
        /**
         * If date and time the runner was removed
         */
        std::tm removalDate;
        /**
         * The BSP related prices for this runner
         */
        StartingPrices sp;
        /**
         * The Exchange prices available for this runner
         */
        ExchangePrices ex;
        /**
         * List of orders in the market
         */
        std::vector<Order> orders;
        /**
         * List of matches (i.e, orders that have been fully or partially executed)
         */
        std::vector<Match> matches;
};

}

#endif // RUNNER_H


