/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/DeveloperAppVersion.h"

namespace greentop {

DeveloperAppVersion::DeveloperAppVersion() : versionId(-1) {
}

DeveloperAppVersion::DeveloperAppVersion(const std::string& owner,
    const int64_t versionId,
    const std::string& version,
    const std::string& applicationKey,
    const Optional<bool>& delayData,
    const Optional<bool>& subscriptionRequired,
    const Optional<bool>& ownerManaged,
    const Optional<bool>& active,
    const std::string& vendorId,
    const std::string& vendorSecret) :
    owner(owner),
    versionId(versionId),
    version(version),
    applicationKey(applicationKey),
    delayData(delayData),
    subscriptionRequired(subscriptionRequired),
    ownerManaged(ownerManaged),
    active(active),
    vendorId(vendorId),
    vendorSecret(vendorSecret) {
}

void DeveloperAppVersion::fromJson(const Json::Value& json) {
    if (json.isMember("owner")) {
        owner = json["owner"].asString();
    }
    if (json.isMember("versionId")) {
        versionId = json["versionId"].asInt64();
    }
    if (json.isMember("version")) {
        version = json["version"].asString();
    }
    if (json.isMember("applicationKey")) {
        applicationKey = json["applicationKey"].asString();
    }
    if (json.isMember("delayData")) {
        delayData = json["delayData"].asBool();
    }
    if (json.isMember("subscriptionRequired")) {
        subscriptionRequired = json["subscriptionRequired"].asBool();
    }
    if (json.isMember("ownerManaged")) {
        ownerManaged = json["ownerManaged"].asBool();
    }
    if (json.isMember("active")) {
        active = json["active"].asBool();
    }
    if (json.isMember("vendorId")) {
        vendorId = json["vendorId"].asString();
    }
    if (json.isMember("vendorSecret")) {
        vendorSecret = json["vendorSecret"].asString();
    }
}

Json::Value DeveloperAppVersion::toJson() const {
    Json::Value json(Json::objectValue);
    if (owner != "") {
        json["owner"] = owner;
    }
    json["versionId"] = versionId;
    if (version != "") {
        json["version"] = version;
    }
    if (applicationKey != "") {
        json["applicationKey"] = applicationKey;
    }
    if (delayData.isValid()) {
        json["delayData"] = delayData.toJson();
    }
    if (subscriptionRequired.isValid()) {
        json["subscriptionRequired"] = subscriptionRequired.toJson();
    }
    if (ownerManaged.isValid()) {
        json["ownerManaged"] = ownerManaged.toJson();
    }
    if (active.isValid()) {
        json["active"] = active.toJson();
    }
    if (vendorId != "") {
        json["vendorId"] = vendorId;
    }
    if (vendorSecret != "") {
        json["vendorSecret"] = vendorSecret;
    }
    return json;
}

bool DeveloperAppVersion::isValid() const {
    return owner != "" && version != "" && applicationKey != "" && subscriptionRequired.isValid() && ownerManaged.isValid() && active.isValid();
}

const std::string& DeveloperAppVersion::getOwner() const {
    return owner;
}
void DeveloperAppVersion::setOwner(const std::string& owner) {
    this->owner = owner;
}

const int64_t DeveloperAppVersion::getVersionId() const {
    return versionId;
}
void DeveloperAppVersion::setVersionId(const int64_t versionId) {
    this->versionId = versionId;
}

const std::string& DeveloperAppVersion::getVersion() const {
    return version;
}
void DeveloperAppVersion::setVersion(const std::string& version) {
    this->version = version;
}

const std::string& DeveloperAppVersion::getApplicationKey() const {
    return applicationKey;
}
void DeveloperAppVersion::setApplicationKey(const std::string& applicationKey) {
    this->applicationKey = applicationKey;
}

const Optional<bool>& DeveloperAppVersion::getDelayData() const {
    return delayData;
}
void DeveloperAppVersion::setDelayData(const Optional<bool>& delayData) {
    this->delayData = delayData;
}

const Optional<bool>& DeveloperAppVersion::getSubscriptionRequired() const {
    return subscriptionRequired;
}
void DeveloperAppVersion::setSubscriptionRequired(const Optional<bool>& subscriptionRequired) {
    this->subscriptionRequired = subscriptionRequired;
}

const Optional<bool>& DeveloperAppVersion::getOwnerManaged() const {
    return ownerManaged;
}
void DeveloperAppVersion::setOwnerManaged(const Optional<bool>& ownerManaged) {
    this->ownerManaged = ownerManaged;
}

const Optional<bool>& DeveloperAppVersion::getActive() const {
    return active;
}
void DeveloperAppVersion::setActive(const Optional<bool>& active) {
    this->active = active;
}

const std::string& DeveloperAppVersion::getVendorId() const {
    return vendorId;
}
void DeveloperAppVersion::setVendorId(const std::string& vendorId) {
    this->vendorId = vendorId;
}

const std::string& DeveloperAppVersion::getVendorSecret() const {
    return vendorSecret;
}
void DeveloperAppVersion::setVendorSecret(const std::string& vendorSecret) {
    this->vendorSecret = vendorSecret;
}


}



