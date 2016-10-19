/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketFilter.h"

namespace greentop {


MarketFilter::MarketFilter(const std::string& textQuery,
    const std::set<std::string>& exchangeIds,
    const std::set<std::string>& eventTypeIds,
    const std::set<std::string>& eventIds,
    const std::set<std::string>& competitionIds,
    const std::set<std::string>& marketIds,
    const std::set<std::string>& venues,
    const Optional<bool>& bspOnly,
    const Optional<bool>& turnInPlayEnabled,
    const Optional<bool>& inPlayOnly,
    const std::set<MarketBettingType>& marketBettingTypes,
    const std::set<std::string>& marketCountries,
    const std::set<std::string>& marketTypeCodes,
    const TimeRange& marketStartTime,
    const std::set<OrderStatus>& withOrders) :
    textQuery(textQuery),
    exchangeIds(exchangeIds),
    eventTypeIds(eventTypeIds),
    eventIds(eventIds),
    competitionIds(competitionIds),
    marketIds(marketIds),
    venues(venues),
    bspOnly(bspOnly),
    turnInPlayEnabled(turnInPlayEnabled),
    inPlayOnly(inPlayOnly),
    marketBettingTypes(marketBettingTypes),
    marketCountries(marketCountries),
    marketTypeCodes(marketTypeCodes),
    marketStartTime(marketStartTime),
    withOrders(withOrders) {
}

void MarketFilter::fromJson(const Json::Value& json) {
    if (json.isMember("textQuery")) {
        textQuery = json["textQuery"].asString();
    }
    if (json.isMember("exchangeIds")) {
        for (unsigned i = 0; i < json["exchangeIds"].size(); ++i) {
            exchangeIds.insert(json["exchangeIds"][i].asString());
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
    if (json.isMember("competitionIds")) {
        for (unsigned i = 0; i < json["competitionIds"].size(); ++i) {
            competitionIds.insert(json["competitionIds"][i].asString());
        }
    }
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        }
    }
    if (json.isMember("venues")) {
        for (unsigned i = 0; i < json["venues"].size(); ++i) {
            venues.insert(json["venues"][i].asString());
        }
    }
    if (json.isMember("bspOnly")) {
        bspOnly = json["bspOnly"].asBool();
    }
    if (json.isMember("turnInPlayEnabled")) {
        turnInPlayEnabled = json["turnInPlayEnabled"].asBool();
    }
    if (json.isMember("inPlayOnly")) {
        inPlayOnly = json["inPlayOnly"].asBool();
    }
    if (json.isMember("marketBettingTypes")) {
        for (unsigned i = 0; i < json["marketBettingTypes"].size(); ++i) {
            marketBettingTypes.insert(json["marketBettingTypes"][i].asString());
        }
    }
    if (json.isMember("marketCountries")) {
        for (unsigned i = 0; i < json["marketCountries"].size(); ++i) {
            marketCountries.insert(json["marketCountries"][i].asString());
        }
    }
    if (json.isMember("marketTypeCodes")) {
        for (unsigned i = 0; i < json["marketTypeCodes"].size(); ++i) {
            marketTypeCodes.insert(json["marketTypeCodes"][i].asString());
        }
    }
    if (json.isMember("marketStartTime")) {
        marketStartTime.fromJson(json["marketStartTime"]);
    }
    if (json.isMember("withOrders")) {
        for (unsigned i = 0; i < json["withOrders"].size(); ++i) {
            withOrders.insert(json["withOrders"][i].asString());
        }
    }
}

Json::Value MarketFilter::toJson() const {
    Json::Value json(Json::objectValue);
    if (textQuery != "") {
        json["textQuery"] = textQuery;
    }
    if (exchangeIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = exchangeIds.begin(); it != exchangeIds.end(); ++it) {
            json["exchangeIds"].append(*it);
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
    if (competitionIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = competitionIds.begin(); it != competitionIds.end(); ++it) {
            json["competitionIds"].append(*it);
        }
    }
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        }
    }
    if (venues.size() > 0) {
        for (std::set<std::string>::const_iterator it = venues.begin(); it != venues.end(); ++it) {
            json["venues"].append(*it);
        }
    }
    if (bspOnly.isValid()) {
        json["bspOnly"] = bspOnly.toJson();
    }
    if (turnInPlayEnabled.isValid()) {
        json["turnInPlayEnabled"] = turnInPlayEnabled.toJson();
    }
    if (inPlayOnly.isValid()) {
        json["inPlayOnly"] = inPlayOnly.toJson();
    }
    if (marketBettingTypes.size() > 0) {
        for (std::set<MarketBettingType>::const_iterator it = marketBettingTypes.begin(); it != marketBettingTypes.end(); ++it) {
            MarketBettingType marketBettingTypes(*it);
            json["marketBettingTypes"].append(marketBettingTypes.getValue());
        }
    }
    if (marketCountries.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketCountries.begin(); it != marketCountries.end(); ++it) {
            json["marketCountries"].append(*it);
        }
    }
    if (marketTypeCodes.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketTypeCodes.begin(); it != marketTypeCodes.end(); ++it) {
            json["marketTypeCodes"].append(*it);
        }
    }
    if (marketStartTime.isValid()) {
        json["marketStartTime"] = marketStartTime.toJson();
    }
    if (withOrders.size() > 0) {
        for (std::set<OrderStatus>::const_iterator it = withOrders.begin(); it != withOrders.end(); ++it) {
            OrderStatus withOrders(*it);
            json["withOrders"].append(withOrders.getValue());
        }
    }
    return json;
}

