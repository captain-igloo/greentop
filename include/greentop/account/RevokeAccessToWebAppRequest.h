/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_REVOKEACCESSTOWEBAPPREQUEST_H
#define ACCOUNT_REVOKEACCESSTOWEBAPPREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"

namespace greentop {
namespace account {

class RevokeAccessToWebAppRequest : public JsonRequest {
    public:
        RevokeAccessToWebAppRequest();

        RevokeAccessToWebAppRequest(const Optional<int64_t>& vendorId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getVendorId() const;
        void setVendorId(const Optional<int64_t>& vendorId);


    private:
        /**
         * The id of the vendor to revoke access for
         */
        Optional<int64_t> vendorId;
};

}
}

#endif // ACCOUNT_REVOKEACCESSTOWEBAPPREQUEST_H
