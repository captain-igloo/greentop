/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/VenueResult.h"

namespace greentop {
namespace sport {


VenueResult::VenueResult(const std::string& venue,
    const Optional<int32_t>& marketCount) :
    venue(venue),
    marketCount(marketCount) {
}

void VenueResult::fromJson(const Json::Value& json) {
    if (json.isMember("venue")) {
        venue = json["venue"].asString();
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asInt();
    }
}

Json::Value VenueResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (venue != "") {
        json["venue"] = venue;
    }
    if (marketCount.isValid()) {
        json["marketCount"] = marketCount.toJson();
    }
    return json;
}

bool VenueResult::isValid() const {
    return true;
}

const std::string& VenueResult::getVenue() const {
    return venue;
}
void VenueResult::setVenue(const std::string& venue) {
    this->venue = venue;
}

const Optional<int32_t>& VenueResult::getMarketCount() const {
    return marketCount;
}
void VenueResult::setMarketCount(const Optional<int32_t>& marketCount) {
    this->marketCount = marketCount;
}


}
}
