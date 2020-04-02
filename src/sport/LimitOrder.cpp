/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/LimitOrder.h"

namespace greentop {
namespace sport {


LimitOrder::LimitOrder(const Optional<double>& size,
    const Optional<double>& price,
    const PersistenceType& persistenceType,
    const TimeInForce& timeInForce,
    const Optional<double>& minFillSize,
    const BetTargetType& betTargetType,
    const Optional<double>& betTargetSize) :
    size(size),
    price(price),
    persistenceType(persistenceType),
    timeInForce(timeInForce),
    minFillSize(minFillSize),
    betTargetType(betTargetType),
    betTargetSize(betTargetSize) {
}

void LimitOrder::fromJson(const Json::Value& json) {
    if (json.isMember("size")) {
        size = json["size"].asDouble();
    }
    if (json.isMember("price")) {
        price = json["price"].asDouble();
    }
    if (json.isMember("persistenceType")) {
        persistenceType = json["persistenceType"].asString();
    }
    if (json.isMember("timeInForce")) {
        timeInForce = json["timeInForce"].asString();
    }
    if (json.isMember("minFillSize")) {
        minFillSize = json["minFillSize"].asDouble();
    }
    if (json.isMember("betTargetType")) {
        betTargetType = json["betTargetType"].asString();
    }
    if (json.isMember("betTargetSize")) {
        betTargetSize = json["betTargetSize"].asDouble();
    }
}

Json::Value LimitOrder::toJson() const {
    Json::Value json(Json::objectValue);
    if (size.isValid()) {
        json["size"] = size.toJson();
    }
    if (price.isValid()) {
        json["price"] = price.toJson();
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    if (timeInForce.isValid()) {
        json["timeInForce"] = timeInForce.getValue();
    }
    if (minFillSize.isValid()) {
        json["minFillSize"] = minFillSize.toJson();
    }
    if (betTargetType.isValid()) {
        json["betTargetType"] = betTargetType.getValue();
    }
    if (betTargetSize.isValid()) {
        json["betTargetSize"] = betTargetSize.toJson();
    }
    return json;
}

bool LimitOrder::isValid() const {
    return price.isValid();
}

const Optional<double>& LimitOrder::getSize() const {
    return size;
}
void LimitOrder::setSize(const Optional<double>& size) {
    this->size = size;
}

const Optional<double>& LimitOrder::getPrice() const {
    return price;
}
void LimitOrder::setPrice(const Optional<double>& price) {
    this->price = price;
}

const PersistenceType& LimitOrder::getPersistenceType() const {
    return persistenceType;
}
void LimitOrder::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}

const TimeInForce& LimitOrder::getTimeInForce() const {
    return timeInForce;
}
void LimitOrder::setTimeInForce(const TimeInForce& timeInForce) {
    this->timeInForce = timeInForce;
}

const Optional<double>& LimitOrder::getMinFillSize() const {
    return minFillSize;
}
void LimitOrder::setMinFillSize(const Optional<double>& minFillSize) {
    this->minFillSize = minFillSize;
}

const BetTargetType& LimitOrder::getBetTargetType() const {
    return betTargetType;
}
void LimitOrder::setBetTargetType(const BetTargetType& betTargetType) {
    this->betTargetType = betTargetType;
}

const Optional<double>& LimitOrder::getBetTargetSize() const {
    return betTargetSize;
}
void LimitOrder::setBetTargetSize(const Optional<double>& betTargetSize) {
    this->betTargetSize = betTargetSize;
}


}
}
