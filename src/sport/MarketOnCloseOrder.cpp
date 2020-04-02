/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketOnCloseOrder.h"

namespace greentop {
namespace sport {

MarketOnCloseOrder::MarketOnCloseOrder() {
}

MarketOnCloseOrder::MarketOnCloseOrder(const Optional<double>& liability) :
    liability(liability) {
}

void MarketOnCloseOrder::fromJson(const Json::Value& json) {
    if (json.isMember("liability")) {
        liability = json["liability"].asDouble();
    }
}

Json::Value MarketOnCloseOrder::toJson() const {
    Json::Value json(Json::objectValue);
    if (liability.isValid()) {
        json["liability"] = liability.toJson();
    }
    return json;
}

bool MarketOnCloseOrder::isValid() const {
    return liability.isValid();
}

const Optional<double>& MarketOnCloseOrder::getLiability() const {
    return liability;
}
void MarketOnCloseOrder::setLiability(const Optional<double>& liability) {
    this->liability = liability;
}


}
}
