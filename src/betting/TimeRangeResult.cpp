#include "greentop/betting/TimeRangeResult.h"

namespace greentop {

TimeRangeResult::TimeRangeResult(const TimeRange& timeRange,
    const uint64_t marketCount) :
    timeRange(timeRange),
    marketCount(marketCount) {
}

void TimeRangeResult::fromJson(const Json::Value& json) {
    if (json.isMember("timeRange")) {
        timeRange.fromJson(json["timeRange"]);
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asUInt();
    }
}

Json::Value TimeRangeResult::toJson() const {
    Json::Value json;
    if (timeRange.isValid()) {
        json["timeRange"] = timeRange.toJson();
    }
    if (marketCount >= 0) {
        json["marketCount"] = marketCount;
    }
    return json;
}

bool TimeRangeResult::isValid() const {
    return true;
}

const TimeRange& TimeRangeResult::getTimeRange() const {
    return timeRange;
}
void TimeRangeResult::setTimeRange(const TimeRange& timeRange) {
    this->timeRange = timeRange;
}

const uint64_t TimeRangeResult::getMarketCount() const {
    return marketCount;
}
void TimeRangeResult::setMarketCount(const uint64_t marketCount) {
    this->marketCount = marketCount;
}


}



