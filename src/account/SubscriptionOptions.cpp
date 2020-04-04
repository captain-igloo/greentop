/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/SubscriptionOptions.h"

namespace greentop {
namespace account {


SubscriptionOptions::SubscriptionOptions(const Optional<int32_t>& subscriptionLength,
    const std::string& subscriptionToken,
    const std::string& clientReference) :
    subscriptionLength(subscriptionLength),
    subscriptionToken(subscriptionToken),
    clientReference(clientReference) {
}

void SubscriptionOptions::fromJson(const Json::Value& json) {
    if (json.isMember("subscription_length")) {
        subscriptionLength = json["subscription_length"].asInt();
    }
    if (json.isMember("subscription_token")) {
        subscriptionToken = json["subscription_token"].asString();
    }
    if (json.isMember("client_reference")) {
        clientReference = json["client_reference"].asString();
    }
}

Json::Value SubscriptionOptions::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionLength.isValid()) {
        json["subscription_length"] = subscriptionLength.toJson();
    }
    if (subscriptionToken != "") {
        json["subscription_token"] = subscriptionToken;
    }
    if (clientReference != "") {
        json["client_reference"] = clientReference;
    }
    return json;
}

bool SubscriptionOptions::isValid() const {
    return true;
}

const Optional<int32_t>& SubscriptionOptions::getSubscriptionLength() const {
    return subscriptionLength;
}
void SubscriptionOptions::setSubscriptionLength(const Optional<int32_t>& subscriptionLength) {
    this->subscriptionLength = subscriptionLength;
}

const std::string& SubscriptionOptions::getSubscriptionToken() const {
    return subscriptionToken;
}
void SubscriptionOptions::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}

const std::string& SubscriptionOptions::getClientReference() const {
    return clientReference;
}
void SubscriptionOptions::setClientReference(const std::string& clientReference) {
    this->clientReference = clientReference;
}


}
}
