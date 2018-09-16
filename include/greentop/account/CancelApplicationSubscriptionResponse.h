/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CANCELAPPLICATIONSUBSCRIPTIONRESPONSE_H
#define CANCELAPPLICATIONSUBSCRIPTIONRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/account/enum/Status.h"

namespace greentop {

class CancelApplicationSubscriptionResponse : public JsonResponse {
    public:
        CancelApplicationSubscriptionResponse();

        CancelApplicationSubscriptionResponse(const Status& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Status& getResponse() const;
        void setResponse(const Status& response);


    private:

        Status response;
};

}

#endif // CANCELAPPLICATIONSUBSCRIPTIONRESPONSE_H
