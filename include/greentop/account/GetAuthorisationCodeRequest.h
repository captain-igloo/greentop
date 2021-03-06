/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETAUTHORISATIONCODEREQUEST_H
#define ACCOUNT_GETAUTHORISATIONCODEREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

class GetAuthorisationCodeRequest : public JsonRequest {
    public:
        GetAuthorisationCodeRequest();

        GetAuthorisationCodeRequest(const std::string& vendorId);

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

#endif // ACCOUNT_GETAUTHORISATIONCODEREQUEST_H
