/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListRunnerBookRequest.h"

namespace greentop {
namespace sport {

ListRunnerBookRequest::ListRunnerBookRequest() {
}

ListRunnerBookRequest::ListRunnerBookRequest(const std::string& marketId,
    const Optional<int64_t>& selectionId,
    const Optional<double>& handicap,
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
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap),
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

void ListRunnerBookRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
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

Json::Value ListRunnerBookRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
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

bool ListRunnerBookRequest::isValid() const {
    return marketId != "" && selectionId.isValid();
}

const std::string& ListRunnerBookRequest::getMarketId() const {
    return marketId;
}
void ListRunnerBookRequest::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const Optional<int64_t>& ListRunnerBookRequest::getSelectionId() const {
    return selectionId;
}
void ListRunnerBookRequest::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& ListRunnerBookRequest::getHandicap() const {
    return handicap;
}
void ListRunnerBookRequest::setHandicap(const Optional<double>& handicap) {
    this->handicap = handicap;
}

const PriceProjection& ListRunnerBookRequest::getPriceProjection() const {
    return priceProjection;
}
void ListRunnerBookRequest::setPriceProjection(const PriceProjection& priceProjection) {
    this->priceProjection = priceProjection;
}

const OrderProjection& ListRunnerBookRequest::getOrderProjection() const {
    return orderProjection;
}
void ListRunnerBookRequest::setOrderProjection(const OrderProjection& orderProjection) {
    this->orderProjection = orderProjection;
}

const MatchProjection& ListRunnerBookRequest::getMatchProjection() const {
    return matchProjection;
}
void ListRunnerBookRequest::setMatchProjection(const MatchProjection& matchProjection) {
    this->matchProjection = matchProjection;
}

const Optional<bool>& ListRunnerBookRequest::getIncludeOverallPosition() const {
    return includeOverallPosition;
}
void ListRunnerBookRequest::setIncludeOverallPosition(const Optional<bool>& includeOverallPosition) {
    this->includeOverallPosition = includeOverallPosition;
}

const Optional<bool>& ListRunnerBookRequest::getPartitionMatchedByStrategyRef() const {
    return partitionMatchedByStrategyRef;
}
void ListRunnerBookRequest::setPartitionMatchedByStrategyRef(const Optional<bool>& partitionMatchedByStrategyRef) {
    this->partitionMatchedByStrategyRef = partitionMatchedByStrategyRef;
}

const std::set<std::string>& ListRunnerBookRequest::getCustomerStrategyRefs() const {
    return customerStrategyRefs;
}
void ListRunnerBookRequest::setCustomerStrategyRefs(const std::set<std::string>& customerStrategyRefs) {
    this->customerStrategyRefs = customerStrategyRefs;
}

const std::string& ListRunnerBookRequest::getCurrencyCode() const {
    return currencyCode;
}
void ListRunnerBookRequest::setCurrencyCode(const std::string& currencyCode) {
    this->currencyCode = currencyCode;
}

const std::string& ListRunnerBookRequest::getLocale() const {
    return locale;
}
void ListRunnerBookRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}

const std::tm& ListRunnerBookRequest::getMatchedSince() const {
    return matchedSince;
}
void ListRunnerBookRequest::setMatchedSince(const std::tm& matchedSince) {
    this->matchedSince = matchedSince;
}

const std::set<std::string>& ListRunnerBookRequest::getBetIds() const {
    return betIds;
}
void ListRunnerBookRequest::setBetIds(const std::set<std::string>& betIds) {
    this->betIds = betIds;
}


}
}
