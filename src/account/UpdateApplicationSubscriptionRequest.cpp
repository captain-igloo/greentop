/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/UpdateApplicationSubscriptionRequest.h"

namespace greentop {

UpdateApplicationSubscriptionRequest::UpdateApplicationSubscriptionRequest() {
}

UpdateApplicationSubscriptionRequest::UpdateApplicationSubscriptionRequest(const std::string& vendorClientId,
    const int32_t subscriptionLength) :
    vendorClientId(vendorClientId),
    subscriptionLength(subscriptionLength) {
}

void UpdateApplicationSubscriptionRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorClientId")) {
        vendorClientId = json["vendorClientId"].asString();
    }
    if (json.isMember("subscriptionLength")) {
        subscriptionLength = json["subscriptionLength"].asInt();
    }
}

Json::Value UpdateApplicationSubscriptionRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorClientId != "") {
        json["vendorClientId"] = vendorClientId;
    }
    json["subscriptionLength"] = subscriptionLength;
    return json;
}

bool UpdateApplicationSubscriptionRequest::isValid() const {
    return vendorClientId != "";
}

const std::string& UpdateApplicationSubscriptionRequest::getVendorClientId() const {
    return vendorClientId;
}
void UpdateApplicationSubscriptionRequest::setVendorClientId(const std::string& vendorClientId) {
    this->vendorClientId = vendorClientId;
}

const int32_t UpdateApplicationSubscriptionRequest::getSubscriptionLength() const {
    return subscriptionLength;
}
void UpdateApplicationSubscriptionRequest::setSubscriptionLength(const int32_t subscriptionLength) {
    this->subscriptionLength = subscriptionLength;
}


}



