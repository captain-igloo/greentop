/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AffiliateRelation.h"

namespace greentop {
namespace account {

AffiliateRelation::AffiliateRelation() {
}

AffiliateRelation::AffiliateRelation(const std::string& vendorClientId,
    const AffiliateRelationStatus& status) :
    vendorClientId(vendorClientId),
    status(status) {
}

void AffiliateRelation::fromJson(const Json::Value& json) {
    if (json.isMember("vendorClientId")) {
        vendorClientId = json["vendorClientId"].asString();
    }
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
}

Json::Value AffiliateRelation::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorClientId != "") {
        json["vendorClientId"] = vendorClientId;
    }
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    return json;
}

bool AffiliateRelation::isValid() const {
    return vendorClientId != "" && status.isValid();
}

const std::string& AffiliateRelation::getVendorClientId() const {
    return vendorClientId;
}
void AffiliateRelation::setVendorClientId(const std::string& vendorClientId) {
    this->vendorClientId = vendorClientId;
}

const AffiliateRelationStatus& AffiliateRelation::getStatus() const {
    return status;
}
void AffiliateRelation::setStatus(const AffiliateRelationStatus& status) {
    this->status = status;
}


}
}
