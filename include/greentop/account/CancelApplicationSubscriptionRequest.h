/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_CANCELAPPLICATIONSUBSCRIPTIONREQUEST_H
#define ACCOUNT_CANCELAPPLICATIONSUBSCRIPTIONREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

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
        /**
         * Subscription token to cancel
         */
        std::string subscriptionToken;
};

}
}

#endif // ACCOUNT_CANCELAPPLICATIONSUBSCRIPTIONREQUEST_H
