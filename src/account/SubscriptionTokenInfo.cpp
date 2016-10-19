/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/SubscriptionTokenInfo.h"

namespace greentop {

SubscriptionTokenInfo::SubscriptionTokenInfo() {
}

SubscriptionTokenInfo::SubscriptionTokenInfo(const std::string& subscriptionToken,
    const std::tm& activatedDateTime,
    const std::tm& expiryDateTime,
    const std::tm& expiredDateTime,
    const std::tm& cancellationDateTime,
    const std::string& subscriptionStatus) :
    subscriptionToken(subscriptionToken),
    activatedDateTime(activatedDateTime),
    expiryDateTime(expiryDateTime),
    expiredDateTime(expiredDateTime),
    cancellationDateTime(cancellationDateTime),
    subscriptionStatus(subscriptionStatus) {
}

void SubscriptionTokenInfo::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionToken")) {
        subscriptionToken = json["subscriptionToken"].asString();
    }
    if (json.isMember("activatedDateTime")) {
        strptime(json["activatedDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &activatedDateTime);
    }
    if (json.isMember("expiryDateTime")) {
        strptime(json["expiryDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &expiryDateTime);
    }
    if (json.isMember("expiredDateTime")) {
        strptime(json["expiredDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &expiredDateTime);
    }
    if (json.isMember("cancellationDateTime")) {
        strptime(json["cancellationDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &cancellationDateTime);
    }
    if (json.isMember("subscriptionStatus")) {
        subscriptionStatus = json["subscriptionStatus"].asString();
    }
}

Json::Value SubscriptionTokenInfo::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionToken != "") {
        json["subscriptionToken"] = subscriptionToken;
    }
    if (activatedDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &activatedDateTime);
        json["activatedDateTime"] = std::string(buffer);
    }
    if (expiryDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &expiryDateTime);
        json["expiryDateTime"] = std::string(buffer);
    }
    if (expiredDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &expiredDateTime);
        json["expiredDateTime"] = std::string(buffer);
    }
    if (cancellationDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &cancellationDateTime);
        json["cancellationDateTime"] = std::string(buffer);
    }
    if (subscriptionStatus != "") {
        json["subscriptionStatus"] = subscriptionStatus;
    }
    return json;
}

bool SubscriptionTokenInfo::isValid() const {
    return subscriptionToken != "";
}

const std::string& SubscriptionTokenInfo::getSubscriptionToken() const {
    return subscriptionToken;
}
void SubscriptionTokenInfo::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}

const std::tm& SubscriptionTokenInfo::getActivatedDateTime() const {
    return activatedDateTime;
}
void SubscriptionTokenInfo::setActivatedDateTime(const std::tm& activatedDateTime) {
    this->activatedDateTime = activatedDateTime;
}

const std::tm& SubscriptionTokenInfo::getExpiryDateTime() const {
    return expiryDateTime;
}
void SubscriptionTokenInfo::setExpiryDateTime(const std::tm& expiryDateTime) {
    this->expiryDateTime = expiryDateTime;
}

const std::tm& SubscriptionTokenInfo::getExpiredDateTime() const {
    return expiredDateTime;
}
void SubscriptionTokenInfo::setExpiredDateTime(const std::tm& expiredDateTime) {
    this->expiredDateTime = expiredDateTime;
}

const std::tm& SubscriptionTokenInfo::getCancellationDateTime() const {
    return cancellationDateTime;
}
void SubscriptionTokenInfo::setCancellationDateTime(const std::tm& cancellationDateTime) {
    this->cancellationDateTime = cancellationDateTime;
}

const std::string& SubscriptionTokenInfo::getSubscriptionStatus() const {
    return subscriptionStatus;
}
void SubscriptionTokenInfo::setSubscriptionStatus(const std::string& subscriptionStatus) {
    this->subscriptionStatus = subscriptionStatus;
}


}



