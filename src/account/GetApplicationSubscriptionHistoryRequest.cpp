/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetApplicationSubscriptionHistoryRequest.h"

namespace greentop {


GetApplicationSubscriptionHistoryRequest::GetApplicationSubscriptionHistoryRequest(const std::string& vendorClientId,
    const std::string& applicationKey) :
    vendorClientId(vendorClientId),
    applicationKey(applicationKey) {
}

void GetApplicationSubscriptionHistoryRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorClientId")) {
        vendorClientId = json["vendorClientId"].asString();
    }
    if (json.isMember("applicationKey")) {
        applicationKey = json["applicationKey"].asString();
    }
}

Json::Value GetApplicationSubscriptionHistoryRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorClientId != "") {
        json["vendorClientId"] = vendorClientId;
    }
    if (applicationKey != "") {
        json["applicationKey"] = applicationKey;
    }
    return json;
}

bool GetApplicationSubscriptionHistoryRequest::isValid() const {
    return true;
}

const std::string& GetApplicationSubscriptionHistoryRequest::getVendorClientId() const {
    return vendorClientId;
}
void GetApplicationSubscriptionHistoryRequest::setVendorClientId(const std::string& vendorClientId) {
    this->vendorClientId = vendorClientId;
}

const std::string& GetApplicationSubscriptionHistoryRequest::getApplicationKey() const {
    return applicationKey;
}
void GetApplicationSubscriptionHistoryRequest::setApplicationKey(const std::string& applicationKey) {
    this->applicationKey = applicationKey;
}


}



