/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETCATALOGUE_H
#define SPORT_MARKETCATALOGUE_H

#include <ctime>
#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/Competition.h"
#include "greentop/sport/Event.h"
#include "greentop/sport/EventType.h"
#include "greentop/sport/MarketDescription.h"
#include "greentop/sport/RunnerCatalog.h"

namespace greentop {
namespace sport {
/**
 * Information about a market
 */
class MarketCatalogue : public JsonMember {
    public:
        MarketCatalogue();

        MarketCatalogue(const std::string& marketId,
            const std::string& marketName,
            const std::tm& marketStartTime = std::tm(),
            const MarketDescription& description = MarketDescription(),
            const Optional<double>& totalMatched = Optional<double>(),
            const std::vector<RunnerCatalog>& runners = std::vector<RunnerCatalog>(),
            const EventType& eventType = EventType(),
            const Competition& competition = Competition(),
            const Event& event = Event());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::string& getMarketName() const;
        void setMarketName(const std::string& marketName);

        const std::tm& getMarketStartTime() const;
        void setMarketStartTime(const std::tm& marketStartTime);

        const MarketDescription& getDescription() const;
        void setDescription(const MarketDescription& description);

        const Optional<double>& getTotalMatched() const;
        void setTotalMatched(const Optional<double>& totalMatched);

        const std::vector<RunnerCatalog>& getRunners() const;
        void setRunners(const std::vector<RunnerCatalog>& runners);

        const EventType& getEventType() const;
        void setEventType(const EventType& eventType);

        const Competition& getCompetition() const;
        void setCompetition(const Competition& competition);

        const Event& getEvent() const;
        void setEvent(const Event& event);


    private:
        /**
         * The unique identifier for the market
         */
        std::string marketId;
        /**
         * The name of the market
         */
        std::string marketName;
        /**
         * The time this market starts at, only returned when the MARKET_START_TIME enum is passed
         * in the marketProjections
         */
        std::tm marketStartTime;
        /**
         * Details about the market
         */
        MarketDescription description;
        /**
         * The total amount of money matched on the market. This value is truncated at 2dp.
         */
        Optional<double> totalMatched;
        /**
         * The runners (selections) contained in the market
         */
        std::vector<RunnerCatalog> runners;
        /**
         * The Event Type the market is contained within
         */
        EventType eventType;
        /**
         * The competition the market is contained within. Usually only applies to Football
         * competitions
         */
        Competition competition;
        /**
         * The event the market is contained within
         */
        Event event;
};

}
}

#endif // SPORT_MARKETCATALOGUE_H
