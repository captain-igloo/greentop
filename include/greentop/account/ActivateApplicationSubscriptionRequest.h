/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ACTIVATEAPPLICATIONSUBSCRIPTIONREQUEST_H
#define ACCOUNT_ACTIVATEAPPLICATIONSUBSCRIPTIONREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

class ActivateApplicationSubscriptionRequest : public JsonRequest {
    public:
        ActivateApplicationSubscriptionRequest();

        ActivateApplicationSubscriptionRequest(const std::string& subscriptionToken);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getSubscriptionToken() const;
        void setSubscriptionToken(const std::string& subscriptionToken);


    private:
        /**
         * Subscription token for activation
         */
        std::string subscriptionToken;
};

}
}

#endif // ACCOUNT_ACTIVATEAPPLICATIONSUBSCRIPTIONREQUEST_H
