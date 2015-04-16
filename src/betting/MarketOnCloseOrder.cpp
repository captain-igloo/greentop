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
    Json::Value json;
    if (liability >= 0) {
        json["liability"] = liability;
    }
    return json;
}

bool MarketOnCloseOrder::isValid() const {
    return liability >= 0;
}

const double MarketOnCloseOrder::getLiability() const {
    return liability;
}
void MarketOnCloseOrder::setLiability(const double liability) {
    this->liability = liability;
}


}



