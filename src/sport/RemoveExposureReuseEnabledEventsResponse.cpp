/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RemoveExposureReuseEnabledEventsResponse.h"

namespace greentop {

RemoveExposureReuseEnabledEventsResponse::RemoveExposureReuseEnabledEventsResponse() {
}

RemoveExposureReuseEnabledEventsResponse::RemoveExposureReuseEnabledEventsResponse(const std::string& response) :
    response(response) {
}

void RemoveExposureReuseEnabledEventsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value RemoveExposureReuseEnabledEventsResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool RemoveExposureReuseEnabledEventsResponse::isValid() const {
    return response != "";
}

const std::string& RemoveExposureReuseEnabledEventsResponse::getResponse() const {
    return response;
}
void RemoveExposureReuseEnabledEventsResponse::setResponse(const std::string& response) {
    this->response = response;
}


}



