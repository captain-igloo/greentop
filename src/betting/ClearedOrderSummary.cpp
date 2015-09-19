/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ClearedOrderSummary.h"

namespace greentop {

ClearedOrderSummary::ClearedOrderSummary(const std::string& eventTypeId,
    const std::string& eventId,
    const std::string& marketId,
    const uint64_t selectionId,
    const double handicap,
    const std::string& betId,
    const std::tm& placedDate,
    const PersistenceType& persistenceType,
    const OrderType& orderType,
    const Side& side,
    const ItemDescription& itemDescription,
    const double priceRequested,
    const std::tm& settledDate,
    const uint64_t betCount,
    const double commission,
    const double priceMatched,
    const BoolJsonMember& priceReduced,
    const double sizeSettled,
    const double profit,
    const double sizeCancelled) :
    eventTypeId(eventTypeId),
    eventId(eventId),
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap),
    betId(betId),
    placedDate(placedDate),
    persistenceType(persistenceType),
    orderType(orderType),
    side(side),
    itemDescription(itemDescription),
    priceRequested(priceRequested),
    settledDate(settledDate),
    betCount(betCount),
    commission(commission),
    priceMatched(priceMatched),
    priceReduced(priceReduced),
    sizeSettled(sizeSettled),
    profit(profit),
    sizeCancelled(sizeCancelled) {
}

void ClearedOrderSummary::fromJson(const Json::Value& json) {
    if (json.isMember("eventTypeId")) {
        eventTypeId = json["eventTypeId"].asString();
    }
    if (json.isMember("eventId")) {
        eventId = json["eventId"].asString();
    }
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asUInt64();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("placedDate")) {
        strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
    }
    if (json.isMember("persistenceType")) {
        persistenceType = json["persistenceType"].asString();
    }
    if (json.isMember("orderType")) {
        orderType = json["orderType"].asString();
    }
    if (json.isMember("side")) {
        side = json["side"].asString();
    }
    if (json.isMember("itemDescription")) {
        itemDescription.fromJson(json["itemDescription"]);
    }
    if (json.isMember("priceRequested")) {
        priceRequested = json["priceRequested"].asDouble();
    }
    if (json.isMember("settledDate")) {
        strptime(json["settledDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &settledDate);
    }
    if (json.isMember("betCount")) {
        betCount = json["betCount"].asUInt64();
    }
    if (json.isMember("commission")) {
        commission = json["commission"].asDouble();
    }
    if (json.isMember("priceMatched")) {
        priceMatched = json["priceMatched"].asDouble();
    }
    if (json.isMember("priceReduced")) {
        priceReduced.fromJson(json["priceReduced"]);
    }
    if (json.isMember("sizeSettled")) {
        sizeSettled = json["sizeSettled"].asDouble();
    }
    if (json.isMember("profit")) {
        profit = json["profit"].asDouble();
    }
    if (json.isMember("sizeCancelled")) {
        sizeCancelled = json["sizeCancelled"].asDouble();
    }
}

Json::Value ClearedOrderSummary::toJson() const {
    Json::Value json(Json::objectValue);
    if (eventTypeId != "") {
        json["eventTypeId"] = eventTypeId;
    }
    if (eventId != "") {
        json["eventId"] = eventId;
    }
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (selectionId > 0) {
        json["selectionId"] = selectionId;
    }
    if (handicap >= 0) {
        json["handicap"] = handicap;
    }
    if (betId != "") {
        json["betId"] = betId;
    }
    if (placedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
        json["placedDate"] = std::string(buffer);
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    if (orderType.isValid()) {
        json["orderType"] = orderType.getValue();
    }
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (itemDescription.isValid()) {
        json["itemDescription"] = itemDescription.toJson();
    }
    if (priceRequested >= 0) {
        json["priceRequested"] = priceRequested;
    }
    if (settledDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &settledDate);
        json["settledDate"] = std::string(buffer);
    }
    if (betCount > 0) {
        json["betCount"] = betCount;
    }
    if (commission >= 0) {
        json["commission"] = commission;
    }
    if (priceMatched >= 0) {
        json["priceMatched"] = priceMatched;
    }
    if (priceReduced.isValid()) {
        json["priceReduced"] = priceReduced.toJson();
    }
    if (sizeSettled >= 0) {
        json["sizeSettled"] = sizeSettled;
    }
    if (profit >= 0) {
        json["profit"] = profit;
    }
    if (sizeCancelled >= 0) {
        json["sizeCancelled"] = sizeCancelled;
    }
    return json;
}

bool ClearedOrderSummary::isValid() const {
    return true;
}

const std::string& ClearedOrderSummary::getEventTypeId() const {
    return eventTypeId;
}
void ClearedOrderSummary::setEventTypeId(const std::string& eventTypeId) {
    this->eventTypeId = eventTypeId;
}

const std::string& ClearedOrderSummary::getEventId() const {
    return eventId;
}
void ClearedOrderSummary::setEventId(const std::string& eventId) {
    this->eventId = eventId;
}

const std::string& ClearedOrderSummary::getMarketId() const {
    return marketId;
}
void ClearedOrderSummary::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const uint64_t ClearedOrderSummary::getSelectionId() const {
    return selectionId;
}
void ClearedOrderSummary::setSelectionId(const uint64_t selectionId) {
    this->selectionId = selectionId;
}

const double ClearedOrderSummary::getHandicap() const {
    return handicap;
}
void ClearedOrderSummary::setHandicap(const double handicap) {
    this->handicap = handicap;
}

const std::string& ClearedOrderSummary::getBetId() const {
    return betId;
}
void ClearedOrderSummary::setBetId(const std::string& betId) {
    this->betId = betId;
}

const std::tm& ClearedOrderSummary::getPlacedDate() const {
    return placedDate;
}
void ClearedOrderSummary::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const PersistenceType& ClearedOrderSummary::getPersistenceType() const {
    return persistenceType;
}
void ClearedOrderSummary::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}

