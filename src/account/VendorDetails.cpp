/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/VendorDetails.h"

namespace greentop {

VendorDetails::VendorDetails() : appVersionId(-1) {
}

VendorDetails::VendorDetails(const int64_t appVersionId,
    const std::string& vendorName,
    const std::string& redirectUrl) :
    appVersionId(appVersionId),
    vendorName(vendorName),
    redirectUrl(redirectUrl) {
}

void VendorDetails::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("appVersionId")) {
            appVersionId = json["appVersionId"].asInt64();
;
        }
        if (json.isMember("vendorName")) {
            vendorName = json["vendorName"].asString();
;
        }
        if (json.isMember("redirectUrl")) {
            redirectUrl = json["redirectUrl"].asString();
;
        }
    }
}

Json::Value VendorDetails::toJson() const {
    Json::Value json(Json::objectValue);
    json["appVersionId"] = appVersionId;
    if (vendorName != "") {
        json["vendorName"] = vendorName;
    }
    if (redirectUrl != "") {
        json["redirectUrl"] = redirectUrl;
    }
    return json;
}

bool VendorDetails::isValid() const {
    return vendorName != "";
}

const int64_t VendorDetails::getAppVersionId() const {
    return appVersionId;
}
void VendorDetails::setAppVersionId(const int64_t appVersionId) {
    this->appVersionId = appVersionId;
}

const std::string& VendorDetails::getVendorName() const {
    return vendorName;
}
void VendorDetails::setVendorName(const std::string& vendorName) {
    this->vendorName = vendorName;
}

const std::string& VendorDetails::getRedirectUrl() const {
    return redirectUrl;
}
void VendorDetails::setRedirectUrl(const std::string& redirectUrl) {
    this->redirectUrl = redirectUrl;
}


}



