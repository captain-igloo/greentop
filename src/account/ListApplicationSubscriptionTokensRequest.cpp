/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ListApplicationSubscriptionTokensRequest.h"

namespace greentop {


ListApplicationSubscriptionTokensRequest::ListApplicationSubscriptionTokensRequest(const SubscriptionStatus& subscriptionStatus) :
    subscriptionStatus(subscriptionStatus) {
}

void ListApplicationSubscriptionTokensRequest::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionStatus")) {
        subscriptionStatus = json["subscriptionStatus"].asString();
    }
}

Json::Value ListApplicationSubscriptionTokensRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionStatus.isValid()) {
        json["subscriptionStatus"] = subscriptionStatus.getValue();
    }
    return json;
}

bool ListApplicationSubscriptionTokensRequest::isValid() const {
    return true;
}

const SubscriptionStatus& ListApplicationSubscriptionTokensRequest::getSubscriptionStatus() const {
    return subscriptionStatus;
}
void ListApplicationSubscriptionTokensRequest::setSubscriptionStatus(const SubscriptionStatus& subscriptionStatus) {
    this->subscriptionStatus = subscriptionStatus;
}


}



