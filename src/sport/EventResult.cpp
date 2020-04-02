/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/EventResult.h"

namespace greentop {
namespace sport {


EventResult::EventResult(const Event& event,
    const Optional<int32_t>& marketCount) :
    event(event),
    marketCount(marketCount) {
}

void EventResult::fromJson(const Json::Value& json) {
    if (json.isMember("event")) {
        event.fromJson(json["event"]);
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asInt();
    }
}

Json::Value EventResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (event.isValid()) {
        json["event"] = event.toJson();
    }
    if (marketCount.isValid()) {
        json["marketCount"] = marketCount.toJson();
    }
    return json;
}

bool EventResult::isValid() const {
    return true;
}

const Event& EventResult::getEvent() const {
    return event;
}
void EventResult::setEvent(const Event& event) {
    this->event = event;
}

const Optional<int32_t>& EventResult::getMarketCount() const {
    return marketCount;
}
void EventResult::setMarketCount(const Optional<int32_t>& marketCount) {
    this->marketCount = marketCount;
}


}
}
