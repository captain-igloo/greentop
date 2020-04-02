/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListTimeRangesRequest.h"

namespace greentop {
namespace sport {

ListTimeRangesRequest::ListTimeRangesRequest() {
}

ListTimeRangesRequest::ListTimeRangesRequest(const MarketFilter& filter,
    const TimeGranularity& granularity) :
    filter(filter),
    granularity(granularity) {
}

void ListTimeRangesRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("granularity")) {
        granularity = json["granularity"].asString();
    }
}

Json::Value ListTimeRangesRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (granularity.isValid()) {
        json["granularity"] = granularity.getValue();
    }
    return json;
}

bool ListTimeRangesRequest::isValid() const {
    return filter.isValid() && granularity.isValid();
}

const MarketFilter& ListTimeRangesRequest::getFilter() const {
    return filter;
}
void ListTimeRangesRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const TimeGranularity& ListTimeRangesRequest::getGranularity() const {
    return granularity;
}
void ListTimeRangesRequest::setGranularity(const TimeGranularity& granularity) {
    this->granularity = granularity;
}


}
}
