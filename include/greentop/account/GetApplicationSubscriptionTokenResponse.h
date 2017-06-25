/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETAPPLICATIONSUBSCRIPTIONTOKENRESPONSE_H
#define GETAPPLICATIONSUBSCRIPTIONTOKENRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {

class GetApplicationSubscriptionTokenResponse : public JsonResponse {
    public:
        GetApplicationSubscriptionTokenResponse();

        GetApplicationSubscriptionTokenResponse(const std::string& subscriptionToken);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getSubscriptionToken() const;
        void setSubscriptionToken(const std::string& subscriptionToken);


    private:

        std::string subscriptionToken;
};

}

#endif // GETAPPLICATIONSUBSCRIPTIONTOKENRESPONSE_H
