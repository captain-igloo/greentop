/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/EventTypeResult.h"

namespace greentop {
namespace sport {


EventTypeResult::EventTypeResult(const EventType& eventType,
    const Optional<int32_t>& marketCount) :
    eventType(eventType),
    marketCount(marketCount) {
}

void EventTypeResult::fromJson(const Json::Value& json) {
    if (json.isMember("eventType")) {
        eventType.fromJson(json["eventType"]);
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asInt();
    }
}

Json::Value EventTypeResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (eventType.isValid()) {
        json["eventType"] = eventType.toJson();
    }
    if (marketCount.isValid()) {
        json["marketCount"] = marketCount.toJson();
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

const Optional<int32_t>& EventTypeResult::getMarketCount() const {
    return marketCount;
}
void EventTypeResult::setMarketCount(const Optional<int32_t>& marketCount) {
    this->marketCount = marketCount;
}


}
}
