/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTACCOUNTSUBSCRIPTIONTOKENSRESPONSE_H
#define LISTACCOUNTSUBSCRIPTIONTOKENSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/AccountSubscription.h"

namespace greentop {

class ListAccountSubscriptionTokensResponse : public JsonResponse {
    public:
        ListAccountSubscriptionTokensResponse();

        ListAccountSubscriptionTokensResponse(const std::vector<AccountSubscription>& accountSubscriptions);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<AccountSubscription>& getAccountSubscriptions() const;
        void setAccountSubscriptions(const std::vector<AccountSubscription>& accountSubscriptions);


    private:

        std::vector<AccountSubscription> accountSubscriptions;
};

}

#endif // LISTACCOUNTSUBSCRIPTIONTOKENSRESPONSE_H
