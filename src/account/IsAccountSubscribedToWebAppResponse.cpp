/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/IsAccountSubscribedToWebAppResponse.h"

namespace greentop {

IsAccountSubscribedToWebAppResponse::IsAccountSubscribedToWebAppResponse() {
}

IsAccountSubscribedToWebAppResponse::IsAccountSubscribedToWebAppResponse(const Optional<bool>& response) :
    response(response) {
}

void IsAccountSubscribedToWebAppResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asBool();
    }
}

Json::Value IsAccountSubscribedToWebAppResponse::toJson() const {
    Json::Value json(Json::booleanValue);
    if (response.isValid()) {
        json = response.toJson();
    }
    return json;
}

bool IsAccountSubscribedToWebAppResponse::isValid() const {
    return response.isValid();
}

const Optional<bool>& IsAccountSubscribedToWebAppResponse::getResponse() const {
    return response;
}
void IsAccountSubscribedToWebAppResponse::setResponse(const Optional<bool>& response) {
    this->response = response;
}


}



