/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/MarketOnCloseOrder.h"

namespace greentop {
MarketOnCloseOrder::MarketOnCloseOrder()  : liability(-1){
}

MarketOnCloseOrder::MarketOnCloseOrder(const double liability) :
    liability(liability) {
}

void MarketOnCloseOrder::fromJson(const Json::Value& json) {
    if (json.isMember("liability")) {
        liability = json["liability"].asDouble();
    }
}

Json::Value MarketOnCloseOrder::toJson() const {
    Json::Value json(Json::objectValue);
    json["liability"] = liability;
    return json;
}

bool MarketOnCloseOrder::isValid() const {
    return true;
}

const double MarketOnCloseOrder::getLiability() const {
    return liability;
}
void MarketOnCloseOrder::setLiability(const double liability) {
    this->liability = liability;
}


}



