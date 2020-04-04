/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_LISTAPPLICATIONSUBSCRIPTIONTOKENSREQUEST_H
#define ACCOUNT_LISTAPPLICATIONSUBSCRIPTIONTOKENSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/account/enum/SubscriptionStatus.h"

namespace greentop {
namespace account {

class ListApplicationSubscriptionTokensRequest : public JsonRequest {
    public:

        ListApplicationSubscriptionTokensRequest(const SubscriptionStatus& subscriptionStatus = SubscriptionStatus());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const SubscriptionStatus& getSubscriptionStatus() const;
        void setSubscriptionStatus(const SubscriptionStatus& subscriptionStatus);


    private:
        /**
         * Optionally filter response by Subscription status of the token
         */
        SubscriptionStatus subscriptionStatus;
};

}
}

#endif // ACCOUNT_LISTAPPLICATIONSUBSCRIPTIONTOKENSREQUEST_H
