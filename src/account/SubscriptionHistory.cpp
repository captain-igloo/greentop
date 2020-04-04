/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/SubscriptionHistory.h"

namespace greentop {
namespace account {

SubscriptionHistory::SubscriptionHistory() {
}

SubscriptionHistory::SubscriptionHistory(const std::string& subscriptionToken,
    const std::tm& expiryDateTime,
    const std::tm& expiredDateTime,
    const std::tm& createdDateTime,
    const std::tm& activationDateTime,
    const std::tm& cancellationDateTime,
    const std::string& subscriptionStatus,
    const std::string& clientReference) :
    subscriptionToken(subscriptionToken),
    expiryDateTime(expiryDateTime),
    expiredDateTime(expiredDateTime),
    createdDateTime(createdDateTime),
    activationDateTime(activationDateTime),
    cancellationDateTime(cancellationDateTime),
    subscriptionStatus(subscriptionStatus),
    clientReference(clientReference) {
}

void SubscriptionHistory::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionToken")) {
        subscriptionToken = json["subscriptionToken"].asString();
    }
    if (json.isMember("expiryDateTime")) {
        strptime(json["expiryDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &expiryDateTime);
    }
    if (json.isMember("expiredDateTime")) {
        strptime(json["expiredDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &expiredDateTime);
    }
    if (json.isMember("createdDateTime")) {
        strptime(json["createdDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &createdDateTime);
    }
    if (json.isMember("activationDateTime")) {
        strptime(json["activationDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &activationDateTime);
    }
    if (json.isMember("cancellationDateTime")) {
        strptime(json["cancellationDateTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &cancellationDateTime);
    }
    if (json.isMember("subscriptionStatus")) {
        subscriptionStatus = json["subscriptionStatus"].asString();
    }
    if (json.isMember("clientReference")) {
        clientReference = json["clientReference"].asString();
    }
}

Json::Value SubscriptionHistory::toJson() const {
    Json::Value json(Json::objectValue);
    if (subscriptionToken != "") {
        json["subscriptionToken"] = subscriptionToken;
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
    if (createdDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &createdDateTime);
        json["createdDateTime"] = std::string(buffer);
    }
    if (activationDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &activationDateTime);
        json["activationDateTime"] = std::string(buffer);
    }
    if (cancellationDateTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &cancellationDateTime);
        json["cancellationDateTime"] = std::string(buffer);
    }
    if (subscriptionStatus != "") {
        json["subscriptionStatus"] = subscriptionStatus;
    }
    if (clientReference != "") {
        json["clientReference"] = clientReference;
    }
    return json;
}

bool SubscriptionHistory::isValid() const {
    return subscriptionToken != "";
}

const std::string& SubscriptionHistory::getSubscriptionToken() const {
    return subscriptionToken;
}
void SubscriptionHistory::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}

const std::tm& SubscriptionHistory::getExpiryDateTime() const {
    return expiryDateTime;
}
void SubscriptionHistory::setExpiryDateTime(const std::tm& expiryDateTime) {
    this->expiryDateTime = expiryDateTime;
}

const std::tm& SubscriptionHistory::getExpiredDateTime() const {
    return expiredDateTime;
}
void SubscriptionHistory::setExpiredDateTime(const std::tm& expiredDateTime) {
    this->expiredDateTime = expiredDateTime;
}

const std::tm& SubscriptionHistory::getCreatedDateTime() const {
    return createdDateTime;
}
void SubscriptionHistory::setCreatedDateTime(const std::tm& createdDateTime) {
    this->createdDateTime = createdDateTime;
}

const std::tm& SubscriptionHistory::getActivationDateTime() const {
    return activationDateTime;
}
void SubscriptionHistory::setActivationDateTime(const std::tm& activationDateTime) {
    this->activationDateTime = activationDateTime;
}

const std::tm& SubscriptionHistory::getCancellationDateTime() const {
    return cancellationDateTime;
}
void SubscriptionHistory::setCancellationDateTime(const std::tm& cancellationDateTime) {
    this->cancellationDateTime = cancellationDateTime;
}

const std::string& SubscriptionHistory::getSubscriptionStatus() const {
    return subscriptionStatus;
}
void SubscriptionHistory::setSubscriptionStatus(const std::string& subscriptionStatus) {
    this->subscriptionStatus = subscriptionStatus;
}

const std::string& SubscriptionHistory::getClientReference() const {
    return clientReference;
}
void SubscriptionHistory::setClientReference(const std::string& clientReference) {
    this->clientReference = clientReference;
}


}
}
