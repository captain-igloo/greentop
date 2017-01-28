/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REVOKEACCESSTOWEBAPPREQUEST_H
#define REVOKEACCESSTOWEBAPPREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"

namespace greentop {

class RevokeAccessToWebAppRequest : public JsonRequest {
    public:
        RevokeAccessToWebAppRequest();

        RevokeAccessToWebAppRequest(const int64_t vendorId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const int64_t getVendorId() const;
        void setVendorId(const int64_t vendorId);


    private:
        /**
         * The id of the vendor to revoke access for
         */
        int64_t vendorId;
};

}

#endif // REVOKEACCESSTOWEBAPPREQUEST_H


