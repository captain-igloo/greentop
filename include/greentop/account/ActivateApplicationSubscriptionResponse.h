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

        ActivateApplicationSubscriptionResponse(const Status& status);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Status& getStatus() const;
        void setStatus(const Status& status);


    private:

        Status status;
};

}

#endif // ACTIVATEAPPLICATIONSUBSCRIPTIONRESPONSE_H
