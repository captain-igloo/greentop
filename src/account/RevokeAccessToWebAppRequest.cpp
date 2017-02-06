/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/RevokeAccessToWebAppRequest.h"

namespace greentop {

RevokeAccessToWebAppRequest::RevokeAccessToWebAppRequest() {
}

RevokeAccessToWebAppRequest::RevokeAccessToWebAppRequest(const int64_t vendorId) :
    vendorId(vendorId) {
}

void RevokeAccessToWebAppRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorId")) {
        vendorId = json["vendorId"].asInt64();
    }
}

Json::Value RevokeAccessToWebAppRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorId.isValid()) {
        json["vendorId"] = vendorId.toJson();
    }
    return json;
}

bool RevokeAccessToWebAppRequest::isValid() const {
    return vendorId.isValid();
}

const int64_t RevokeAccessToWebAppRequest::getVendorId() const {
    return vendorId;
}
void RevokeAccessToWebAppRequest::setVendorId(const int64_t vendorId) {
    this->vendorId = vendorId;
}


}



