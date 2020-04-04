/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListExposureLimitsForMarketGroupsResponse.h"

namespace greentop {
namespace sport {

ListExposureLimitsForMarketGroupsResponse::ListExposureLimitsForMarketGroupsResponse() {
}

ListExposureLimitsForMarketGroupsResponse::ListExposureLimitsForMarketGroupsResponse(const std::vector<ExposureLimitsForMarketGroups>& exposureLimitsForMarketGroupses) :
    exposureLimitsForMarketGroupses(exposureLimitsForMarketGroupses) {
}

void ListExposureLimitsForMarketGroupsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            ExposureLimitsForMarketGroups exposureLimitsForMarketGroupse;
            exposureLimitsForMarketGroupse.fromJson(json[i]);
            exposureLimitsForMarketGroupses.push_back(exposureLimitsForMarketGroupse);
        }
    }
}

Json::Value ListExposureLimitsForMarketGroupsResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (exposureLimitsForMarketGroupses.size() > 0) {
        for (unsigned i = 0; i < exposureLimitsForMarketGroupses.size(); ++i) {
            json.append(exposureLimitsForMarketGroupses[i].toJson());
        }
    }
    return json;
}

bool ListExposureLimitsForMarketGroupsResponse::isValid() const {
    return exposureLimitsForMarketGroupses.size() > 0;
}

const std::vector<ExposureLimitsForMarketGroups>& ListExposureLimitsForMarketGroupsResponse::getExposureLimitsForMarketGroupses() const {
    return exposureLimitsForMarketGroupses;
}
void ListExposureLimitsForMarketGroupsResponse::setExposureLimitsForMarketGroupses(const std::vector<ExposureLimitsForMarketGroups>& exposureLimitsForMarketGroupses) {
    this->exposureLimitsForMarketGroupses = exposureLimitsForMarketGroupses;
}


}
}
