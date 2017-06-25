/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/IsAccountSubscribedToWebAppRequest.h"

namespace greentop {

IsAccountSubscribedToWebAppRequest::IsAccountSubscribedToWebAppRequest() {
}

IsAccountSubscribedToWebAppRequest::IsAccountSubscribedToWebAppRequest(const std::string& vendorId) :
    vendorId(vendorId) {
}

void IsAccountSubscribedToWebAppRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorId")) {
        vendorId = json["vendorId"].asString();
    }
}

Json::Value IsAccountSubscribedToWebAppRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorId != "") {
        json["vendorId"] = vendorId;
    }
    return json;
}

bool IsAccountSubscribedToWebAppRequest::isValid() const {
    return vendorId != "";
}

const std::string& IsAccountSubscribedToWebAppRequest::getVendorId() const {
    return vendorId;
}
void IsAccountSubscribedToWebAppRequest::setVendorId(const std::string& vendorId) {
    this->vendorId = vendorId;
}


}



