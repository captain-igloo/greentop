#include "greentop/betting/ListMarketBookRequest.h"

namespace greentop {
ListMarketBookRequest::ListMarketBookRequest() {
}

ListMarketBookRequest::ListMarketBookRequest(const std::set<std::string>& marketIds,
    const PriceProjection& priceProjection,
    const OrderProjection& orderProjection,
    const MatchProjection& matchProjection,
    const std::string& currencyCode,
    const std::string& locale) :
    marketIds(marketIds),
    priceProjection(priceProjection),
    orderProjection(orderProjection),
    matchProjection(matchProjection),
    currencyCode(currencyCode),
    locale(locale) {
}

void ListMarketBookRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        };
    }
    if (json.isMember("priceProjection")) {
        priceProjection.fromJson(json["priceProjection"]);
    }
    if (json.isMember("orderProjection")) {
        orderProjection = json["orderProjection"].asString();
    }
    if (json.isMember("matchProjection")) {
        matchProjection = json["matchProjection"].asString();
    }
    if (json.isMember("currencyCode")) {
        currencyCode = json["currencyCode"].asString();
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListMarketBookRequest::toJson() const {
    Json::Value json;
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        };
    }
    if (priceProjection.isValid()) {
        json["priceProjection"] = priceProjection.toJson();
    }
    if (orderProjection.isValid()) {
        json["orderProjection"] = orderProjection.getValue();
    }
    if (matchProjection.isValid()) {
        json["matchProjection"] = matchProjection.getValue();
    }
    if (currencyCode != "") {
        json["currencyCode"] = currencyCode;
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListMarketBookRequest::isValid() const {
    return marketIds.size() > 0;
}

const std::set<std::string>& ListMarketBookRequest::getMarketIds() const {
    return marketIds;
}
void ListMarketBookRequest::setMarketIds(const std::set<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const PriceProjection& ListMarketBookRequest::getPriceProjection() const {
    return priceProjection;
}
void ListMarketBookRequest::setPriceProjection(const PriceProjection& priceProjection) {
    this->priceProjection = priceProjection;
}

const OrderProjection& ListMarketBookRequest::getOrderProjection() const {
    return orderProjection;
}
void ListMarketBookRequest::setOrderProjection(const OrderProjection& orderProjection) {
    this->orderProjection = orderProjection;
}

const MatchProjection& ListMarketBookRequest::getMatchProjection() const {
    return matchProjection;
}
void ListMarketBookRequest::setMatchProjection(const MatchProjection& matchProjection) {
    this->matchProjection = matchProjection;
}

const std::string& ListMarketBookRequest::getCurrencyCode() const {
    return currencyCode;
}
void ListMarketBookRequest::setCurrencyCode(const std::string& currencyCode) {
    this->currencyCode = currencyCode;
}

const std::string& ListMarketBookRequest::getLocale() const {
    return locale;
}
void ListMarketBookRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



