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
    Json::Value json;
    if (liability >= 0) {
        json["liability"] = liability;
    }
    if (price >= 0) {
        json["price"] = price;
    }
    return json;
}

bool LimitOnCloseOrder::isValid() const {
    return liability >= 0 && price >= 0;
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



