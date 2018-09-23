/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/AddExposureReuseEnabledEventsRequest.h"

namespace greentop {

AddExposureReuseEnabledEventsRequest::AddExposureReuseEnabledEventsRequest() {
}

AddExposureReuseEnabledEventsRequest::AddExposureReuseEnabledEventsRequest(const std::vector<int64_t>& eventIds) :
    eventIds(eventIds) {
}

void AddExposureReuseEnabledEventsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("eventIds")) {
        for (unsigned i = 0; i < json["eventIds"].size(); ++i) {
            eventIds.push_back(json["eventIds"][i].asInt64());
        }
    }
}

Json::Value AddExposureReuseEnabledEventsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (eventIds.size() > 0) {
        for (unsigned i = 0; i < eventIds.size(); ++i) {
            json["eventIds"].append(eventIds[i]);
        }
    }
    return json;
}

bool AddExposureReuseEnabledEventsRequest::isValid() const {
    return eventIds.size() > 0;
}

const std::vector<int64_t>& AddExposureReuseEnabledEventsRequest::getEventIds() const {
    return eventIds;
}
void AddExposureReuseEnabledEventsRequest::setEventIds(const std::vector<int64_t>& eventIds) {
    this->eventIds = eventIds;
}


}



