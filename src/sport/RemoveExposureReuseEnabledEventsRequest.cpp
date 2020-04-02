/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RemoveExposureReuseEnabledEventsRequest.h"

namespace greentop {
namespace sport {

RemoveExposureReuseEnabledEventsRequest::RemoveExposureReuseEnabledEventsRequest() {
}

RemoveExposureReuseEnabledEventsRequest::RemoveExposureReuseEnabledEventsRequest(const std::vector<int64_t>& eventIds) :
    eventIds(eventIds) {
}

void RemoveExposureReuseEnabledEventsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("eventIds")) {
        for (unsigned i = 0; i < json["eventIds"].size(); ++i) {
            eventIds.push_back(json["eventIds"][i].asInt64());
        }
    }
}

Json::Value RemoveExposureReuseEnabledEventsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (eventIds.size() > 0) {
        for (unsigned i = 0; i < eventIds.size(); ++i) {
            json["eventIds"].append(Json::Value::Int64(eventIds[i]));
        }
    }
    return json;
}

bool RemoveExposureReuseEnabledEventsRequest::isValid() const {
    return eventIds.size() > 0;
}

const std::vector<int64_t>& RemoveExposureReuseEnabledEventsRequest::getEventIds() const {
    return eventIds;
}
void RemoveExposureReuseEnabledEventsRequest::setEventIds(const std::vector<int64_t>& eventIds) {
    this->eventIds = eventIds;
}


}
}
