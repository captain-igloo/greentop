/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PriceSize.h"

namespace greentop {

PriceSize::PriceSize() : price(-1), size(-1) {
}

PriceSize::PriceSize(const double price,
    const double size) :
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
    json["price"] = price;
    json["size"] = size;
    return json;
}

bool PriceSize::isValid() const {
    return true;
}

const double PriceSize::getPrice() const {
    return price;
}
void PriceSize::setPrice(const double price) {
    this->price = price;
}

const double PriceSize::getSize() const {
    return size;
}
void PriceSize::setSize(const double size) {
    this->size = size;
}


}



