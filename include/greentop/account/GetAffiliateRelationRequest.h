/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETAFFILIATERELATIONREQUEST_H
#define GETAFFILIATERELATIONREQUEST_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonRequest.h"

namespace greentop {

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

#endif // GETAFFILIATERELATIONREQUEST_H
