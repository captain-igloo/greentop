/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetAuthorisationCodeRequest.h"

namespace greentop {

GetAuthorisationCodeRequest::GetAuthorisationCodeRequest() {
}

GetAuthorisationCodeRequest::GetAuthorisationCodeRequest(const std::string& vendorId) :
    vendorId(vendorId) {
}

void GetAuthorisationCodeRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorId")) {
        vendorId = json["vendorId"].asString();
    }
}

Json::Value GetAuthorisationCodeRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorId != "") {
        json["vendorId"] = vendorId;
    }
    return json;
}

bool GetAuthorisationCodeRequest::isValid() const {
    return vendorId != "";
}

const std::string& GetAuthorisationCodeRequest::getVendorId() const {
    return vendorId;
}
void GetAuthorisationCodeRequest::setVendorId(const std::string& vendorId) {
    this->vendorId = vendorId;
}


}



