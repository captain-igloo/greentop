/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/TimeRangeResult.h"

namespace greentop {
namespace sport {


TimeRangeResult::TimeRangeResult(const common::TimeRange& timeRange,
    const Optional<int32_t>& marketCount) :
    timeRange(timeRange),
    marketCount(marketCount) {
}

void TimeRangeResult::fromJson(const Json::Value& json) {
    if (json.isMember("timeRange")) {
        timeRange.fromJson(json["timeRange"]);
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asInt();
    }
}

Json::Value TimeRangeResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (timeRange.isValid()) {
        json["timeRange"] = timeRange.toJson();
    }
    if (marketCount.isValid()) {
        json["marketCount"] = marketCount.toJson();
    }
    return json;
}

bool TimeRangeResult::isValid() const {
    return true;
}

const common::TimeRange& TimeRangeResult::getTimeRange() const {
    return timeRange;
}
void TimeRangeResult::setTimeRange(const common::TimeRange& timeRange) {
    this->timeRange = timeRange;
}

const Optional<int32_t>& TimeRangeResult::getMarketCount() const {
    return marketCount;
}
void TimeRangeResult::setMarketCount(const Optional<int32_t>& marketCount) {
    this->marketCount = marketCount;
}


}
}
