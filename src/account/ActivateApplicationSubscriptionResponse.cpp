/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ActivateApplicationSubscriptionResponse.h"

namespace greentop {
namespace account {

ActivateApplicationSubscriptionResponse::ActivateApplicationSubscriptionResponse() {
}

ActivateApplicationSubscriptionResponse::ActivateApplicationSubscriptionResponse(const Status& response) :
    response(response) {
}

void ActivateApplicationSubscriptionResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value ActivateApplicationSubscriptionResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response.isValid()) {
        json = response.getValue();
    }
    return json;
}

bool ActivateApplicationSubscriptionResponse::isValid() const {
    return response.isValid();
}

const Status& ActivateApplicationSubscriptionResponse::getResponse() const {
    return response;
}
void ActivateApplicationSubscriptionResponse::setResponse(const Status& response) {
    this->response = response;
}


}
}
