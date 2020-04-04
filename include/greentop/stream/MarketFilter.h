/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_MARKETFILTER_H
#define STREAM_MARKETFILTER_H

#include <json/json.h>
#include <set>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace stream {        

class MarketFilter : public JsonMember {
    public:

        MarketFilter(const std::set<std::string>& countryCodes = std::set<std::string>(),
            const std::set<std::string>& bettingTypes = std::set<std::string>(),
            const Optional<bool>& turnInPlayEnabled = Optional<bool>(),
            const std::set<std::string>& marketTypes = std::set<std::string>(),
            const std::set<std::string>& venues = std::set<std::string>(),
            const std::set<std::string>& marketIds = std::set<std::string>(),
            const std::set<std::string>& eventTypeIds = std::set<std::string>(),
            const std::set<std::string>& eventIds = std::set<std::string>(),
            const Optional<bool>& bspMarket = Optional<bool>(),
            const std::set<std::string>& raceTypes = std::set<std::string>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::set<std::string>& getCountryCodes() const;
        void setCountryCodes(const std::set<std::string>& countryCodes);

        const std::set<std::string>& getBettingTypes() const;
        void setBettingTypes(const std::set<std::string>& bettingTypes);

        const Optional<bool>& getTurnInPlayEnabled() const;
        void setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled);

        const std::set<std::string>& getMarketTypes() const;
        void setMarketTypes(const std::set<std::string>& marketTypes);

        const std::set<std::string>& getVenues() const;
        void setVenues(const std::set<std::string>& venues);

        const std::set<std::string>& getMarketIds() const;
        void setMarketIds(const std::set<std::string>& marketIds);

        const std::set<std::string>& getEventTypeIds() const;
        void setEventTypeIds(const std::set<std::string>& eventTypeIds);

        const std::set<std::string>& getEventIds() const;
        void setEventIds(const std::set<std::string>& eventIds);

        const Optional<bool>& getBspMarket() const;
        void setBspMarket(const Optional<bool>& bspMarket);

        const std::set<std::string>& getRaceTypes() const;
        void setRaceTypes(const std::set<std::string>& raceTypes);


    private:

        std::set<std::string> countryCodes;

        std::set<std::string> bettingTypes;

        Optional<bool> turnInPlayEnabled;

        std::set<std::string> marketTypes;

        std::set<std::string> venues;

        std::set<std::string> marketIds;

        std::set<std::string> eventTypeIds;

        std::set<std::string> eventIds;

        Optional<bool> bspMarket;

        std::set<std::string> raceTypes;
};

}
}

#endif // STREAM_MARKETFILTER_H
