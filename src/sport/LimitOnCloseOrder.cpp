/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/LimitOnCloseOrder.h"

namespace greentop {
namespace sport {

LimitOnCloseOrder::LimitOnCloseOrder() {
}

LimitOnCloseOrder::LimitOnCloseOrder(const Optional<double>& liability,
    const Optional<double>& price) :
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
    if (liability.isValid()) {
        json["liability"] = liability.toJson();
    }
    if (price.isValid()) {
        json["price"] = price.toJson();
    }
    return json;
}

bool LimitOnCloseOrder::isValid() const {
    return liability.isValid() && price.isValid();
}

const Optional<double>& LimitOnCloseOrder::getLiability() const {
    return liability;
}
void LimitOnCloseOrder::setLiability(const Optional<double>& liability) {
    this->liability = liability;
}

const Optional<double>& LimitOnCloseOrder::getPrice() const {
    return price;
}
void LimitOnCloseOrder::setPrice(const Optional<double>& price) {
    this->price = price;
}


}
}
