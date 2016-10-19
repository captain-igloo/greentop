/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEAPPLICATIONSUBSCRIPTIONREQUEST_H
#define UPDATEAPPLICATIONSUBSCRIPTIONREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

class UpdateApplicationSubscriptionRequest : public JsonRequest {
    public:
        UpdateApplicationSubscriptionRequest();

        UpdateApplicationSubscriptionRequest(const std::string& vendorClientId,
            const int32_t subscriptionLength);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorClientId() const;
        void setVendorClientId(const std::string& vendorClientId);

        const int32_t getSubscriptionLength() const;
        void setSubscriptionLength(const int32_t subscriptionLength);


    private:
        std::string vendorClientId;
        int32_t subscriptionLength;
};

}

#endif // UPDATEAPPLICATIONSUBSCRIPTIONREQUEST_H


