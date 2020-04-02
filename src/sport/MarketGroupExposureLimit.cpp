/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketGroupExposureLimit.h"

namespace greentop {
namespace sport {

MarketGroupExposureLimit::MarketGroupExposureLimit() {
}

MarketGroupExposureLimit::MarketGroupExposureLimit(const MarketGroupId& groupId,
    const ExposureLimit& limit) :
    groupId(groupId),
    limit(limit) {
}

void MarketGroupExposureLimit::fromJson(const Json::Value& json) {
    if (json.isMember("groupId")) {
        groupId.fromJson(json["groupId"]);
    }
    if (json.isMember("limit")) {
        limit.fromJson(json["limit"]);
    }
}

Json::Value MarketGroupExposureLimit::toJson() const {
    Json::Value json(Json::objectValue);
    if (groupId.isValid()) {
        json["groupId"] = groupId.toJson();
    }
    if (limit.isValid()) {
        json["limit"] = limit.toJson();
    }
    return json;
}

bool MarketGroupExposureLimit::isValid() const {
    return groupId.isValid() && limit.isValid();
}

const MarketGroupId& MarketGroupExposureLimit::getGroupId() const {
    return groupId;
}
void MarketGroupExposureLimit::setGroupId(const MarketGroupId& groupId) {
    this->groupId = groupId;
}

const ExposureLimit& MarketGroupExposureLimit::getLimit() const {
    return limit;
}
void MarketGroupExposureLimit::setLimit(const ExposureLimit& limit) {
    this->limit = limit;
}


}
}
