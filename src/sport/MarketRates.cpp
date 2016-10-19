/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketRates.h"

namespace greentop {

MarketRates::MarketRates() : marketBaseRate(-1), discountAllowed(false) {
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
    json["marketBaseRate"] = marketBaseRate;
    json["discountAllowed"] = discountAllowed;
    return json;
}

bool MarketRates::isValid() const {
    return true;
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



