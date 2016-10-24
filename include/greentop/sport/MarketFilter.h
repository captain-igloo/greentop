/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETFILTER_H
#define MARKETFILTER_H

#include <json/json.h>
#include <set>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/common/TimeRange.h"
#include "greentop/sport/enum/MarketBettingType.h"
#include "greentop/sport/enum/OrderStatus.h"

namespace greentop {

class MarketFilter : public JsonMember {
    public:

        MarketFilter(const std::string& textQuery = std::string(),
            const std::set<std::string>& exchangeIds = std::set<std::string>(),
            const std::set<std::string>& eventTypeIds = std::set<std::string>(),
            const std::set<std::string>& eventIds = std::set<std::string>(),
            const std::set<std::string>& competitionIds = std::set<std::string>(),
            const std::set<std::string>& marketIds = std::set<std::string>(),
            const std::set<std::string>& venues = std::set<std::string>(),
            const Optional<bool>& bspOnly = Optional<bool>(),
            const Optional<bool>& turnInPlayEnabled = Optional<bool>(),
            const Optional<bool>& inPlayOnly = Optional<bool>(),
            const std::set<MarketBettingType>& marketBettingTypes = std::set<MarketBettingType>(),
            const std::set<std::string>& marketCountries = std::set<std::string>(),
            const std::set<std::string>& marketTypeCodes = std::set<std::string>(),
            const TimeRange& marketStartTime = TimeRange(),
            const std::set<OrderStatus>& withOrders = std::set<OrderStatus>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getTextQuery() const;
        void setTextQuery(const std::string& textQuery);

        const std::set<std::string>& getExchangeIds() const;
        void setExchangeIds(const std::set<std::string>& exchangeIds);

        const std::set<std::string>& getEventTypeIds() const;
        void setEventTypeIds(const std::set<std::string>& eventTypeIds);

        const std::set<std::string>& getEventIds() const;
        void setEventIds(const std::set<std::string>& eventIds);

        const std::set<std::string>& getCompetitionIds() const;
        void setCompetitionIds(const std::set<std::string>& competitionIds);

        const std::set<std::string>& getMarketIds() const;
        void setMarketIds(const std::set<std::string>& marketIds);

        const std::set<std::string>& getVenues() const;
        void setVenues(const std::set<std::string>& venues);

        const Optional<bool>& getBspOnly() const;
        void setBspOnly(const Optional<bool>& bspOnly);

        const Optional<bool>& getTurnInPlayEnabled() const;
        void setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled);

        const Optional<bool>& getInPlayOnly() const;
        void setInPlayOnly(const Optional<bool>& inPlayOnly);

        const std::set<MarketBettingType>& getMarketBettingTypes() const;
        void setMarketBettingTypes(const std::set<MarketBettingType>& marketBettingTypes);

        const std::set<std::string>& getMarketCountries() const;
        void setMarketCountries(const std::set<std::string>& marketCountries);

        const std::set<std::string>& getMarketTypeCodes() const;
        void setMarketTypeCodes(const std::set<std::string>& marketTypeCodes);

        const TimeRange& getMarketStartTime() const;
        void setMarketStartTime(const TimeRange& marketStartTime);

        const std::set<OrderStatus>& getWithOrders() const;
        void setWithOrders(const std::set<OrderStatus>& withOrders);


    private:
        /**
         * Restrict markets by any text associated with the market such as the Name, Event,
         * Competition, etc. You can include a wildcard (*) character as long as it is not the
         * first character.
         */
        std::string textQuery;
        /**
         * Restrict markets by the Exchange where the market operates. Note: This is not currently
         * in use and only entities for the current exchange will be returned.
         */
        std::set<std::string> exchangeIds;
        /**
         * Restrict markets by event type associated with the market. (i.e., Football, Hockey, etc)
         */
        std::set<std::string> eventTypeIds;
        /**
         * Restrict markets by the event id associated with the market.
         */
        std::set<std::string> eventIds;
        /**
         * Restrict markets by the competitions associated with the market.
         */
        std::set<std::string> competitionIds;
        /**
         * Restrict markets by the market id associated with the market.
         */
        std::set<std::string> marketIds;
        /**
         * Restrict markets by the venue associated with the market. Currently only Horse Racing
         * markets have venues.
         */
        std::set<std::string> venues;
        /**
         * Restrict to bsp markets only, if True or non-bsp markets if False. If not specified then
         * returns both BSP and non-BSP markets
         */
        Optional<bool> bspOnly;
        /**
         * Restrict to markets that will turn in play if True or will not turn in play if false. If
         * not specified, returns both.
         */
        Optional<bool> turnInPlayEnabled;
        /**
         * Restrict to markets that will turn in play if True or will not turn in play if false. If
         * not specified, returns both.
         */
        Optional<bool> inPlayOnly;
        /**
         * Restrict to markets that match the betting type of the market (i.e. Odds, Asian Handicap
         * Singles, or Asian Handicap Doubles
         */
        std::set<MarketBettingType> marketBettingTypes;
        /**
         * Restrict to markets that are in the specified country or countries
         */
        std::set<std::string> marketCountries;
        /**
         * Restrict to markets that match the type of the market (i.e., MATCH_ODDS,
         * HALF_TIME_SCORE). You should use this instead of relying on the market name as the
         * market type codes are the same in all locales
         */
        std::set<std::string> marketTypeCodes;
        /**
         * Restrict to markets with a market start time before or after the specified date
         */
        TimeRange marketStartTime;
        /**
         * Restrict to markets that I have one or more orders in these status.
         */
        std::set<OrderStatus> withOrders;
};

}

#endif // MARKETFILTER_H


