/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetVendorClientIdResponse.h"

namespace greentop {

GetVendorClientIdResponse::GetVendorClientIdResponse() {
}

GetVendorClientIdResponse::GetVendorClientIdResponse(const std::string& vendorClientId) :
    vendorClientId(vendorClientId) {
}

void GetVendorClientIdResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("vendorClientId")) {
            vendorClientId = json["vendorClientId"].asString();
;
        }
    }
}

Json::Value GetVendorClientIdResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (vendorClientId != "") {
        json["vendorClientId"] = vendorClientId;
    }
    return json;
}

bool GetVendorClientIdResponse::isValid() const {
    return vendorClientId != "";
}

const std::string& GetVendorClientIdResponse::getVendorClientId() const {
    return vendorClientId;
}
void GetVendorClientIdResponse::setVendorClientId(const std::string& vendorClientId) {
    this->vendorClientId = vendorClientId;
}


}



