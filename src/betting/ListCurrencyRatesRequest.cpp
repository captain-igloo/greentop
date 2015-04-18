/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ListCurrencyRatesRequest.h"

namespace greentop {

ListCurrencyRatesRequest::ListCurrencyRatesRequest(const std::string& fromCurrency) :
    fromCurrency(fromCurrency) {
}

void ListCurrencyRatesRequest::fromJson(const Json::Value& json) {
    if (json.isMember("fromCurrency")) {
        fromCurrency = json["fromCurrency"].asString();
    }
}

Json::Value ListCurrencyRatesRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (fromCurrency != "") {
        json["fromCurrency"] = fromCurrency;
    }
    return json;
}

bool ListCurrencyRatesRequest::isValid() const {
    return true;
}

const std::string& ListCurrencyRatesRequest::getFromCurrency() const {
    return fromCurrency;
}
void ListCurrencyRatesRequest::setFromCurrency(const std::string& fromCurrency) {
    this->fromCurrency = fromCurrency;
}


}



