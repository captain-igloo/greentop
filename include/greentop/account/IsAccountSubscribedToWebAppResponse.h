/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ISACCOUNTSUBSCRIBEDTOWEBAPPRESPONSE_H
#define ACCOUNT_ISACCOUNTSUBSCRIBEDTOWEBAPPRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"

namespace greentop {
namespace account {

class IsAccountSubscribedToWebAppResponse : public JsonResponse {
    public:
        IsAccountSubscribedToWebAppResponse();

        IsAccountSubscribedToWebAppResponse(const Optional<bool>& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<bool>& getResponse() const;
        void setResponse(const Optional<bool>& response);


    private:

        Optional<bool> response;
};

}
}

#endif // ACCOUNT_ISACCOUNTSUBSCRIBEDTOWEBAPPRESPONSE_H
