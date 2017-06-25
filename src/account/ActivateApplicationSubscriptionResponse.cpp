/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ActivateApplicationSubscriptionResponse.h"

namespace greentop {

ActivateApplicationSubscriptionResponse::ActivateApplicationSubscriptionResponse() {
}

ActivateApplicationSubscriptionResponse::ActivateApplicationSubscriptionResponse(const Status& status) :
    status(status) {
}

void ActivateApplicationSubscriptionResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        status = json["status"].asString();
    }
}

Json::Value ActivateApplicationSubscriptionResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    return json;
}

bool ActivateApplicationSubscriptionResponse::isValid() const {
    return status.isValid();
}

const Status& ActivateApplicationSubscriptionResponse::getStatus() const {
    return status;
}
void ActivateApplicationSubscriptionResponse::setStatus(const Status& status) {
    this->status = status;
}


}



