/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/CurrentOrderSummary.h"

namespace greentop {

CurrentOrderSummary::CurrentOrderSummary() : selectionId(-1), handicap(-1), bspLiability(-1) {
}

CurrentOrderSummary::CurrentOrderSummary(const std::string& betId,
    const std::string& marketId,
    const int64_t selectionId,
    const double handicap,
    const PriceSize& priceSize,
    const double bspLiability,
    const Side& side,
    const std::string& status,
    const PersistenceType& persistenceType,
    const OrderType& orderType,
    const std::tm& placedDate,
    const std::tm& matchedDate,
    const Optional<double>& averagePriceMatched,
    const Optional<double>& sizeMatched,
    const Optional<double>& sizeRemaining,
    const Optional<double>& sizeLapsed,
    const Optional<double>& sizeCancelled,
    const Optional<double>& sizeVoided,
    const std::string& regulatorAuthCode,
    const std::string& regulatorCode) :
    betId(betId),
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap),
    priceSize(priceSize),
    bspLiability(bspLiability),
    side(side),
    status(status),
    persistenceType(persistenceType),
    orderType(orderType),
    placedDate(placedDate),
    matchedDate(matchedDate),
    averagePriceMatched(averagePriceMatched),
    sizeMatched(sizeMatched),
    sizeRemaining(sizeRemaining),
    sizeLapsed(sizeLapsed),
    sizeCancelled(sizeCancelled),
    sizeVoided(sizeVoided),
    regulatorAuthCode(regulatorAuthCode),
    regulatorCode(regulatorCode) {
}

void CurrentOrderSummary::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
    if (json.isMember("priceSize")) {
        priceSize.fromJson(json["priceSize"]);
    }
    if (json.isMember("bspLiability")) {
        bspLiability = json["bspLiability"].asDouble();
    }
    if (json.isMember("side")) {
        side = json["side"].asString();
    }
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("persistenceType")) {
        persistenceType = json["persistenceType"].asString();
    }
    if (json.isMember("orderType")) {
        orderType = json["orderType"].asString();
    }
    if (json.isMember("placedDate")) {
        strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
    }
    if (json.isMember("matchedDate")) {
        strptime(json["matchedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &matchedDate);
    }
    if (json.isMember("averagePriceMatched")) {
        averagePriceMatched = json["averagePriceMatched"].asDouble();
    }
    if (json.isMember("sizeMatched")) {
        sizeMatched = json["sizeMatched"].asDouble();
    }
    if (json.isMember("sizeRemaining")) {
        sizeRemaining = json["sizeRemaining"].asDouble();
    }
    if (json.isMember("sizeLapsed")) {
        sizeLapsed = json["sizeLapsed"].asDouble();
    }
    if (json.isMember("sizeCancelled")) {
        sizeCancelled = json["sizeCancelled"].asDouble();
    }
    if (json.isMember("sizeVoided")) {
        sizeVoided = json["sizeVoided"].asDouble();
    }
    if (json.isMember("regulatorAuthCode")) {
        regulatorAuthCode = json["regulatorAuthCode"].asString();
    }
    if (json.isMember("regulatorCode")) {
        regulatorCode = json["regulatorCode"].asString();
    }
}

Json::Value CurrentOrderSummary::toJson() const {
    Json::Value json(Json::objectValue);
    json["betId"] = betId;
    json["marketId"] = marketId;
    json["selectionId"] = selectionId;
    json["handicap"] = handicap;
    if (priceSize.isValid()) {
        json["priceSize"] = priceSize.toJson();
    }
    json["bspLiability"] = bspLiability;
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (status != "") {
        json["status"] = status;
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    if (orderType.isValid()) {
        json["orderType"] = orderType.getValue();
    }
    if (placedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
        json["placedDate"] = std::string(buffer);
    }
    if (matchedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &matchedDate);
        json["matchedDate"] = std::string(buffer);
    }
    if (averagePriceMatched.isValid()) {
        json["averagePriceMatched"] = averagePriceMatched.toJson();
    }
    if (sizeMatched.isValid()) {
        json["sizeMatched"] = sizeMatched.toJson();
    }
    if (sizeRemaining.isValid()) {
        json["sizeRemaining"] = sizeRemaining.toJson();
    }
    if (sizeLapsed.isValid()) {
        json["sizeLapsed"] = sizeLapsed.toJson();
    }
    if (sizeCancelled.isValid()) {
        json["sizeCancelled"] = sizeCancelled.toJson();
    }
    if (sizeVoided.isValid()) {
        json["sizeVoided"] = sizeVoided.toJson();
    }
    if (regulatorAuthCode != "") {
        json["regulatorAuthCode"] = regulatorAuthCode;
    }
    if (regulatorCode != "") {
        json["regulatorCode"] = regulatorCode;
    }
    return json;
}

bool CurrentOrderSummary::isValid() const {
    return priceSize.isValid() && side.isValid() && status != "" && persistenceType.isValid() && orderType.isValid() && placedDate.tm_year > 0 && matchedDate.tm_year > 0;
}

const std::string& CurrentOrderSummary::getBetId() const {
    return betId;
}
void CurrentOrderSummary::setBetId(const std::string& betId) {
    this->betId = betId;
}

const std::string& CurrentOrderSummary::getMarketId() const {
    return marketId;
}
void CurrentOrderSummary::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const int64_t CurrentOrderSummary::getSelectionId() const {
    return selectionId;
}
void CurrentOrderSummary::setSelectionId(const int64_t selectionId) {
    this->selectionId = selectionId;
}

const double CurrentOrderSummary::getHandicap() const {
    return handicap;
}
void CurrentOrderSummary::setHandicap(const double handicap) {
    this->handicap = handicap;
}

const PriceSize& CurrentOrderSummary::getPriceSize() const {
    return priceSize;
}
void CurrentOrderSummary::setPriceSize(const PriceSize& priceSize) {
    this->priceSize = priceSize;
}

const double CurrentOrderSummary::getBspLiability() const {
    return bspLiability;
}
void CurrentOrderSummary::setBspLiability(const double bspLiability) {
    this->bspLiability = bspLiability;
}

const Side& CurrentOrderSummary::getSide() const {
    return side;
}
void CurrentOrderSummary::setSide(const Side& side) {
    this->side = side;
}

const std::string& CurrentOrderSummary::getStatus() const {
    return status;
}
void CurrentOrderSummary::setStatus(const std::string& status) {
    this->status = status;
}

const PersistenceType& CurrentOrderSummary::getPersistenceType() const {
    return persistenceType;
}
void CurrentOrderSummary::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}

