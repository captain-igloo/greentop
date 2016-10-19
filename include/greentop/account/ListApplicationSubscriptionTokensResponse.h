/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTAPPLICATIONSUBSCRIPTIONTOKENSRESPONSE_H
#define LISTAPPLICATIONSUBSCRIPTIONTOKENSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/ApplicationSubscription.h"

namespace greentop {

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

#endif // LISTAPPLICATIONSUBSCRIPTIONTOKENSRESPONSE_H


