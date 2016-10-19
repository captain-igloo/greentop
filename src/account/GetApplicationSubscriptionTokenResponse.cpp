/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetApplicationSubscriptionTokenResponse.h"

namespace greentop {

GetApplicationSubscriptionTokenResponse::GetApplicationSubscriptionTokenResponse() {
}

GetApplicationSubscriptionTokenResponse::GetApplicationSubscriptionTokenResponse(const std::string& subscriptionToken) :
    subscriptionToken(subscriptionToken) {
}

void GetApplicationSubscriptionTokenResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("subscriptionToken")) {
            subscriptionToken = json["subscriptionToken"].asString();
;
        }
    }
}

Json::Value GetApplicationSubscriptionTokenResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (subscriptionToken != "") {
        json["subscriptionToken"] = subscriptionToken;
    }
    return json;
}

bool GetApplicationSubscriptionTokenResponse::isValid() const {
    return subscriptionToken != "";
}

const std::string& GetApplicationSubscriptionTokenResponse::getSubscriptionToken() const {
    return subscriptionToken;
}
void GetApplicationSubscriptionTokenResponse::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}


}



