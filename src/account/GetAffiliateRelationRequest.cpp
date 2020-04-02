/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetAffiliateRelationRequest.h"

namespace greentop {
namespace account {

GetAffiliateRelationRequest::GetAffiliateRelationRequest() {
}

GetAffiliateRelationRequest::GetAffiliateRelationRequest(const std::vector<std::string>& vendorClientIds) :
    vendorClientIds(vendorClientIds) {
}

void GetAffiliateRelationRequest::fromJson(const Json::Value& json) {
    if (json.isMember("vendorClientIds")) {
        for (unsigned i = 0; i < json["vendorClientIds"].size(); ++i) {
            vendorClientIds.push_back(json["vendorClientIds"][i].asString());
        }
    }
}

Json::Value GetAffiliateRelationRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (vendorClientIds.size() > 0) {
        for (unsigned i = 0; i < vendorClientIds.size(); ++i) {
            json["vendorClientIds"].append(vendorClientIds[i]);
        }
    }
    return json;
}

bool GetAffiliateRelationRequest::isValid() const {
    return vendorClientIds.size() > 0;
}

const std::vector<std::string>& GetAffiliateRelationRequest::getVendorClientIds() const {
    return vendorClientIds;
}
void GetAffiliateRelationRequest::setVendorClientIds(const std::vector<std::string>& vendorClientIds) {
    this->vendorClientIds = vendorClientIds;
}


}
}
