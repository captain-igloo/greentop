/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/Order.h"

namespace greentop {

Order::Order() {
}

Order::Order(const std::string& betId,
    const OrderType& orderType,
    const OrderStatus& status,
    const PersistenceType& persistenceType,
    const Side& side,
    const Optional<double>& price,
    const Optional<double>& size,
    const Optional<double>& bspLiability,
    const std::tm& placedDate,
    const Optional<double>& avgPriceMatched,
    const Optional<double>& sizeMatched,
    const Optional<double>& sizeRemaining,
    const Optional<double>& sizeLapsed,
    const Optional<double>& sizeCancelled,
    const Optional<double>& sizeVoided,
    const std::string& customerOrderRef,
    const std::string& customerStrategyRef) :
    betId(betId),
    orderType(orderType),
    status(status),
    persistenceType(persistenceType),
    side(side),
    price(price),
    size(size),
    bspLiability(bspLiability),
    placedDate(placedDate),
    avgPriceMatched(avgPriceMatched),
    sizeMatched(sizeMatched),
    sizeRemaining(sizeRemaining),
    sizeLapsed(sizeLapsed),
    sizeCancelled(sizeCancelled),
    sizeVoided(sizeVoided),
    customerOrderRef(customerOrderRef),
    customerStrategyRef(customerStrategyRef) {
}

void Order::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("orderType")) {
        orderType = json["orderType"].asString();
    }
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("persistenceType")) {
        persistenceType = json["persistenceType"].asString();
    }
    if (json.isMember("side")) {
        side = json["side"].asString();
    }
    if (json.isMember("price")) {
        price = json["price"].asDouble();
    }
    if (json.isMember("size")) {
        size = json["size"].asDouble();
    }
    if (json.isMember("bspLiability")) {
        bspLiability = json["bspLiability"].asDouble();
    }
    if (json.isMember("placedDate")) {
        strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
    }
    if (json.isMember("avgPriceMatched")) {
        avgPriceMatched = json["avgPriceMatched"].asDouble();
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
    if (json.isMember("customerOrderRef")) {
        customerOrderRef = json["customerOrderRef"].asString();
    }
    if (json.isMember("customerStrategyRef")) {
        customerStrategyRef = json["customerStrategyRef"].asString();
    }
}

Json::Value Order::toJson() const {
    Json::Value json(Json::objectValue);
    if (betId != "") {
        json["betId"] = betId;
    }
    if (orderType.isValid()) {
        json["orderType"] = orderType.getValue();
    }
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (price.isValid()) {
        json["price"] = price.toJson();
    }
    if (size.isValid()) {
        json["size"] = size.toJson();
    }
    if (bspLiability.isValid()) {
        json["bspLiability"] = bspLiability.toJson();
    }
    if (placedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
        json["placedDate"] = std::string(buffer);
    }
    if (avgPriceMatched.isValid()) {
        json["avgPriceMatched"] = avgPriceMatched.toJson();
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
    if (customerOrderRef != "") {
        json["customerOrderRef"] = customerOrderRef;
    }
    if (customerStrategyRef != "") {
        json["customerStrategyRef"] = customerStrategyRef;
    }
    return json;
}

bool Order::isValid() const {
    return betId != "" && orderType.isValid() && status.isValid() && persistenceType.isValid() && side.isValid() && price.isValid() && size.isValid() && bspLiability.isValid() && placedDate.tm_year > 0;
}

const std::string& Order::getBetId() const {
    return betId;
}
void Order::setBetId(const std::string& betId) {
    this->betId = betId;
}

const OrderType& Order::getOrderType() const {
    return orderType;
}
void Order::setOrderType(const OrderType& orderType) {
    this->orderType = orderType;
}

const OrderStatus& Order::getStatus() const {
    return status;
}
void Order::setStatus(const OrderStatus& status) {
    this->status = status;
}

const PersistenceType& Order::getPersistenceType() const {
    return persistenceType;
}
void Order::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}

const Side& Order::getSide() const {
    return side;
}
void Order::setSide(const Side& side) {
    this->side = side;
}

const Optional<double>& Order::getPrice() const {
    return price;
}
void Order::setPrice(const Optional<double>& price) {
    this->price = price;
}

const Optional<double>& Order::getSize() const {
    return size;
}
void Order::setSize(const Optional<double>& size) {
    this->size = size;
}

const Optional<double>& Order::getBspLiability() const {
    return bspLiability;
}
void Order::setBspLiability(const Optional<double>& bspLiability) {
    this->bspLiability = bspLiability;
}

const std::tm& Order::getPlacedDate() const {
    return placedDate;
}
void Order::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const Optional<double>& Order::getAvgPriceMatched() const {
    return avgPriceMatched;
}
void Order::setAvgPriceMatched(const Optional<double>& avgPriceMatched) {
    this->avgPriceMatched = avgPriceMatched;
}

const Optional<double>& Order::getSizeMatched() const {
    return sizeMatched;
}
void Order::setSizeMatched(const Optional<double>& sizeMatched) {
    this->sizeMatched = sizeMatched;
}

const Optional<double>& Order::getSizeRemaining() const {
    return sizeRemaining;
}
void Order::setSizeRemaining(const Optional<double>& sizeRemaining) {
    this->sizeRemaining = sizeRemaining;
}

const Optional<double>& Order::getSizeLapsed() const {
    return sizeLapsed;
}
void Order::setSizeLapsed(const Optional<double>& sizeLapsed) {
    this->sizeLapsed = sizeLapsed;
}

const Optional<double>& Order::getSizeCancelled() const {
    return sizeCancelled;
}
void Order::setSizeCancelled(const Optional<double>& sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}

const Optional<double>& Order::getSizeVoided() const {
    return sizeVoided;
}
void Order::setSizeVoided(const Optional<double>& sizeVoided) {
    this->sizeVoided = sizeVoided;
}

const std::string& Order::getCustomerOrderRef() const {
    return customerOrderRef;
}
void Order::setCustomerOrderRef(const std::string& customerOrderRef) {
    this->customerOrderRef = customerOrderRef;
}

const std::string& Order::getCustomerStrategyRef() const {
    return customerStrategyRef;
}
void Order::setCustomerStrategyRef(const std::string& customerStrategyRef) {
    this->customerStrategyRef = customerStrategyRef;
}


}