const OrderType& ClearedOrderSummary::getOrderType() const {
    return orderType;
}
void ClearedOrderSummary::setOrderType(const OrderType& orderType) {
    this->orderType = orderType;
}

const Side& ClearedOrderSummary::getSide() const {
    return side;
}
void ClearedOrderSummary::setSide(const Side& side) {
    this->side = side;
}

const ItemDescription& ClearedOrderSummary::getItemDescription() const {
    return itemDescription;
}
void ClearedOrderSummary::setItemDescription(const ItemDescription& itemDescription) {
    this->itemDescription = itemDescription;
}

const double ClearedOrderSummary::getPriceRequested() const {
    return priceRequested;
}
void ClearedOrderSummary::setPriceRequested(const double priceRequested) {
    this->priceRequested = priceRequested;
}

const std::tm& ClearedOrderSummary::getSettledDate() const {
    return settledDate;
}
void ClearedOrderSummary::setSettledDate(const std::tm& settledDate) {
    this->settledDate = settledDate;
}

const uint64_t ClearedOrderSummary::getBetCount() const {
    return betCount;
}
void ClearedOrderSummary::setBetCount(const uint64_t betCount) {
    this->betCount = betCount;
}

const double ClearedOrderSummary::getCommission() const {
    return commission;
}
void ClearedOrderSummary::setCommission(const double commission) {
    this->commission = commission;
}

const double ClearedOrderSummary::getPriceMatched() const {
    return priceMatched;
}
void ClearedOrderSummary::setPriceMatched(const double priceMatched) {
    this->priceMatched = priceMatched;
}

const BoolJsonMember& ClearedOrderSummary::getPriceReduced() const {
    return priceReduced;
}
void ClearedOrderSummary::setPriceReduced(const BoolJsonMember& priceReduced) {
    this->priceReduced = priceReduced;
}

const double ClearedOrderSummary::getSizeSettled() const {
    return sizeSettled;
}
void ClearedOrderSummary::setSizeSettled(const double sizeSettled) {
    this->sizeSettled = sizeSettled;
}

const double ClearedOrderSummary::getProfit() const {
    return profit;
}
void ClearedOrderSummary::setProfit(const double profit) {
    this->profit = profit;
}

const double ClearedOrderSummary::getSizeCancelled() const {
    return sizeCancelled;
}
void ClearedOrderSummary::setSizeCancelled(const double sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}


}



