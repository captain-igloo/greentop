/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/UpdateApplicationSubscriptionResponse.h"

namespace greentop {

UpdateApplicationSubscriptionResponse::UpdateApplicationSubscriptionResponse() {
}

UpdateApplicationSubscriptionResponse::UpdateApplicationSubscriptionResponse(const std::string& subscriptionToken) :
    subscriptionToken(subscriptionToken) {
}

void UpdateApplicationSubscriptionResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("subscriptionToken")) {
            subscriptionToken = json["subscriptionToken"].asString();
;
        }
    }
}

Json::Value UpdateApplicationSubscriptionResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionToken != "") {
        json["subscriptionToken"] = subscriptionToken;
    }
    return json;
}

bool UpdateApplicationSubscriptionResponse::isValid() const {
    return subscriptionToken != "";
}

const std::string& UpdateApplicationSubscriptionResponse::getSubscriptionToken() const {
    return subscriptionToken;
}
void UpdateApplicationSubscriptionResponse::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}


}



