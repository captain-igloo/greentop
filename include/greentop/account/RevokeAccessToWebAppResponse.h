/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_REVOKEACCESSTOWEBAPPRESPONSE_H
#define ACCOUNT_REVOKEACCESSTOWEBAPPRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/account/enum/Status.h"

namespace greentop {
namespace account {

class RevokeAccessToWebAppResponse : public JsonResponse {
    public:
        RevokeAccessToWebAppResponse();

        RevokeAccessToWebAppResponse(const Status& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Status& getResponse() const;
        void setResponse(const Status& response);


    private:

        Status response;
};

}
}

#endif // ACCOUNT_REVOKEACCESSTOWEBAPPRESPONSE_H
