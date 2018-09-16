/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACTIVATEAPPLICATIONSUBSCRIPTIONRESPONSE_H
#define ACTIVATEAPPLICATIONSUBSCRIPTIONRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/account/enum/Status.h"

namespace greentop {

class ActivateApplicationSubscriptionResponse : public JsonResponse {
    public:
        ActivateApplicationSubscriptionResponse();

        ActivateApplicationSubscriptionResponse(const Status& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Status& getResponse() const;
        void setResponse(const Status& response);


    private:

        Status response;
};

}

#endif // ACTIVATEAPPLICATIONSUBSCRIPTIONRESPONSE_H
