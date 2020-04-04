/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ISACCOUNTSUBSCRIBEDTOWEBAPPREQUEST_H
#define ACCOUNT_ISACCOUNTSUBSCRIBEDTOWEBAPPREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

class IsAccountSubscribedToWebAppRequest : public JsonRequest {
    public:
        IsAccountSubscribedToWebAppRequest();

        IsAccountSubscribedToWebAppRequest(const std::string& vendorId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorId() const;
        void setVendorId(const std::string& vendorId);


    private:
        /**
         * The id of the vendor to check subscription for
         */
        std::string vendorId;
};

}
}

#endif // ACCOUNT_ISACCOUNTSUBSCRIBEDTOWEBAPPREQUEST_H
