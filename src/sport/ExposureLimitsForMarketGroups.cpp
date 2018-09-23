/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ExposureLimitsForMarketGroups.h"

namespace greentop {

ExposureLimitsForMarketGroups::ExposureLimitsForMarketGroups() {
}

ExposureLimitsForMarketGroups::ExposureLimitsForMarketGroups(const MarketGroupType& marketGroupType,
    const ExposureLimit& defaultLimit,
    const std::vector<MarketGroupExposureLimit>& groupLimits,
    const std::vector<MarketGroupId>& blockedMarketGroups) :
    marketGroupType(marketGroupType),
    defaultLimit(defaultLimit),
    groupLimits(groupLimits),
    blockedMarketGroups(blockedMarketGroups) {
}

void ExposureLimitsForMarketGroups::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroupType")) {
        marketGroupType = json["marketGroupType"].asString();
    }
    if (json.isMember("defaultLimit")) {
        defaultLimit.fromJson(json["defaultLimit"]);
    }
    if (json.isMember("groupLimits")) {
        for (unsigned i = 0; i < json["groupLimits"].size(); ++i) {
            MarketGroupExposureLimit groupLimit;
            groupLimit.fromJson(json["groupLimits"][i]);
            groupLimits.push_back(groupLimit);
        }
    }
    if (json.isMember("blockedMarketGroups")) {
        for (unsigned i = 0; i < json["blockedMarketGroups"].size(); ++i) {
            MarketGroupId blockedMarketGroup;
            blockedMarketGroup.fromJson(json["blockedMarketGroups"][i]);
            blockedMarketGroups.push_back(blockedMarketGroup);
        }
    }
}

Json::Value ExposureLimitsForMarketGroups::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroupType.isValid()) {
        json["marketGroupType"] = marketGroupType.getValue();
    }
    if (defaultLimit.isValid()) {
        json["defaultLimit"] = defaultLimit.toJson();
    }
    if (groupLimits.size() > 0) {
        for (unsigned i = 0; i < groupLimits.size(); ++i) {
            json["groupLimits"].append(groupLimits[i].toJson());
        }
    }
    if (blockedMarketGroups.size() > 0) {
        for (unsigned i = 0; i < blockedMarketGroups.size(); ++i) {
            json["blockedMarketGroups"].append(blockedMarketGroups[i].toJson());
        }
    }
    return json;
}

bool ExposureLimitsForMarketGroups::isValid() const {
    return marketGroupType.isValid();
}

const MarketGroupType& ExposureLimitsForMarketGroups::getMarketGroupType() const {
    return marketGroupType;
}
void ExposureLimitsForMarketGroups::setMarketGroupType(const MarketGroupType& marketGroupType) {
    this->marketGroupType = marketGroupType;
}

const ExposureLimit& ExposureLimitsForMarketGroups::getDefaultLimit() const {
    return defaultLimit;
}
void ExposureLimitsForMarketGroups::setDefaultLimit(const ExposureLimit& defaultLimit) {
    this->defaultLimit = defaultLimit;
}

const std::vector<MarketGroupExposureLimit>& ExposureLimitsForMarketGroups::getGroupLimits() const {
    return groupLimits;
}
void ExposureLimitsForMarketGroups::setGroupLimits(const std::vector<MarketGroupExposureLimit>& groupLimits) {
    this->groupLimits = groupLimits;
}

const std::vector<MarketGroupId>& ExposureLimitsForMarketGroups::getBlockedMarketGroups() const {
    return blockedMarketGroups;
}
void ExposureLimitsForMarketGroups::setBlockedMarketGroups(const std::vector<MarketGroupId>& blockedMarketGroups) {
    this->blockedMarketGroups = blockedMarketGroups;
}


}



