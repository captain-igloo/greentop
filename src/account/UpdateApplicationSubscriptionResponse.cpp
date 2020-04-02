/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/UpdateApplicationSubscriptionResponse.h"

namespace greentop {
namespace account {

UpdateApplicationSubscriptionResponse::UpdateApplicationSubscriptionResponse() {
}

UpdateApplicationSubscriptionResponse::UpdateApplicationSubscriptionResponse(const std::string& response) :
    response(response) {
}

void UpdateApplicationSubscriptionResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value UpdateApplicationSubscriptionResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool UpdateApplicationSubscriptionResponse::isValid() const {
    return response != "";
}

const std::string& UpdateApplicationSubscriptionResponse::getResponse() const {
    return response;
}
void UpdateApplicationSubscriptionResponse::setResponse(const std::string& response) {
    this->response = response;
}


}
}
