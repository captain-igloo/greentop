/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UnblockMarketGroupRequest.h"

namespace greentop {
namespace sport {

UnblockMarketGroupRequest::UnblockMarketGroupRequest() {
}

UnblockMarketGroupRequest::UnblockMarketGroupRequest(const MarketGroup& marketGroup) :
    marketGroup(marketGroup) {
}

void UnblockMarketGroupRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroup")) {
        marketGroup.fromJson(json["marketGroup"]);
    }
}

Json::Value UnblockMarketGroupRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroup.isValid()) {
        json["marketGroup"] = marketGroup.toJson();
    }
    return json;
}

bool UnblockMarketGroupRequest::isValid() const {
    return marketGroup.isValid();
}

const MarketGroup& UnblockMarketGroupRequest::getMarketGroup() const {
    return marketGroup;
}
void UnblockMarketGroupRequest::setMarketGroup(const MarketGroup& marketGroup) {
    this->marketGroup = marketGroup;
}


}
}
