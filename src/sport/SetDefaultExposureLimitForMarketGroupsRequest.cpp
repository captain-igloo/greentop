/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/SetDefaultExposureLimitForMarketGroupsRequest.h"

namespace greentop {
namespace sport {

SetDefaultExposureLimitForMarketGroupsRequest::SetDefaultExposureLimitForMarketGroupsRequest() {
}

SetDefaultExposureLimitForMarketGroupsRequest::SetDefaultExposureLimitForMarketGroupsRequest(const MarketGroupType& marketGroupType,
    const ExposureLimit& limit) :
    marketGroupType(marketGroupType),
    limit(limit) {
}

void SetDefaultExposureLimitForMarketGroupsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroupType")) {
        marketGroupType = json["marketGroupType"].asString();
    }
    if (json.isMember("limit")) {
        limit.fromJson(json["limit"]);
    }
}

Json::Value SetDefaultExposureLimitForMarketGroupsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroupType.isValid()) {
        json["marketGroupType"] = marketGroupType.getValue();
    }
    if (limit.isValid()) {
        json["limit"] = limit.toJson();
    }
    return json;
}

bool SetDefaultExposureLimitForMarketGroupsRequest::isValid() const {
    return marketGroupType.isValid() && limit.isValid();
}

const MarketGroupType& SetDefaultExposureLimitForMarketGroupsRequest::getMarketGroupType() const {
    return marketGroupType;
}
void SetDefaultExposureLimitForMarketGroupsRequest::setMarketGroupType(const MarketGroupType& marketGroupType) {
    this->marketGroupType = marketGroupType;
}

const ExposureLimit& SetDefaultExposureLimitForMarketGroupsRequest::getLimit() const {
    return limit;
}
void SetDefaultExposureLimitForMarketGroupsRequest::setLimit(const ExposureLimit& limit) {
    this->limit = limit;
}


}
}
