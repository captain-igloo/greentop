/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/LimitOrder.h"

namespace greentop {
LimitOrder::LimitOrder()  : size(-1), price(-1){
}

LimitOrder::LimitOrder(const double size,
    const double price,
    const PersistenceType& persistenceType) :
    size(size),
    price(price),
    persistenceType(persistenceType) {
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
}

Json::Value LimitOrder::toJson() const {
    Json::Value json(Json::objectValue);
    if (size >= 0) {
        json["size"] = size;
    }
    if (price >= 0) {
        json["price"] = price;
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    return json;
}

bool LimitOrder::isValid() const {
    return size >= 0 && price >= 0 && persistenceType.isValid();
}

const double LimitOrder::getSize() const {
    return size;
}
void LimitOrder::setSize(const double size) {
    this->size = size;
}

const double LimitOrder::getPrice() const {
    return price;
}
void LimitOrder::setPrice(const double price) {
    this->price = price;
}

const PersistenceType& LimitOrder::getPersistenceType() const {
    return persistenceType;
}
void LimitOrder::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}


}



