/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RemoveExposureLimitForMarketGroupRequest.h"

namespace greentop {
namespace sport {

RemoveExposureLimitForMarketGroupRequest::RemoveExposureLimitForMarketGroupRequest() {
}

RemoveExposureLimitForMarketGroupRequest::RemoveExposureLimitForMarketGroupRequest(const MarketGroup& marketGroup) :
    marketGroup(marketGroup) {
}

void RemoveExposureLimitForMarketGroupRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroup")) {
        marketGroup.fromJson(json["marketGroup"]);
    }
}

Json::Value RemoveExposureLimitForMarketGroupRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroup.isValid()) {
        json["marketGroup"] = marketGroup.toJson();
    }
    return json;
}

bool RemoveExposureLimitForMarketGroupRequest::isValid() const {
    return marketGroup.isValid();
}

const MarketGroup& RemoveExposureLimitForMarketGroupRequest::getMarketGroup() const {
    return marketGroup;
}
void RemoveExposureLimitForMarketGroupRequest::setMarketGroup(const MarketGroup& marketGroup) {
    this->marketGroup = marketGroup;
}


}
}
