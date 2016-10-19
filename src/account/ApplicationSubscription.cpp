/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ApplicationSubscription.h"

namespace greentop {

ApplicationSubscription::ApplicationSubscription() {
}

ApplicationSubscription::ApplicationSubscription(const std::string& subscriptionToken,
    const std::tm& expiryDateTime,
    const std::tm& expiredDateTime,
    const std::tm& createdDateTime,
    const std::tm& activationDateTime,
    const std::tm& cancellationDateTime,
    const std::string& subscriptionStatus,
    const std::string& clientReference,
    const std::string& vendorClientId) :
    subscriptionToken(subscriptionToken),
    expiryDateTime(expiryDateTime),
    expiredDateTime(expiredDateTime),
    createdDateTime(createdDateTime),
    activationDateTime(activationDateTime),
    cancellationDateTime(cancellationDateTime),
    subscriptionStatus(subscriptionStatus),
    clientReference(clientReference),
    vendorClientId(vendorClientId) {
}

void ApplicationSubscription::fromJson(const Json::Value& json) {
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
    if (json.isMember("vendorClientId")) {
        vendorClientId = json["vendorClientId"].asString();
    }
}

Json::Value ApplicationSubscription::toJson() const {
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
    if (vendorClientId != "") {
        json["vendorClientId"] = vendorClientId;
    }
    return json;
}

bool ApplicationSubscription::isValid() const {
    return subscriptionToken != "";
}

const std::string& ApplicationSubscription::getSubscriptionToken() const {
    return subscriptionToken;
}
void ApplicationSubscription::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}

const std::tm& ApplicationSubscription::getExpiryDateTime() const {
    return expiryDateTime;
}
void ApplicationSubscription::setExpiryDateTime(const std::tm& expiryDateTime) {
    this->expiryDateTime = expiryDateTime;
}

const std::tm& ApplicationSubscription::getExpiredDateTime() const {
    return expiredDateTime;
}
void ApplicationSubscription::setExpiredDateTime(const std::tm& expiredDateTime) {
    this->expiredDateTime = expiredDateTime;
}

const std::tm& ApplicationSubscription::getCreatedDateTime() const {
    return createdDateTime;
}
void ApplicationSubscription::setCreatedDateTime(const std::tm& createdDateTime) {
    this->createdDateTime = createdDateTime;
}

const std::tm& ApplicationSubscription::getActivationDateTime() const {
    return activationDateTime;
}
void ApplicationSubscription::setActivationDateTime(const std::tm& activationDateTime) {
    this->activationDateTime = activationDateTime;
}

const std::tm& ApplicationSubscription::getCancellationDateTime() const {
    return cancellationDateTime;
}
void ApplicationSubscription::setCancellationDateTime(const std::tm& cancellationDateTime) {
    this->cancellationDateTime = cancellationDateTime;
}

const std::string& ApplicationSubscription::getSubscriptionStatus() const {
    return subscriptionStatus;
}
void ApplicationSubscription::setSubscriptionStatus(const std::string& subscriptionStatus) {
    this->subscriptionStatus = subscriptionStatus;
}

const std::string& ApplicationSubscription::getClientReference() const {
    return clientReference;
}
void ApplicationSubscription::setClientReference(const std::string& clientReference) {
    this->clientReference = clientReference;
}

const std::string& ApplicationSubscription::getVendorClientId() const {
    return vendorClientId;
}
void ApplicationSubscription::setVendorClientId(const std::string& vendorClientId) {
    this->vendorClientId = vendorClientId;
}


}



