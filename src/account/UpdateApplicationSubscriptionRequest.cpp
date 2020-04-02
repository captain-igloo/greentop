/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/UpdateApplicationSubscriptionRequest.h"

namespace greentop {
namespace account {

UpdateApplicationSubscriptionRequest::UpdateApplicationSubscriptionRequest() {
}

UpdateApplicationSubscriptionRequest::UpdateApplicationSubscriptionRequest(const std::string& vendorClientId,
    const Optional<int32_t>& subscriptionLength) :
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
    if (subscriptionLength.isValid()) {
        json["subscriptionLength"] = subscriptionLength.toJson();
    }
    return json;
}

bool UpdateApplicationSubscriptionRequest::isValid() const {
    return vendorClientId != "" && subscriptionLength.isValid();
}

const std::string& UpdateApplicationSubscriptionRequest::getVendorClientId() const {
    return vendorClientId;
}
void UpdateApplicationSubscriptionRequest::setVendorClientId(const std::string& vendorClientId) {
    this->vendorClientId = vendorClientId;
}

const Optional<int32_t>& UpdateApplicationSubscriptionRequest::getSubscriptionLength() const {
    return subscriptionLength;
}
void UpdateApplicationSubscriptionRequest::setSubscriptionLength(const Optional<int32_t>& subscriptionLength) {
    this->subscriptionLength = subscriptionLength;
}


}
}
