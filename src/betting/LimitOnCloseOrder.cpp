/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/LimitOnCloseOrder.h"

namespace greentop {
LimitOnCloseOrder::LimitOnCloseOrder()  : liability(-1), price(-1){
}

LimitOnCloseOrder::LimitOnCloseOrder(const double liability,
    const double price) :
    liability(liability),
    price(price) {
}

void LimitOnCloseOrder::fromJson(const Json::Value& json) {
    if (json.isMember("liability")) {
        liability = json["liability"].asDouble();
    }
    if (json.isMember("price")) {
        price = json["price"].asDouble();
    }
}

Json::Value LimitOnCloseOrder::toJson() const {
    Json::Value json(Json::objectValue);
    json["liability"] = liability;
    json["price"] = price;
    return json;
}

bool LimitOnCloseOrder::isValid() const {
    return true && true;
}

const double LimitOnCloseOrder::getLiability() const {
    return liability;
}
void LimitOnCloseOrder::setLiability(const double liability) {
    this->liability = liability;
}

const double LimitOnCloseOrder::getPrice() const {
    return price;
}
void LimitOnCloseOrder::setPrice(const double price) {
    this->price = price;
}


}



