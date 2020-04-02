/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/RevokeAccessToWebAppRequest.h"

namespace greentop {
namespace account {

RevokeAccessToWebAppRequest::RevokeAccessToWebAppRequest() {
}

RevokeAccessToWebAppRequest::RevokeAccessToWebAppRequest(const Optional<int64_t>& vendorId) :
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

const Optional<int64_t>& RevokeAccessToWebAppRequest::getVendorId() const {
    return vendorId;
}
void RevokeAccessToWebAppRequest::setVendorId(const Optional<int64_t>& vendorId) {
    this->vendorId = vendorId;
}


}
}
