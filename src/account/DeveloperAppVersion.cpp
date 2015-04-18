/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/DeveloperAppVersion.h"

namespace greentop {
DeveloperAppVersion::DeveloperAppVersion()  : versionId(0){
}

DeveloperAppVersion::DeveloperAppVersion(const std::string& owner,
    const uint64_t versionId,
    const std::string& version,
    const std::string& applicationKey,
    const BoolJsonMember& delayData,
    const BoolJsonMember& subscriptionRequired,
    const BoolJsonMember& ownerManaged,
    const BoolJsonMember& active) :
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
        versionId = json["versionId"].asUInt();
    }
    if (json.isMember("version")) {
        version = json["version"].asString();
    }
    if (json.isMember("applicationKey")) {
        applicationKey = json["applicationKey"].asString();
    }
    if (json.isMember("delayData")) {
        delayData.fromJson(json["delayData"]);
    }
    if (json.isMember("subscriptionRequired")) {
        subscriptionRequired.fromJson(json["subscriptionRequired"]);
    }
    if (json.isMember("ownerManaged")) {
        ownerManaged.fromJson(json["ownerManaged"]);
    }
    if (json.isMember("active")) {
        active.fromJson(json["active"]);
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
    return json;
}

bool DeveloperAppVersion::isValid() const {
    return owner != "" && versionId > 0 && version != "" && applicationKey != "" && delayData.isValid() && subscriptionRequired.isValid() && ownerManaged.isValid() && active.isValid();
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

const BoolJsonMember& DeveloperAppVersion::getDelayData() const {
    return delayData;
}
void DeveloperAppVersion::setDelayData(const BoolJsonMember& delayData) {
    this->delayData = delayData;
}

const BoolJsonMember& DeveloperAppVersion::getSubscriptionRequired() const {
    return subscriptionRequired;
}
void DeveloperAppVersion::setSubscriptionRequired(const BoolJsonMember& subscriptionRequired) {
    this->subscriptionRequired = subscriptionRequired;
}

const BoolJsonMember& DeveloperAppVersion::getOwnerManaged() const {
    return ownerManaged;
}
void DeveloperAppVersion::setOwnerManaged(const BoolJsonMember& ownerManaged) {
    this->ownerManaged = ownerManaged;
}

const BoolJsonMember& DeveloperAppVersion::getActive() const {
    return active;
}
void DeveloperAppVersion::setActive(const BoolJsonMember& active) {
    this->active = active;
}


}



