/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketRates.h"

namespace greentop {

MarketRates::MarketRates() {
}

MarketRates::MarketRates(const double marketBaseRate,
    const bool discountAllowed) :
    marketBaseRate(marketBaseRate),
    discountAllowed(discountAllowed) {
}

void MarketRates::fromJson(const Json::Value& json) {
    if (json.isMember("marketBaseRate")) {
        marketBaseRate = json["marketBaseRate"].asDouble();
    }
    if (json.isMember("discountAllowed")) {
        discountAllowed = json["discountAllowed"].asBool();
    }
}

Json::Value MarketRates::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketBaseRate.isValid()) {
        json["marketBaseRate"] = marketBaseRate.toJson();
    }
    if (discountAllowed.isValid()) {
        json["discountAllowed"] = discountAllowed.toJson();
    }
    return json;
}

bool MarketRates::isValid() const {
    return marketBaseRate.isValid() && discountAllowed.isValid();
}

const double MarketRates::getMarketBaseRate() const {
    return marketBaseRate;
}
void MarketRates::setMarketBaseRate(const double marketBaseRate) {
    this->marketBaseRate = marketBaseRate;
}

const bool MarketRates::getDiscountAllowed() const {
    return discountAllowed;
}
void MarketRates::setDiscountAllowed(const bool discountAllowed) {
    this->discountAllowed = discountAllowed;
}


}



