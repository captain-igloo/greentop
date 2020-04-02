/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_LISTAPPLICATIONSUBSCRIPTIONTOKENSRESPONSE_H
#define ACCOUNT_LISTAPPLICATIONSUBSCRIPTIONTOKENSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/ApplicationSubscription.h"

namespace greentop {
namespace account {

class ListApplicationSubscriptionTokensResponse : public JsonResponse {
    public:
        ListApplicationSubscriptionTokensResponse();

        ListApplicationSubscriptionTokensResponse(const std::vector<ApplicationSubscription>& applicationSubscriptions);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<ApplicationSubscription>& getApplicationSubscriptions() const;
        void setApplicationSubscriptions(const std::vector<ApplicationSubscription>& applicationSubscriptions);


    private:

        std::vector<ApplicationSubscription> applicationSubscriptions;
};

}
}

#endif // ACCOUNT_LISTAPPLICATIONSUBSCRIPTIONTOKENSRESPONSE_H
