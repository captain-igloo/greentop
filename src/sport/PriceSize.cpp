/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PriceSize.h"

namespace greentop {

PriceSize::PriceSize() {
}

PriceSize::PriceSize(const Optional<double>& price,
    const Optional<double>& size) :
    price(price),
    size(size) {
}

void PriceSize::fromJson(const Json::Value& json) {
    if (json.isMember("price")) {
        price = json["price"].asDouble();
    }
    if (json.isMember("size")) {
        size = json["size"].asDouble();
    }
}

Json::Value PriceSize::toJson() const {
    Json::Value json(Json::objectValue);
    if (price.isValid()) {
        json["price"] = price.toJson();
    }
    if (size.isValid()) {
        json["size"] = size.toJson();
    }
    return json;
}

bool PriceSize::isValid() const {
    return price.isValid() && size.isValid();
}

const Optional<double>& PriceSize::getPrice() const {
    return price;
}
void PriceSize::setPrice(const Optional<double>& price) {
    this->price = price;
}

const Optional<double>& PriceSize::getSize() const {
    return size;
}
void PriceSize::setSize(const Optional<double>& size) {
    this->size = size;
}


}



