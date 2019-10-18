/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/MarketFilter.h"

namespace greentop {
namespace stream {


MarketFilter::MarketFilter(const std::set<std::string>& countryCodes,
    const std::set<std::string>& bettingTypes,
    const Optional<bool>& turnInPlayEnabled,
    const std::set<std::string>& marketTypes,
    const std::set<std::string>& venues,
    const std::set<std::string>& marketIds,
    const std::set<std::string>& eventTypeIds,
    const std::set<std::string>& eventIds,
    const Optional<bool>& bspMarket,
    const std::set<std::string>& raceTypes) :
    countryCodes(countryCodes),
    bettingTypes(bettingTypes),
    turnInPlayEnabled(turnInPlayEnabled),
    marketTypes(marketTypes),
    venues(venues),
    marketIds(marketIds),
    eventTypeIds(eventTypeIds),
    eventIds(eventIds),
    bspMarket(bspMarket),
    raceTypes(raceTypes) {
}

void MarketFilter::fromJson(const Json::Value& json) {
    if (json.isMember("countryCodes")) {
        for (unsigned i = 0; i < json["countryCodes"].size(); ++i) {
            countryCodes.insert(json["countryCodes"][i].asString());
        }
    }
    if (json.isMember("bettingTypes")) {
        for (unsigned i = 0; i < json["bettingTypes"].size(); ++i) {
            bettingTypes.insert(json["bettingTypes"][i].asString());
        }
    }
    if (json.isMember("turnInPlayEnabled")) {
        turnInPlayEnabled = json["turnInPlayEnabled"].asBool();
    }
    if (json.isMember("marketTypes")) {
        for (unsigned i = 0; i < json["marketTypes"].size(); ++i) {
            marketTypes.insert(json["marketTypes"][i].asString());
        }
    }
    if (json.isMember("venues")) {
        for (unsigned i = 0; i < json["venues"].size(); ++i) {
            venues.insert(json["venues"][i].asString());
        }
    }
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        }
    }
    if (json.isMember("eventTypeIds")) {
        for (unsigned i = 0; i < json["eventTypeIds"].size(); ++i) {
            eventTypeIds.insert(json["eventTypeIds"][i].asString());
        }
    }
    if (json.isMember("eventIds")) {
        for (unsigned i = 0; i < json["eventIds"].size(); ++i) {
            eventIds.insert(json["eventIds"][i].asString());
        }
    }
    if (json.isMember("bspMarket")) {
        bspMarket = json["bspMarket"].asBool();
    }
    if (json.isMember("raceTypes")) {
        for (unsigned i = 0; i < json["raceTypes"].size(); ++i) {
            raceTypes.insert(json["raceTypes"][i].asString());
        }
    }
}

Json::Value MarketFilter::toJson() const {
    Json::Value json(Json::objectValue);
    if (countryCodes.size() > 0) {
        for (std::set<std::string>::const_iterator it = countryCodes.begin(); it != countryCodes.end(); ++it) {
            json["countryCodes"].append(*it);
        }
    }
    if (bettingTypes.size() > 0) {
        for (std::set<std::string>::const_iterator it = bettingTypes.begin(); it != bettingTypes.end(); ++it) {
            json["bettingTypes"].append(*it);
        }
    }
    if (turnInPlayEnabled.isValid()) {
        json["turnInPlayEnabled"] = turnInPlayEnabled.toJson();
    }
    if (marketTypes.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketTypes.begin(); it != marketTypes.end(); ++it) {
            json["marketTypes"].append(*it);
        }
    }
    if (venues.size() > 0) {
        for (std::set<std::string>::const_iterator it = venues.begin(); it != venues.end(); ++it) {
            json["venues"].append(*it);
        }
    }
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        }
    }
    if (eventTypeIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = eventTypeIds.begin(); it != eventTypeIds.end(); ++it) {
            json["eventTypeIds"].append(*it);
        }
    }
    if (eventIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = eventIds.begin(); it != eventIds.end(); ++it) {
            json["eventIds"].append(*it);
        }
    }
    if (bspMarket.isValid()) {
        json["bspMarket"] = bspMarket.toJson();
    }
    if (raceTypes.size() > 0) {
        for (std::set<std::string>::const_iterator it = raceTypes.begin(); it != raceTypes.end(); ++it) {
            json["raceTypes"].append(*it);
        }
    }
    return json;
}

bool MarketFilter::isValid() const {
    return true;
}

const std::set<std::string>& MarketFilter::getCountryCodes() const {
    return countryCodes;
}
void MarketFilter::setCountryCodes(const std::set<std::string>& countryCodes) {
    this->countryCodes = countryCodes;
}

const std::set<std::string>& MarketFilter::getBettingTypes() const {
    return bettingTypes;
}
void MarketFilter::setBettingTypes(const std::set<std::string>& bettingTypes) {
    this->bettingTypes = bettingTypes;
}

const Optional<bool>& MarketFilter::getTurnInPlayEnabled() const {
    return turnInPlayEnabled;
}
void MarketFilter::setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled) {
    this->turnInPlayEnabled = turnInPlayEnabled;
}

const std::set<std::string>& MarketFilter::getMarketTypes() const {
    return marketTypes;
}
void MarketFilter::setMarketTypes(const std::set<std::string>& marketTypes) {
    this->marketTypes = marketTypes;
}

const std::set<std::string>& MarketFilter::getVenues() const {
    return venues;
}
void MarketFilter::setVenues(const std::set<std::string>& venues) {
    this->venues = venues;
}

const std::set<std::string>& MarketFilter::getMarketIds() const {
    return marketIds;
}
void MarketFilter::setMarketIds(const std::set<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const std::set<std::string>& MarketFilter::getEventTypeIds() const {
    return eventTypeIds;
}
void MarketFilter::setEventTypeIds(const std::set<std::string>& eventTypeIds) {
    this->eventTypeIds = eventTypeIds;
}

const std::set<std::string>& MarketFilter::getEventIds() const {
    return eventIds;
}
void MarketFilter::setEventIds(const std::set<std::string>& eventIds) {
    this->eventIds = eventIds;
}

const Optional<bool>& MarketFilter::getBspMarket() const {
    return bspMarket;
}
void MarketFilter::setBspMarket(const Optional<bool>& bspMarket) {
    this->bspMarket = bspMarket;
}

const std::set<std::string>& MarketFilter::getRaceTypes() const {
    return raceTypes;
}
void MarketFilter::setRaceTypes(const std::set<std::string>& raceTypes) {
    this->raceTypes = raceTypes;
}


}
}
