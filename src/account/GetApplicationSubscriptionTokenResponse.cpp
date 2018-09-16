/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetApplicationSubscriptionTokenResponse.h"

namespace greentop {

GetApplicationSubscriptionTokenResponse::GetApplicationSubscriptionTokenResponse() {
}

GetApplicationSubscriptionTokenResponse::GetApplicationSubscriptionTokenResponse(const std::string& response) :
    response(response) {
}

void GetApplicationSubscriptionTokenResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value GetApplicationSubscriptionTokenResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool GetApplicationSubscriptionTokenResponse::isValid() const {
    return response != "";
}

const std::string& GetApplicationSubscriptionTokenResponse::getResponse() const {
    return response;
}
void GetApplicationSubscriptionTokenResponse::setResponse(const std::string& response) {
    this->response = response;
}


}



