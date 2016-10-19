/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/CountryCodeResult.h"

namespace greentop {


CountryCodeResult::CountryCodeResult(const std::string& countryCode,
    const Optional<int32_t>& marketCount) :
    countryCode(countryCode),
    marketCount(marketCount) {
}

void CountryCodeResult::fromJson(const Json::Value& json) {
    if (json.isMember("countryCode")) {
        countryCode = json["countryCode"].asString();
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asInt();
    }
}

Json::Value CountryCodeResult::toJson() const {
    Json::Value json(Json::objectValue);
    json["countryCode"] = countryCode;
    if (marketCount.isValid()) {
        json["marketCount"] = marketCount.toJson();
    }
    return json;
}

bool CountryCodeResult::isValid() const {
    return true;
}

const std::string& CountryCodeResult::getCountryCode() const {
    return countryCode;
}
void CountryCodeResult::setCountryCode(const std::string& countryCode) {
    this->countryCode = countryCode;
}

const Optional<int32_t>& CountryCodeResult::getMarketCount() const {
    return marketCount;
}
void CountryCodeResult::setMarketCount(const Optional<int32_t>& marketCount) {
    this->marketCount = marketCount;
}


}



