/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetAffiliateRelationResponse.h"

namespace greentop {
namespace account {

GetAffiliateRelationResponse::GetAffiliateRelationResponse() {
}

GetAffiliateRelationResponse::GetAffiliateRelationResponse(const std::vector<AffiliateRelation>& affiliateRelations) :
    affiliateRelations(affiliateRelations) {
}

void GetAffiliateRelationResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            AffiliateRelation affiliateRelation;
            affiliateRelation.fromJson(json[i]);
            affiliateRelations.push_back(affiliateRelation);
        }
    }
}

Json::Value GetAffiliateRelationResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (affiliateRelations.size() > 0) {
        for (unsigned i = 0; i < affiliateRelations.size(); ++i) {
            json.append(affiliateRelations[i].toJson());
        }
    }
    return json;
}

bool GetAffiliateRelationResponse::isValid() const {
    return affiliateRelations.size() > 0;
}

const std::vector<AffiliateRelation>& GetAffiliateRelationResponse::getAffiliateRelations() const {
    return affiliateRelations;
}
void GetAffiliateRelationResponse::setAffiliateRelations(const std::vector<AffiliateRelation>& affiliateRelations) {
    this->affiliateRelations = affiliateRelations;
}


}
}
