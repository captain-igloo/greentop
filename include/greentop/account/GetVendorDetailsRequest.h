/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETVENDORDETAILSREQUEST_H
#define ACCOUNT_GETVENDORDETAILSREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

class GetVendorDetailsRequest : public JsonRequest {
    public:
        GetVendorDetailsRequest();

        GetVendorDetailsRequest(const std::string& vendorId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorId() const;
        void setVendorId(const std::string& vendorId);


    private:
        /**
         * The vendor's public identifier
         */
        std::string vendorId;
};

}
}

#endif // ACCOUNT_GETVENDORDETAILSREQUEST_H
