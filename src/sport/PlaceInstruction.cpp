/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PlaceInstruction.h"

namespace greentop {
namespace sport {

PlaceInstruction::PlaceInstruction() {
}

PlaceInstruction::PlaceInstruction(const OrderType& orderType,
    const Optional<int64_t>& selectionId,
    const Optional<double>& handicap,
    const Side& side,
    const LimitOrder& limitOrder,
    const LimitOnCloseOrder& limitOnCloseOrder,
    const MarketOnCloseOrder& marketOnCloseOrder,
    const std::string& customerOrderRef) :
    orderType(orderType),
    selectionId(selectionId),
    handicap(handicap),
    side(side),
    limitOrder(limitOrder),
    limitOnCloseOrder(limitOnCloseOrder),
    marketOnCloseOrder(marketOnCloseOrder),
    customerOrderRef(customerOrderRef) {
}

void PlaceInstruction::fromJson(const Json::Value& json) {
    if (json.isMember("orderType")) {
        orderType = json["orderType"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
    if (json.isMember("side")) {
        side = json["side"].asString();
    }
    if (json.isMember("limitOrder")) {
        limitOrder.fromJson(json["limitOrder"]);
    }
    if (json.isMember("limitOnCloseOrder")) {
        limitOnCloseOrder.fromJson(json["limitOnCloseOrder"]);
    }
    if (json.isMember("marketOnCloseOrder")) {
        marketOnCloseOrder.fromJson(json["marketOnCloseOrder"]);
    }
    if (json.isMember("customerOrderRef")) {
        customerOrderRef = json["customerOrderRef"].asString();
    }
}

Json::Value PlaceInstruction::toJson() const {
    Json::Value json(Json::objectValue);
    if (orderType.isValid()) {
        json["orderType"] = orderType.getValue();
    }
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
    }
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (limitOrder.isValid()) {
        json["limitOrder"] = limitOrder.toJson();
    }
    if (limitOnCloseOrder.isValid()) {
        json["limitOnCloseOrder"] = limitOnCloseOrder.toJson();
    }
    if (marketOnCloseOrder.isValid()) {
        json["marketOnCloseOrder"] = marketOnCloseOrder.toJson();
    }
    if (customerOrderRef != "") {
        json["customerOrderRef"] = customerOrderRef;
    }
    return json;
}

bool PlaceInstruction::isValid() const {
    return orderType.isValid() && selectionId.isValid() && side.isValid();
}

const OrderType& PlaceInstruction::getOrderType() const {
    return orderType;
}
void PlaceInstruction::setOrderType(const OrderType& orderType) {
    this->orderType = orderType;
}

const Optional<int64_t>& PlaceInstruction::getSelectionId() const {
    return selectionId;
}
void PlaceInstruction::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& PlaceInstruction::getHandicap() const {
    return handicap;
}
void PlaceInstruction::setHandicap(const Optional<double>& handicap) {
    this->handicap = handicap;
}

const Side& PlaceInstruction::getSide() const {
    return side;
}
void PlaceInstruction::setSide(const Side& side) {
    this->side = side;
}

const LimitOrder& PlaceInstruction::getLimitOrder() const {
    return limitOrder;
}
void PlaceInstruction::setLimitOrder(const LimitOrder& limitOrder) {
    this->limitOrder = limitOrder;
}

const LimitOnCloseOrder& PlaceInstruction::getLimitOnCloseOrder() const {
    return limitOnCloseOrder;
}
void PlaceInstruction::setLimitOnCloseOrder(const LimitOnCloseOrder& limitOnCloseOrder) {
    this->limitOnCloseOrder = limitOnCloseOrder;
}

const MarketOnCloseOrder& PlaceInstruction::getMarketOnCloseOrder() const {
    return marketOnCloseOrder;
}
void PlaceInstruction::setMarketOnCloseOrder(const MarketOnCloseOrder& marketOnCloseOrder) {
    this->marketOnCloseOrder = marketOnCloseOrder;
}

const std::string& PlaceInstruction::getCustomerOrderRef() const {
    return customerOrderRef;
}
void PlaceInstruction::setCustomerOrderRef(const std::string& customerOrderRef) {
    this->customerOrderRef = customerOrderRef;
}


}
}
