/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/RevokeAccessToWebAppResponse.h"

namespace greentop {
namespace account {

RevokeAccessToWebAppResponse::RevokeAccessToWebAppResponse() {
}

RevokeAccessToWebAppResponse::RevokeAccessToWebAppResponse(const Status& response) :
    response(response) {
}

void RevokeAccessToWebAppResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value RevokeAccessToWebAppResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response.isValid()) {
        json = response.getValue();
    }
    return json;
}

bool RevokeAccessToWebAppResponse::isValid() const {
    return response.isValid();
}

const Status& RevokeAccessToWebAppResponse::getResponse() const {
    return response;
}
void RevokeAccessToWebAppResponse::setResponse(const Status& response) {
    this->response = response;
}


}
}
