/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETAFFILIATERELATIONRESPONSE_H
#define ACCOUNT_GETAFFILIATERELATIONRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/AffiliateRelation.h"

namespace greentop {
namespace account {

class GetAffiliateRelationResponse : public JsonResponse {
    public:
        GetAffiliateRelationResponse();

        GetAffiliateRelationResponse(const std::vector<AffiliateRelation>& affiliateRelations);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<AffiliateRelation>& getAffiliateRelations() const;
        void setAffiliateRelations(const std::vector<AffiliateRelation>& affiliateRelations);


    private:

        std::vector<AffiliateRelation> affiliateRelations;
};

}
}

#endif // ACCOUNT_GETAFFILIATERELATIONRESPONSE_H
