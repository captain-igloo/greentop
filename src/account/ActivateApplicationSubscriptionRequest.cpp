/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ActivateApplicationSubscriptionRequest.h"

namespace greentop {
namespace account {

ActivateApplicationSubscriptionRequest::ActivateApplicationSubscriptionRequest() {
}

ActivateApplicationSubscriptionRequest::ActivateApplicationSubscriptionRequest(const std::string& subscriptionToken) :
    subscriptionToken(subscriptionToken) {
}

void ActivateApplicationSubscriptionRequest::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionToken")) {
        subscriptionToken = json["subscriptionToken"].asString();
    }
}

Json::Value ActivateApplicationSubscriptionRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionToken != "") {
        json["subscriptionToken"] = subscriptionToken;
    }
    return json;
}

bool ActivateApplicationSubscriptionRequest::isValid() const {
    return subscriptionToken != "";
}

const std::string& ActivateApplicationSubscriptionRequest::getSubscriptionToken() const {
    return subscriptionToken;
}
void ActivateApplicationSubscriptionRequest::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}


}
}
