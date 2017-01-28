/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/RevokeAccessToWebAppResponse.h"

namespace greentop {

RevokeAccessToWebAppResponse::RevokeAccessToWebAppResponse() {
}

RevokeAccessToWebAppResponse::RevokeAccessToWebAppResponse(const Status& status) :
    status(status) {
}

void RevokeAccessToWebAppResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("status")) {
            status = json["status"].asString();
;
        }
    }
}

Json::Value RevokeAccessToWebAppResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    return json;
}

bool RevokeAccessToWebAppResponse::isValid() const {
    return status.isValid();
}

const Status& RevokeAccessToWebAppResponse::getStatus() const {
    return status;
}
void RevokeAccessToWebAppResponse::setStatus(const Status& status) {
    this->status = status;
}


}



