/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETCATALOGUE_H
#define MARKETCATALOGUE_H

#include <ctime>
#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/betting/Competition.h"
#include "greentop/betting/Event.h"
#include "greentop/betting/EventType.h"
#include "greentop/betting/MarketDescription.h"
#include "greentop/betting/RunnerCatalog.h"

namespace greentop {

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
        std::string marketId;
        std::string marketName;
        std::tm marketStartTime;
        MarketDescription description;
        Optional<double> totalMatched;
        std::vector<RunnerCatalog> runners;
        EventType eventType;
        Competition competition;
        Event event;
};

}

#endif // MARKETCATALOGUE_H


