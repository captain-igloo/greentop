/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/CancelApplicationSubscriptionResponse.h"

namespace greentop {

CancelApplicationSubscriptionResponse::CancelApplicationSubscriptionResponse() {
}

CancelApplicationSubscriptionResponse::CancelApplicationSubscriptionResponse(const Status& response) :
    response(response) {
}

void CancelApplicationSubscriptionResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value CancelApplicationSubscriptionResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response.isValid()) {
        json = response.getValue();
    }
    return json;
}

bool CancelApplicationSubscriptionResponse::isValid() const {
    return response.isValid();
}

const Status& CancelApplicationSubscriptionResponse::getResponse() const {
    return response;
}
void CancelApplicationSubscriptionResponse::setResponse(const Status& response) {
    this->response = response;
}


}



