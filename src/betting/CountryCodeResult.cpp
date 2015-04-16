#include "greentop/betting/CountryCodeResult.h"

namespace greentop {

CountryCodeResult::CountryCodeResult(const std::string& countryCode,
    const uint64_t marketCount) :
    countryCode(countryCode),
    marketCount(marketCount) {
}

void CountryCodeResult::fromJson(const Json::Value& json) {
    if (json.isMember("countryCode")) {
        countryCode = json["countryCode"].asString();
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asUInt();
    }
}

Json::Value CountryCodeResult::toJson() const {
    Json::Value json;
    if (countryCode != "") {
        json["countryCode"] = countryCode;
    }
    if (marketCount >= 0) {
        json["marketCount"] = marketCount;
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

const uint64_t CountryCodeResult::getMarketCount() const {
    return marketCount;
}
void CountryCodeResult::setMarketCount(const uint64_t marketCount) {
    this->marketCount = marketCount;
}


}



