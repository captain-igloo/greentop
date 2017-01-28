/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ISACCOUNTSUBSCRIBEDTOWEBAPPREQUEST_H
#define ISACCOUNTSUBSCRIBEDTOWEBAPPREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

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

#endif // ISACCOUNTSUBSCRIBEDTOWEBAPPREQUEST_H


