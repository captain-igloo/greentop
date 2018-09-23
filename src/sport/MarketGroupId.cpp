/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketGroupId.h"

namespace greentop {


MarketGroupId::MarketGroupId(const Optional<int64_t>& eventId) :
    eventId(eventId) {
}

void MarketGroupId::fromJson(const Json::Value& json) {
    if (json.isMember("eventId")) {
        eventId = json["eventId"].asInt64();
    }
}

Json::Value MarketGroupId::toJson() const {
    Json::Value json(Json::objectValue);
    if (eventId.isValid()) {
        json["eventId"] = eventId.toJson();
    }
    return json;
}

bool MarketGroupId::isValid() const {
    return true;
}

const Optional<int64_t>& MarketGroupId::getEventId() const {
    return eventId;
}
void MarketGroupId::setEventId(const Optional<int64_t>& eventId) {
    this->eventId = eventId;
}


}



