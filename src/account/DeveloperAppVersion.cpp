/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/DeveloperAppVersion.h"

namespace greentop {
DeveloperAppVersion::DeveloperAppVersion()  : versionId(0), delayData(0), subscriptionRequired(0), ownerManaged(0), active(0){
}

DeveloperAppVersion::DeveloperAppVersion(const std::string& owner,
    const uint64_t versionId,
    const std::string& version,
    const std::string& applicationKey,
    const bool delayData,
    const bool subscriptionRequired,
    const bool ownerManaged,
    const bool active) :
    owner(owner),
    versionId(versionId),
    version(version),
    applicationKey(applicationKey),
    delayData(delayData),
    subscriptionRequired(subscriptionRequired),
    ownerManaged(ownerManaged),
    active(active) {
}

void DeveloperAppVersion::fromJson(const Json::Value& json) {
    if (json.isMember("owner")) {
        owner = json["owner"].asString();
    }
    if (json.isMember("versionId")) {
        versionId = json["versionId"].asUInt64();
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
}

Json::Value DeveloperAppVersion::toJson() const {
    Json::Value json(Json::objectValue);
    if (owner != "") {
        json["owner"] = owner;
    }
    if (versionId > 0) {
        json["versionId"] = versionId;
    }
    if (version != "") {
        json["version"] = version;
    }
    if (applicationKey != "") {
        json["applicationKey"] = applicationKey;
    }
    json["delayData"] = delayData;
    json["subscriptionRequired"] = subscriptionRequired;
    json["ownerManaged"] = ownerManaged;
    json["active"] = active;
    return json;
}

bool DeveloperAppVersion::isValid() const {
    return owner != "" && versionId > 0 && version != "" && applicationKey != "" && true && true && true && true;
}

const std::string& DeveloperAppVersion::getOwner() const {
    return owner;
}
void DeveloperAppVersion::setOwner(const std::string& owner) {
    this->owner = owner;
}

const uint64_t DeveloperAppVersion::getVersionId() const {
    return versionId;
}
void DeveloperAppVersion::setVersionId(const uint64_t versionId) {
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

const bool DeveloperAppVersion::getDelayData() const {
    return delayData;
}
void DeveloperAppVersion::setDelayData(const bool delayData) {
    this->delayData = delayData;
}

const bool DeveloperAppVersion::getSubscriptionRequired() const {
    return subscriptionRequired;
}
void DeveloperAppVersion::setSubscriptionRequired(const bool subscriptionRequired) {
    this->subscriptionRequired = subscriptionRequired;
}

const bool DeveloperAppVersion::getOwnerManaged() const {
    return ownerManaged;
}
void DeveloperAppVersion::setOwnerManaged(const bool ownerManaged) {
    this->ownerManaged = ownerManaged;
}

const bool DeveloperAppVersion::getActive() const {
    return active;
}
void DeveloperAppVersion::setActive(const bool active) {
    this->active = active;
}


}



