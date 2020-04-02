/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetVendorDetailsRequest.h"

namespace greentop {
namespace account {

GetVendorDetailsRequest::GetVendorDetailsRequest() {
}

GetVendorDetailsRequest::GetVendorDetailsRequest(const std::string& vendorId) :
    vendorId(vendorId) {
}

void GetVendorDetailsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorId")) {
        vendorId = json["vendorId"].asString();
    }
}

Json::Value GetVendorDetailsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorId != "") {
        json["vendorId"] = vendorId;
    }
    return json;
}

bool GetVendorDetailsRequest::isValid() const {
    return vendorId != "";
}

const std::string& GetVendorDetailsRequest::getVendorId() const {
    return vendorId;
}
void GetVendorDetailsRequest::setVendorId(const std::string& vendorId) {
    this->vendorId = vendorId;
}


}
}
