/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetApplicationSubscriptionTokenRequest.h"

namespace greentop {


GetApplicationSubscriptionTokenRequest::GetApplicationSubscriptionTokenRequest(const Optional<int32_t>& subscriptionLength,
    const std::string& clientReference) :
    subscriptionLength(subscriptionLength),
    clientReference(clientReference) {
}

void GetApplicationSubscriptionTokenRequest::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionLength")) {
        subscriptionLength = json["subscriptionLength"].asInt();
    }
    if (json.isMember("clientReference")) {
        clientReference = json["clientReference"].asString();
    }
}

Json::Value GetApplicationSubscriptionTokenRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionLength.isValid()) {
        json["subscriptionLength"] = subscriptionLength.toJson();
    }
    if (clientReference != "") {
        json["clientReference"] = clientReference;
    }
    return json;
}

bool GetApplicationSubscriptionTokenRequest::isValid() const {
    return true;
}

const Optional<int32_t>& GetApplicationSubscriptionTokenRequest::getSubscriptionLength() const {
    return subscriptionLength;
}
void GetApplicationSubscriptionTokenRequest::setSubscriptionLength(const Optional<int32_t>& subscriptionLength) {
    this->subscriptionLength = subscriptionLength;
}

const std::string& GetApplicationSubscriptionTokenRequest::getClientReference() const {
    return clientReference;
}
void GetApplicationSubscriptionTokenRequest::setClientReference(const std::string& clientReference) {
    this->clientReference = clientReference;
}


}



