/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETAPPLICATIONSUBSCRIPTIONTOKENREQUEST_H
#define GETAPPLICATIONSUBSCRIPTIONTOKENREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"

namespace greentop {

class GetApplicationSubscriptionTokenRequest : public JsonRequest {
    public:

        GetApplicationSubscriptionTokenRequest(const Optional<int32_t>& subscriptionLength = Optional<int32_t>(),
            const std::string& clientReference = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int32_t>& getSubscriptionLength() const;
        void setSubscriptionLength(const Optional<int32_t>& subscriptionLength);

        const std::string& getClientReference() const;
        void setClientReference(const std::string& clientReference);


    private:
        Optional<int32_t> subscriptionLength;
        std::string clientReference;
};

}

#endif // GETAPPLICATIONSUBSCRIPTIONTOKENREQUEST_H