bool MarketFilter::isValid() const {
    return true;
}

const std::string& MarketFilter::getTextQuery() const {
    return textQuery;
}
void MarketFilter::setTextQuery(const std::string& textQuery) {
    this->textQuery = textQuery;
}

const std::set<std::string>& MarketFilter::getExchangeIds() const {
    return exchangeIds;
}
void MarketFilter::setExchangeIds(const std::set<std::string>& exchangeIds) {
    this->exchangeIds = exchangeIds;
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

const std::set<std::string>& MarketFilter::getCompetitionIds() const {
    return competitionIds;
}
void MarketFilter::setCompetitionIds(const std::set<std::string>& competitionIds) {
    this->competitionIds = competitionIds;
}

const std::set<std::string>& MarketFilter::getMarketIds() const {
    return marketIds;
}
void MarketFilter::setMarketIds(const std::set<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const std::set<std::string>& MarketFilter::getVenues() const {
    return venues;
}
void MarketFilter::setVenues(const std::set<std::string>& venues) {
    this->venues = venues;
}

const Optional<bool>& MarketFilter::getBspOnly() const {
    return bspOnly;
}
void MarketFilter::setBspOnly(const Optional<bool>& bspOnly) {
    this->bspOnly = bspOnly;
}

const Optional<bool>& MarketFilter::getTurnInPlayEnabled() const {
    return turnInPlayEnabled;
}
void MarketFilter::setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled) {
    this->turnInPlayEnabled = turnInPlayEnabled;
}

const Optional<bool>& MarketFilter::getInPlayOnly() const {
    return inPlayOnly;
}
void MarketFilter::setInPlayOnly(const Optional<bool>& inPlayOnly) {
    this->inPlayOnly = inPlayOnly;
}

const std::set<MarketBettingType>& MarketFilter::getMarketBettingTypes() const {
    return marketBettingTypes;
}
void MarketFilter::setMarketBettingTypes(const std::set<MarketBettingType>& marketBettingTypes) {
    this->marketBettingTypes = marketBettingTypes;
}

const std::set<std::string>& MarketFilter::getMarketCountries() const {
    return marketCountries;
}
void MarketFilter::setMarketCountries(const std::set<std::string>& marketCountries) {
    this->marketCountries = marketCountries;
}

const std::set<std::string>& MarketFilter::getMarketTypeCodes() const {
    return marketTypeCodes;
}
void MarketFilter::setMarketTypeCodes(const std::set<std::string>& marketTypeCodes) {
    this->marketTypeCodes = marketTypeCodes;
}

const TimeRange& MarketFilter::getMarketStartTime() const {
    return marketStartTime;
}
void MarketFilter::setMarketStartTime(const TimeRange& marketStartTime) {
    this->marketStartTime = marketStartTime;
}

const std::set<OrderStatus>& MarketFilter::getWithOrders() const {
    return withOrders;
}
void MarketFilter::setWithOrders(const std::set<OrderStatus>& withOrders) {
    this->withOrders = withOrders;
}


}