const OrderType& CurrentOrderSummary::getOrderType() const {
    return orderType;
}
void CurrentOrderSummary::setOrderType(const OrderType& orderType) {
    this->orderType = orderType;
}

const std::tm& CurrentOrderSummary::getPlacedDate() const {
    return placedDate;
}
void CurrentOrderSummary::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const std::tm& CurrentOrderSummary::getMatchedDate() const {
    return matchedDate;
}
void CurrentOrderSummary::setMatchedDate(const std::tm& matchedDate) {
    this->matchedDate = matchedDate;
}

const Optional<double>& CurrentOrderSummary::getAveragePriceMatched() const {
    return averagePriceMatched;
}
void CurrentOrderSummary::setAveragePriceMatched(const Optional<double>& averagePriceMatched) {
    this->averagePriceMatched = averagePriceMatched;
}

const Optional<double>& CurrentOrderSummary::getSizeMatched() const {
    return sizeMatched;
}
void CurrentOrderSummary::setSizeMatched(const Optional<double>& sizeMatched) {
    this->sizeMatched = sizeMatched;
}

const Optional<double>& CurrentOrderSummary::getSizeRemaining() const {
    return sizeRemaining;
}
void CurrentOrderSummary::setSizeRemaining(const Optional<double>& sizeRemaining) {
    this->sizeRemaining = sizeRemaining;
}

const Optional<double>& CurrentOrderSummary::getSizeLapsed() const {
    return sizeLapsed;
}
void CurrentOrderSummary::setSizeLapsed(const Optional<double>& sizeLapsed) {
    this->sizeLapsed = sizeLapsed;
}

const Optional<double>& CurrentOrderSummary::getSizeCancelled() const {
    return sizeCancelled;
}
void CurrentOrderSummary::setSizeCancelled(const Optional<double>& sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}

const Optional<double>& CurrentOrderSummary::getSizeVoided() const {
    return sizeVoided;
}
void CurrentOrderSummary::setSizeVoided(const Optional<double>& sizeVoided) {
    this->sizeVoided = sizeVoided;
}

const std::string& CurrentOrderSummary::getRegulatorAuthCode() const {
    return regulatorAuthCode;
}
void CurrentOrderSummary::setRegulatorAuthCode(const std::string& regulatorAuthCode) {
    this->regulatorAuthCode = regulatorAuthCode;
}

const std::string& CurrentOrderSummary::getRegulatorCode() const {
    return regulatorCode;
}
void CurrentOrderSummary::setRegulatorCode(const std::string& regulatorCode) {
    this->regulatorCode = regulatorCode;
}


}



