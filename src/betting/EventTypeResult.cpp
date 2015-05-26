/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/EventTypeResult.h"

namespace greentop {

EventTypeResult::EventTypeResult(const EventType& eventType,
    const uint64_t marketCount) :
    eventType(eventType),
    marketCount(marketCount) {
}

void EventTypeResult::fromJson(const Json::Value& json) {
    if (json.isMember("eventType")) {
        eventType.fromJson(json["eventType"]);
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asUInt64();
    }
}

Json::Value EventTypeResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (eventType.isValid()) {
        json["eventType"] = eventType.toJson();
    }
    if (marketCount > 0) {
        json["marketCount"] = marketCount;
    }
    return json;
}

bool EventTypeResult::isValid() const {
    return true;
}

const EventType& EventTypeResult::getEventType() const {
    return eventType;
}
void EventTypeResult::setEventType(const EventType& eventType) {
    this->eventType = eventType;
}

const uint64_t EventTypeResult::getMarketCount() const {
    return marketCount;
}
void EventTypeResult::setMarketCount(const uint64_t marketCount) {
    this->marketCount = marketCount;
}


}



