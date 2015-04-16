#include "greentop/betting/EventResult.h"

namespace greentop {

EventResult::EventResult(const Event& event,
    const int marketCount) :
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
    Json::Value json;
    if (event.isValid()) {
        json["event"] = event.toJson();
    }
    if (marketCount >= 0) {
        json["marketCount"] = marketCount;
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

const int EventResult::getMarketCount() const {
    return marketCount;
}
void EventResult::setMarketCount(const int marketCount) {
    this->marketCount = marketCount;
}


}



