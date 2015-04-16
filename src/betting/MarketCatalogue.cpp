#include "greentop/betting/MarketCatalogue.h"

namespace greentop {
MarketCatalogue::MarketCatalogue()  : totalMatched(-1){
}

MarketCatalogue::MarketCatalogue(const std::string& marketId,
    const std::string& marketName,
    const std::tm& marketStartTime,
    const MarketDescription& description,
    const double totalMatched,
    const std::vector<RunnerCatalog>& runners,
    const EventType& eventType,
    const Competition& competition,
    const Event& event) :
    marketId(marketId),
    marketName(marketName),
    marketStartTime(marketStartTime),
    description(description),
    totalMatched(totalMatched),
    runners(runners),
    eventType(eventType),
    competition(competition),
    event(event) {
}

void MarketCatalogue::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("marketName")) {
        marketName = json["marketName"].asString();
    }
    if (json.isMember("marketStartTime")) {
        strptime(json["marketStartTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &marketStartTime);
    }
    if (json.isMember("description")) {
        description.fromJson(json["description"]);
    }
    if (json.isMember("totalMatched")) {
        totalMatched = json["totalMatched"].asDouble();
    }
    if (json.isMember("runners")) {
        for (unsigned i = 0; i < json["runners"].size(); ++i) {
                RunnerCatalog runner;
                runner.fromJson(json["runners"][i]);
                runners.push_back(runner);
            };
    }
    if (json.isMember("eventType")) {
        eventType.fromJson(json["eventType"]);
    }
    if (json.isMember("competition")) {
        competition.fromJson(json["competition"]);
    }
    if (json.isMember("event")) {
        event.fromJson(json["event"]);
    }
}

Json::Value MarketCatalogue::toJson() const {
    Json::Value json;
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (marketName != "") {
        json["marketName"] = marketName;
    }
    if (false) {
        // marketStartTime not implemented;
    }
    if (description.isValid()) {
        json["description"] = description.toJson();
    }
    if (totalMatched >= 0) {
        json["totalMatched"] = totalMatched;
    }
    if (runners.size() > 0) {
        for (unsigned i = 0; i < runners.size(); ++i) {
            json["runners"].append(runners[i].toJson());
        };
    }
    if (eventType.isValid()) {
        json["eventType"] = eventType.toJson();
    }
    if (competition.isValid()) {
        json["competition"] = competition.toJson();
    }
    if (event.isValid()) {
        json["event"] = event.toJson();
    }
    return json;
}

bool MarketCatalogue::isValid() const {
    return marketId != "" && marketName != "";
}

const std::string& MarketCatalogue::getMarketId() const {
    return marketId;
}
void MarketCatalogue::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::string& MarketCatalogue::getMarketName() const {
    return marketName;
}
void MarketCatalogue::setMarketName(const std::string& marketName) {
    this->marketName = marketName;
}

const std::tm& MarketCatalogue::getMarketStartTime() const {
    return marketStartTime;
}
void MarketCatalogue::setMarketStartTime(const std::tm& marketStartTime) {
    this->marketStartTime = marketStartTime;
}

const MarketDescription& MarketCatalogue::getDescription() const {
    return description;
}
void MarketCatalogue::setDescription(const MarketDescription& description) {
    this->description = description;
}

const double MarketCatalogue::getTotalMatched() const {
    return totalMatched;
}
void MarketCatalogue::setTotalMatched(const double totalMatched) {
    this->totalMatched = totalMatched;
}

const std::vector<RunnerCatalog>& MarketCatalogue::getRunners() const {
    return runners;
}
void MarketCatalogue::setRunners(const std::vector<RunnerCatalog>& runners) {
    this->runners = runners;
}

const EventType& MarketCatalogue::getEventType() const {
    return eventType;
}
void MarketCatalogue::setEventType(const EventType& eventType) {
    this->eventType = eventType;
}

const Competition& MarketCatalogue::getCompetition() const {
    return competition;
}
void MarketCatalogue::setCompetition(const Competition& competition) {
    this->competition = competition;
}

const Event& MarketCatalogue::getEvent() const {
    return event;
}
void MarketCatalogue::setEvent(const Event& event) {
    this->event = event;
}


}



