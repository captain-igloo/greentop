/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/CurrencyRate.h"

namespace greentop {
namespace account {


CurrencyRate::CurrencyRate(const std::string& currencyCode,
    const Optional<double>& rate) :
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
    if (rate.isValid()) {
        json["rate"] = rate.toJson();
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

const Optional<double>& CurrencyRate::getRate() const {
    return rate;
}
void CurrencyRate::setRate(const Optional<double>& rate) {
    this->rate = rate;
}


}
}
