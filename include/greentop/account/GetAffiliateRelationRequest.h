/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETAFFILIATERELATIONREQUEST_H
#define ACCOUNT_GETAFFILIATERELATIONREQUEST_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

class GetAffiliateRelationRequest : public JsonRequest {
    public:
        GetAffiliateRelationRequest();

        GetAffiliateRelationRequest(const std::vector<std::string>& vendorClientIds);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<std::string>& getVendorClientIds() const;
        void setVendorClientIds(const std::vector<std::string>& vendorClientIds);


    private:
        /**
         * List of client ids to check affiliation on
         */
        std::vector<std::string> vendorClientIds;
};

}
}

#endif // ACCOUNT_GETAFFILIATERELATIONREQUEST_H
