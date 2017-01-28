/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETVENDORDETAILSREQUEST_H
#define GETVENDORDETAILSREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

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

#endif // GETVENDORDETAILSREQUEST_H


