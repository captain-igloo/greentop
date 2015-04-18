/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/CurrencyRate.h"

namespace greentop {

CurrencyRate::CurrencyRate(const std::string& currencyCode,
    const double rate) :
    currencyCode(currencyCode),
    rate(rate) {
}

void CurrencyRate::fromJson(const Json::Value& json) {
    if (json.isMember("currencyCode")) {
        currencyCode = json["currencyCode"].asString();
    }
    if (json.isMember("rate")) {
        rate = json["rate"].asDouble();
    }
}

Json::Value CurrencyRate::toJson() const {
    Json::Value json(Json::objectValue);
    if (currencyCode != "") {
        json["currencyCode"] = currencyCode;
    }
    if (rate >= 0) {
        json["rate"] = rate;
    }
    return json;
}

bool CurrencyRate::isValid() const {
    return true;
}

const std::string& CurrencyRate::getCurrencyCode() const {
    return currencyCode;
}
void CurrencyRate::setCurrencyCode(const std::string& currencyCode) {
    this->currencyCode = currencyCode;
}

const double CurrencyRate::getRate() const {
    return rate;
}
void CurrencyRate::setRate(const double rate) {
    this->rate = rate;
}


}



