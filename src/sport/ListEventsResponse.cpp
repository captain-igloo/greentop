/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListEventsResponse.h"

namespace greentop {

ListEventsResponse::ListEventsResponse() {
}

ListEventsResponse::ListEventsResponse(const std::vector<EventResult>& eventResults) :
    eventResults(eventResults) {
}

void ListEventsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            EventResult eventResult;
            eventResult.fromJson(json[i]);
            eventResults.push_back(eventResult);
        }
    }
}

Json::Value ListEventsResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (eventResults.size() > 0) {
        for (unsigned i = 0; i < eventResults.size(); ++i) {
            json.append(eventResults[i].toJson());
        }
    }
    return json;
}

bool ListEventsResponse::isValid() const {
    return eventResults.size() > 0;
}

const std::vector<EventResult>& ListEventsResponse::getEventResults() const {
    return eventResults;
}
void ListEventsResponse::setEventResults(const std::vector<EventResult>& eventResults) {
    this->eventResults = eventResults;
}


}



