/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RemoveDefaultExposureLimitForMarketGroupsRequest.h"

namespace greentop {
namespace sport {

RemoveDefaultExposureLimitForMarketGroupsRequest::RemoveDefaultExposureLimitForMarketGroupsRequest() {
}

RemoveDefaultExposureLimitForMarketGroupsRequest::RemoveDefaultExposureLimitForMarketGroupsRequest(const MarketGroupType& marketGroupType) :
    marketGroupType(marketGroupType) {
}

void RemoveDefaultExposureLimitForMarketGroupsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroupType")) {
        marketGroupType = json["marketGroupType"].asString();
    }
}

Json::Value RemoveDefaultExposureLimitForMarketGroupsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroupType.isValid()) {
        json["marketGroupType"] = marketGroupType.getValue();
    }
    return json;
}

bool RemoveDefaultExposureLimitForMarketGroupsRequest::isValid() const {
    return marketGroupType.isValid();
}

const MarketGroupType& RemoveDefaultExposureLimitForMarketGroupsRequest::getMarketGroupType() const {
    return marketGroupType;
}
void RemoveDefaultExposureLimitForMarketGroupsRequest::setMarketGroupType(const MarketGroupType& marketGroupType) {
    this->marketGroupType = marketGroupType;
}


}
}
