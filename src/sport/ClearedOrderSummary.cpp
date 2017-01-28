/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ClearedOrderSummary.h"

namespace greentop {


ClearedOrderSummary::ClearedOrderSummary(const std::string& eventTypeId,
    const std::string& eventId,
    const std::string& marketId,
    const Optional<int64_t>& selectionId,
    const Optional<double>& handicap,
    const std::string& betId,
    const std::tm& placedDate,
    const PersistenceType& persistenceType,
    const OrderType& orderType,
    const Side& side,
    const ItemDescription& itemDescription,
    const std::string& betOutcome,
    const Optional<double>& priceRequested,
    const std::tm& settledDate,
    const std::tm& lastMatchedDate,
    const Optional<int32_t>& betCount,
    const Optional<double>& commission,
    const Optional<double>& priceMatched,
    const Optional<bool>& priceReduced,
    const Optional<double>& sizeSettled,
    const Optional<double>& profit,
    const Optional<double>& sizeCancelled,
    const std::string& customerOrderRef,
    const std::string& customerStrategyRef) :
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
    betOutcome(betOutcome),
    priceRequested(priceRequested),
    settledDate(settledDate),
    lastMatchedDate(lastMatchedDate),
    betCount(betCount),
    commission(commission),
    priceMatched(priceMatched),
    priceReduced(priceReduced),
    sizeSettled(sizeSettled),
    profit(profit),
    sizeCancelled(sizeCancelled),
    customerOrderRef(customerOrderRef),
    customerStrategyRef(customerStrategyRef) {
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
        selectionId = json["selectionId"].asInt64();
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
    if (json.isMember("betOutcome")) {
        betOutcome = json["betOutcome"].asString();
    }
    if (json.isMember("priceRequested")) {
        priceRequested = json["priceRequested"].asDouble();
    }
    if (json.isMember("settledDate")) {
        strptime(json["settledDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &settledDate);
    }
    if (json.isMember("lastMatchedDate")) {
        strptime(json["lastMatchedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &lastMatchedDate);
    }
    if (json.isMember("betCount")) {
        betCount = json["betCount"].asInt();
    }
    if (json.isMember("commission")) {
        commission = json["commission"].asDouble();
    }
    if (json.isMember("priceMatched")) {
        priceMatched = json["priceMatched"].asDouble();
    }
    if (json.isMember("priceReduced")) {
        priceReduced = json["priceReduced"].asBool();
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
    if (json.isMember("customerOrderRef")) {
        customerOrderRef = json["customerOrderRef"].asString();
    }
    if (json.isMember("customerStrategyRef")) {
        customerStrategyRef = json["customerStrategyRef"].asString();
    }
}

Json::Value ClearedOrderSummary::toJson() const {
    Json::Value json(Json::objectValue);
    json["eventTypeId"] = eventTypeId;
    json["eventId"] = eventId;
    json["marketId"] = marketId;
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
    }
    json["betId"] = betId;
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
    if (betOutcome != "") {
        json["betOutcome"] = betOutcome;
    }
    if (priceRequested.isValid()) {
        json["priceRequested"] = priceRequested.toJson();
    }
    if (settledDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &settledDate);
        json["settledDate"] = std::string(buffer);
    }
    if (lastMatchedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &lastMatchedDate);
        json["lastMatchedDate"] = std::string(buffer);
    }
    if (betCount.isValid()) {
        json["betCount"] = betCount.toJson();
    }
    if (commission.isValid()) {
        json["commission"] = commission.toJson();
    }
    if (priceMatched.isValid()) {
        json["priceMatched"] = priceMatched.toJson();
    }
    if (priceReduced.isValid()) {
        json["priceReduced"] = priceReduced.toJson();
    }
    if (sizeSettled.isValid()) {
        json["sizeSettled"] = sizeSettled.toJson();
    }
    if (profit.isValid()) {
        json["profit"] = profit.toJson();
    }
    if (sizeCancelled.isValid()) {
        json["sizeCancelled"] = sizeCancelled.toJson();
    }
    if (customerOrderRef != "") {
        json["customerOrderRef"] = customerOrderRef;
    }
    if (customerStrategyRef != "") {
        json["customerStrategyRef"] = customerStrategyRef;
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

const Optional<int64_t>& ClearedOrderSummary::getSelectionId() const {
    return selectionId;
}
void ClearedOrderSummary::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& ClearedOrderSummary::getHandicap() const {
    return handicap;
}
void ClearedOrderSummary::setHandicap(const Optional<double>& handicap) {
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

const std::string& ClearedOrderSummary::getBetOutcome() const {
    return betOutcome;
}
void ClearedOrderSummary::setBetOutcome(const std::string& betOutcome) {
    this->betOutcome = betOutcome;
}

const Optional<double>& ClearedOrderSummary::getPriceRequested() const {
    return priceRequested;
}
void ClearedOrderSummary::setPriceRequested(const Optional<double>& priceRequested) {
    this->priceRequested = priceRequested;
}

const std::tm& ClearedOrderSummary::getSettledDate() const {
    return settledDate;
}
void ClearedOrderSummary::setSettledDate(const std::tm& settledDate) {
    this->settledDate = settledDate;
}

const std::tm& ClearedOrderSummary::getLastMatchedDate() const {
    return lastMatchedDate;
}
void ClearedOrderSummary::setLastMatchedDate(const std::tm& lastMatchedDate) {
    this->lastMatchedDate = lastMatchedDate;
}

const Optional<int32_t>& ClearedOrderSummary::getBetCount() const {
    return betCount;
}
void ClearedOrderSummary::setBetCount(const Optional<int32_t>& betCount) {
    this->betCount = betCount;
}

const Optional<double>& ClearedOrderSummary::getCommission() const {
    return commission;
}
void ClearedOrderSummary::setCommission(const Optional<double>& commission) {
    this->commission = commission;
}

const Optional<double>& ClearedOrderSummary::getPriceMatched() const {
    return priceMatched;
}
void ClearedOrderSummary::setPriceMatched(const Optional<double>& priceMatched) {
    this->priceMatched = priceMatched;
}

const Optional<bool>& ClearedOrderSummary::getPriceReduced() const {
    return priceReduced;
}
void ClearedOrderSummary::setPriceReduced(const Optional<bool>& priceReduced) {
    this->priceReduced = priceReduced;
}

const Optional<double>& ClearedOrderSummary::getSizeSettled() const {
    return sizeSettled;
}
void ClearedOrderSummary::setSizeSettled(const Optional<double>& sizeSettled) {
    this->sizeSettled = sizeSettled;
}

const Optional<double>& ClearedOrderSummary::getProfit() const {
    return profit;
}
void ClearedOrderSummary::setProfit(const Optional<double>& profit) {
    this->profit = profit;
}

const Optional<double>& ClearedOrderSummary::getSizeCancelled() const {
    return sizeCancelled;
}
void ClearedOrderSummary::setSizeCancelled(const Optional<double>& sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}

const std::string& ClearedOrderSummary::getCustomerOrderRef() const {
    return customerOrderRef;
}
void ClearedOrderSummary::setCustomerOrderRef(const std::string& customerOrderRef) {
    this->customerOrderRef = customerOrderRef;
}

const std::string& ClearedOrderSummary::getCustomerStrategyRef() const {
    return customerStrategyRef;
}
void ClearedOrderSummary::setCustomerStrategyRef(const std::string& customerStrategyRef) {
    this->customerStrategyRef = customerStrategyRef;
}


}



