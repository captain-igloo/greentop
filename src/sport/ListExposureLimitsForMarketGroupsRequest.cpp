/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListExposureLimitsForMarketGroupsRequest.h"

namespace greentop {
namespace sport {


ListExposureLimitsForMarketGroupsRequest::ListExposureLimitsForMarketGroupsRequest(const MarketGroupType& marketGroupTypeFilter,
    const std::vector<MarketGroup>& marketGroupFilter) :
    marketGroupTypeFilter(marketGroupTypeFilter),
    marketGroupFilter(marketGroupFilter) {
}

void ListExposureLimitsForMarketGroupsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketGroupTypeFilter")) {
        marketGroupTypeFilter = json["marketGroupTypeFilter"].asString();
    }
    if (json.isMember("marketGroupFilter")) {
        for (unsigned i = 0; i < json["marketGroupFilter"].size(); ++i) {
            MarketGroup marketGroup;
            marketGroup.fromJson(json["marketGroupFilter"][i]);
            marketGroupFilter.push_back(marketGroup);
        }
    }
}

Json::Value ListExposureLimitsForMarketGroupsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketGroupTypeFilter.isValid()) {
        json["marketGroupTypeFilter"] = marketGroupTypeFilter.getValue();
    }
    if (marketGroupFilter.size() > 0) {
        for (unsigned i = 0; i < marketGroupFilter.size(); ++i) {
            json["marketGroupFilter"].append(marketGroupFilter[i].toJson());
        }
    }
    return json;
}

bool ListExposureLimitsForMarketGroupsRequest::isValid() const {
    return true;
}

const MarketGroupType& ListExposureLimitsForMarketGroupsRequest::getMarketGroupTypeFilter() const {
    return marketGroupTypeFilter;
}
void ListExposureLimitsForMarketGroupsRequest::setMarketGroupTypeFilter(const MarketGroupType& marketGroupTypeFilter) {
    this->marketGroupTypeFilter = marketGroupTypeFilter;
}

const std::vector<MarketGroup>& ListExposureLimitsForMarketGroupsRequest::getMarketGroupFilter() const {
    return marketGroupFilter;
}
void ListExposureLimitsForMarketGroupsRequest::setMarketGroupFilter(const std::vector<MarketGroup>& marketGroupFilter) {
    this->marketGroupFilter = marketGroupFilter;
}


}
}
