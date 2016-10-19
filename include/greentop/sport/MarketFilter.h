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
        std::string textQuery;
        std::set<std::string> exchangeIds;
        std::set<std::string> eventTypeIds;
        std::set<std::string> eventIds;
        std::set<std::string> competitionIds;
        std::set<std::string> marketIds;
        std::set<std::string> venues;
        Optional<bool> bspOnly;
        Optional<bool> turnInPlayEnabled;
        Optional<bool> inPlayOnly;
        std::set<MarketBettingType> marketBettingTypes;
        std::set<std::string> marketCountries;
        std::set<std::string> marketTypeCodes;
        TimeRange marketStartTime;
        std::set<OrderStatus> withOrders;
};

}

#endif // MARKETFILTER_H


