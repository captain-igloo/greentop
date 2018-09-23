/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/SetExposureLimitForMarketGroupRequest.h"

namespace greentop {

SetExposureLimitForMarketGroupRequest::SetExposureLimitForMarketGroupRequest() {
}

SetExposureLimitForMarketGroupRequest::SetExposureLimitForMarketGroupRequest(const MarketGroup& marketGroup,
    const ExposureLimit& limit) :
    marketGroup(marketGroup),
    limit(limit) {
}

void SetExposureLimitForMarketGroupRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroup")) {
        marketGroup.fromJson(json["marketGroup"]);
    }
    if (json.isMember("limit")) {
        limit.fromJson(json["limit"]);
    }
}

Json::Value SetExposureLimitForMarketGroupRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroup.isValid()) {
        json["marketGroup"] = marketGroup.toJson();
    }
    if (limit.isValid()) {
        json["limit"] = limit.toJson();
    }
    return json;
}

bool SetExposureLimitForMarketGroupRequest::isValid() const {
    return marketGroup.isValid() && limit.isValid();
}

const MarketGroup& SetExposureLimitForMarketGroupRequest::getMarketGroup() const {
    return marketGroup;
}
void SetExposureLimitForMarketGroupRequest::setMarketGroup(const MarketGroup& marketGroup) {
    this->marketGroup = marketGroup;
}

const ExposureLimit& SetExposureLimitForMarketGroupRequest::getLimit() const {
    return limit;
}
void SetExposureLimitForMarketGroupRequest::setLimit(const ExposureLimit& limit) {
    this->limit = limit;
}


}



