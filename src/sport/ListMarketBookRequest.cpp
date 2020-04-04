/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketBookRequest.h"

namespace greentop {
namespace sport {

ListMarketBookRequest::ListMarketBookRequest() {
}

ListMarketBookRequest::ListMarketBookRequest(const std::vector<std::string>& marketIds,
    const PriceProjection& priceProjection,
    const OrderProjection& orderProjection,
    const MatchProjection& matchProjection,
    const Optional<bool>& includeOverallPosition,
    const Optional<bool>& partitionMatchedByStrategyRef,
    const std::set<std::string>& customerStrategyRefs,
    const std::string& currencyCode,
    const std::string& locale,
    const std::tm& matchedSince,
    const std::set<std::string>& betIds) :
    marketIds(marketIds),
    priceProjection(priceProjection),
    orderProjection(orderProjection),
    matchProjection(matchProjection),
    includeOverallPosition(includeOverallPosition),
    partitionMatchedByStrategyRef(partitionMatchedByStrategyRef),
    customerStrategyRefs(customerStrategyRefs),
    currencyCode(currencyCode),
    locale(locale),
    matchedSince(matchedSince),
    betIds(betIds) {
}

void ListMarketBookRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.push_back(json["marketIds"][i].asString());
        }
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
    if (json.isMember("includeOverallPosition")) {
        includeOverallPosition = json["includeOverallPosition"].asBool();
    }
    if (json.isMember("partitionMatchedByStrategyRef")) {
        partitionMatchedByStrategyRef = json["partitionMatchedByStrategyRef"].asBool();
    }
    if (json.isMember("customerStrategyRefs")) {
        for (unsigned i = 0; i < json["customerStrategyRefs"].size(); ++i) {
            customerStrategyRefs.insert(json["customerStrategyRefs"][i].asString());
        }
    }
    if (json.isMember("currencyCode")) {
        currencyCode = json["currencyCode"].asString();
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
    if (json.isMember("matchedSince")) {
        strptime(json["matchedSince"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &matchedSince);
    }
    if (json.isMember("betIds")) {
        for (unsigned i = 0; i < json["betIds"].size(); ++i) {
            betIds.insert(json["betIds"][i].asString());
        }
    }
}

Json::Value ListMarketBookRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketIds.size() > 0) {
        for (unsigned i = 0; i < marketIds.size(); ++i) {
            json["marketIds"].append(marketIds[i]);
        }
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
    if (includeOverallPosition.isValid()) {
        json["includeOverallPosition"] = includeOverallPosition.toJson();
    }
    if (partitionMatchedByStrategyRef.isValid()) {
        json["partitionMatchedByStrategyRef"] = partitionMatchedByStrategyRef.toJson();
    }
    if (customerStrategyRefs.size() > 0) {
        for (std::set<std::string>::const_iterator it = customerStrategyRefs.begin(); it != customerStrategyRefs.end(); ++it) {
            json["customerStrategyRefs"].append(*it);
        }
    }
    if (currencyCode != "") {
        json["currencyCode"] = currencyCode;
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    if (matchedSince.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &matchedSince);
        json["matchedSince"] = std::string(buffer);
    }
    if (betIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = betIds.begin(); it != betIds.end(); ++it) {
            json["betIds"].append(*it);
        }
    }
    return json;
}

bool ListMarketBookRequest::isValid() const {
    return marketIds.size() > 0;
}

const std::vector<std::string>& ListMarketBookRequest::getMarketIds() const {
    return marketIds;
}
void ListMarketBookRequest::setMarketIds(const std::vector<std::string>& marketIds) {
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

const Optional<bool>& ListMarketBookRequest::getIncludeOverallPosition() const {
    return includeOverallPosition;
}
void ListMarketBookRequest::setIncludeOverallPosition(const Optional<bool>& includeOverallPosition) {
    this->includeOverallPosition = includeOverallPosition;
}

const Optional<bool>& ListMarketBookRequest::getPartitionMatchedByStrategyRef() const {
    return partitionMatchedByStrategyRef;
}
void ListMarketBookRequest::setPartitionMatchedByStrategyRef(const Optional<bool>& partitionMatchedByStrategyRef) {
    this->partitionMatchedByStrategyRef = partitionMatchedByStrategyRef;
}

const std::set<std::string>& ListMarketBookRequest::getCustomerStrategyRefs() const {
    return customerStrategyRefs;
}
void ListMarketBookRequest::setCustomerStrategyRefs(const std::set<std::string>& customerStrategyRefs) {
    this->customerStrategyRefs = customerStrategyRefs;
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

const std::tm& ListMarketBookRequest::getMatchedSince() const {
    return matchedSince;
}
void ListMarketBookRequest::setMatchedSince(const std::tm& matchedSince) {
    this->matchedSince = matchedSince;
}

const std::set<std::string>& ListMarketBookRequest::getBetIds() const {
    return betIds;
}
void ListMarketBookRequest::setBetIds(const std::set<std::string>& betIds) {
    this->betIds = betIds;
}


}
}
