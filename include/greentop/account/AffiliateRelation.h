/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_AFFILIATERELATION_H
#define ACCOUNT_AFFILIATERELATION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/account/enum/AffiliateRelationStatus.h"

namespace greentop {
namespace account {
/**
 * Wrapper object containing affiliate relation details
 */
class AffiliateRelation : public JsonMember {
    public:
        AffiliateRelation();

        AffiliateRelation(const std::string& vendorClientId,
            const AffiliateRelationStatus& status);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorClientId() const;
        void setVendorClientId(const std::string& vendorClientId);

        const AffiliateRelationStatus& getStatus() const;
        void setStatus(const AffiliateRelationStatus& status);


    private:
        /**
         * ID of user
         */
        std::string vendorClientId;
        /**
         * The affiliate relation status
         */
        AffiliateRelationStatus status;
};

}
}

#endif // ACCOUNT_AFFILIATERELATION_H
