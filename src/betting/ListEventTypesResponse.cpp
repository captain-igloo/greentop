#include "greentop/betting/ListEventTypesResponse.h"

namespace greentop {
ListEventTypesResponse::ListEventTypesResponse() {
}

ListEventTypesResponse::ListEventTypesResponse(const std::vector<EventTypeResult>& eventTypeResults) :
    eventTypeResults(eventTypeResults) {
}

void ListEventTypesResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            EventTypeResult eventTypeResult;
            eventTypeResult.fromJson(json[i]);
            eventTypeResults.push_back(eventTypeResult);
        };
    }
}

Json::Value ListEventTypesResponse::toJson() const {
    Json::Value json;
    if (eventTypeResults.size() > 0) {
        for (unsigned i = 0; i < eventTypeResults.size(); ++i) {
            json.append(eventTypeResults[i].toJson());
        };
    }
    return json;
}

bool ListEventTypesResponse::isValid() const {
    return eventTypeResults.size() > 0;
}

const std::vector<EventTypeResult>& ListEventTypesResponse::getEventTypeResults() const {
    return eventTypeResults;
}
void ListEventTypesResponse::setEventTypeResults(const std::vector<EventTypeResult>& eventTypeResults) {
    this->eventTypeResults = eventTypeResults;
}


}



