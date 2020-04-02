/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/SubscriptionOptions.h"

namespace greentop {
namespace account {


SubscriptionOptions::SubscriptionOptions(const Optional<int32_t>& subscription_length,
    const std::string& subscription_token,
    const std::string& client_reference) :
    subscription_length(subscription_length),
    subscription_token(subscription_token),
    client_reference(client_reference) {
}

void SubscriptionOptions::fromJson(const Json::Value& json) {
    if (json.isMember("subscription_length")) {
        subscription_length = json["subscription_length"].asInt();
    }
    if (json.isMember("subscription_token")) {
        subscription_token = json["subscription_token"].asString();
    }
    if (json.isMember("client_reference")) {
        client_reference = json["client_reference"].asString();
    }
}

Json::Value SubscriptionOptions::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscription_length.isValid()) {
        json["subscription_length"] = subscription_length.toJson();
    }
    if (subscription_token != "") {
        json["subscription_token"] = subscription_token;
    }
    if (client_reference != "") {
        json["client_reference"] = client_reference;
    }
    return json;
}

bool SubscriptionOptions::isValid() const {
    return true;
}

const Optional<int32_t>& SubscriptionOptions::getSubscription_length() const {
    return subscription_length;
}
void SubscriptionOptions::setSubscription_length(const Optional<int32_t>& subscription_length) {
    this->subscription_length = subscription_length;
}

const std::string& SubscriptionOptions::getSubscription_token() const {
    return subscription_token;
}
void SubscriptionOptions::setSubscription_token(const std::string& subscription_token) {
    this->subscription_token = subscription_token;
}

const std::string& SubscriptionOptions::getClient_reference() const {
    return client_reference;
}
void SubscriptionOptions::setClient_reference(const std::string& client_reference) {
    this->client_reference = client_reference;
}


}
}
