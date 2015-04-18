/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CANCELAPPLICATIONSUBSCRIPTIONREQUEST_H
#define CANCELAPPLICATIONSUBSCRIPTIONREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

class CancelApplicationSubscriptionRequest : public JsonRequest {
    public:
        CancelApplicationSubscriptionRequest();

        CancelApplicationSubscriptionRequest(const std::string& subscriptionToken);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getSubscriptionToken() const;
        void setSubscriptionToken(const std::string& subscriptionToken);


    private:
        std::string subscriptionToken;
};

}

#endif // CANCELAPPLICATIONSUBSCRIPTIONREQUEST_H


