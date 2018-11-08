/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/GetExposureReuseEnabledEventsResponse.h"

namespace greentop {

GetExposureReuseEnabledEventsResponse::GetExposureReuseEnabledEventsResponse() {
}

GetExposureReuseEnabledEventsResponse::GetExposureReuseEnabledEventsResponse(const std::vector<int64_t>& response) :
    response(response) {
}

void GetExposureReuseEnabledEventsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            response.push_back(json[i].asInt64());
        }
    }
}

Json::Value GetExposureReuseEnabledEventsResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (response.size() > 0) {
        for (unsigned i = 0; i < response.size(); ++i) {
            json.append(Json::Value::Int64(response[i]));
        }
    }
    return json;
}

bool GetExposureReuseEnabledEventsResponse::isValid() const {
    return response.size() > 0;
}

const std::vector<int64_t>& GetExposureReuseEnabledEventsResponse::getResponse() const {
    return response;
}
void GetExposureReuseEnabledEventsResponse::setResponse(const std::vector<int64_t>& response) {
    this->response = response;
}


}



