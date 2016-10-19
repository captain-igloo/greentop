/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AccountSubscription.h"

namespace greentop {

AccountSubscription::AccountSubscription() {
}

AccountSubscription::AccountSubscription(const std::vector<SubscriptionTokenInfo>& subscriptionTokens,
    const std::string& applicationName,
    const std::string& applicationVersionId) :
    subscriptionTokens(subscriptionTokens),
    applicationName(applicationName),
    applicationVersionId(applicationVersionId) {
}

void AccountSubscription::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionTokens")) {
        for (unsigned i = 0; i < json["subscriptionTokens"].size(); ++i) {
            SubscriptionTokenInfo subscriptionToken;
            subscriptionToken.fromJson(json["subscriptionTokens"][i]);
            subscriptionTokens.push_back(subscriptionToken);
        }
    }
    if (json.isMember("applicationName")) {
        applicationName = json["applicationName"].asString();
    }
    if (json.isMember("applicationVersionId")) {
        applicationVersionId = json["applicationVersionId"].asString();
    }
}

Json::Value AccountSubscription::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionTokens.size() > 0) {
        for (unsigned i = 0; i < subscriptionTokens.size(); ++i) {
            json["subscriptionTokens"].append(subscriptionTokens[i].toJson());
        }
    }
    if (applicationName != "") {
        json["applicationName"] = applicationName;
    }
    if (applicationVersionId != "") {
        json["applicationVersionId"] = applicationVersionId;
    }
    return json;
}

bool AccountSubscription::isValid() const {
    return subscriptionTokens.size() > 0;
}

const std::vector<SubscriptionTokenInfo>& AccountSubscription::getSubscriptionTokens() const {
    return subscriptionTokens;
}
void AccountSubscription::setSubscriptionTokens(const std::vector<SubscriptionTokenInfo>& subscriptionTokens) {
    this->subscriptionTokens = subscriptionTokens;
}

const std::string& AccountSubscription::getApplicationName() const {
    return applicationName;
}
void AccountSubscription::setApplicationName(const std::string& applicationName) {
    this->applicationName = applicationName;
}

const std::string& AccountSubscription::getApplicationVersionId() const {
    return applicationVersionId;
}
void AccountSubscription::setApplicationVersionId(const std::string& applicationVersionId) {
    this->applicationVersionId = applicationVersionId;
}


}



