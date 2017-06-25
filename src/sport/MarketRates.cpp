/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketRates.h"

namespace greentop {

MarketRates::MarketRates() {
}

MarketRates::MarketRates(const Optional<double>& marketBaseRate,
    const Optional<bool>& discountAllowed) :
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

const Optional<double>& MarketRates::getMarketBaseRate() const {
    return marketBaseRate;
}
void MarketRates::setMarketBaseRate(const Optional<double>& marketBaseRate) {
    this->marketBaseRate = marketBaseRate;
}

const Optional<bool>& MarketRates::getDiscountAllowed() const {
    return discountAllowed;
}
void MarketRates::setDiscountAllowed(const Optional<bool>& discountAllowed) {
    this->discountAllowed = discountAllowed;
}


}



