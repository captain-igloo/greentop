/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/AddExposureReuseEnabledEventsResponse.h"

namespace greentop {

AddExposureReuseEnabledEventsResponse::AddExposureReuseEnabledEventsResponse() {
}

AddExposureReuseEnabledEventsResponse::AddExposureReuseEnabledEventsResponse(const std::string& response) :
    response(response) {
}

void AddExposureReuseEnabledEventsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value AddExposureReuseEnabledEventsResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool AddExposureReuseEnabledEventsResponse::isValid() const {
    return response != "";
}

const std::string& AddExposureReuseEnabledEventsResponse::getResponse() const {
    return response;
}
void AddExposureReuseEnabledEventsResponse::setResponse(const std::string& response) {
    this->response = response;
}


}



