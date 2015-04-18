/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ListTimeRangesResponse.h"

namespace greentop {
ListTimeRangesResponse::ListTimeRangesResponse() {
}

ListTimeRangesResponse::ListTimeRangesResponse(const std::vector<TimeRangeResult>& timeRangeResults) :
    timeRangeResults(timeRangeResults) {
}

void ListTimeRangesResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            TimeRangeResult timeRangeResult;
            timeRangeResult.fromJson(json[i]);
            timeRangeResults.push_back(timeRangeResult);
        };
    }
}

Json::Value ListTimeRangesResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (timeRangeResults.size() > 0) {
        for (unsigned i = 0; i < timeRangeResults.size(); ++i) {
            json.append(timeRangeResults[i].toJson());
        };
    }
    return json;
}

bool ListTimeRangesResponse::isValid() const {
    return timeRangeResults.size() > 0;
}

const std::vector<TimeRangeResult>& ListTimeRangesResponse::getTimeRangeResults() const {
    return timeRangeResults;
}
void ListTimeRangesResponse::setTimeRangeResults(const std::vector<TimeRangeResult>& timeRangeResults) {
    this->timeRangeResults = timeRangeResults;
}


}



