/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ISACCOUNTSUBSCRIBEDTOWEBAPPRESPONSE_H
#define ISACCOUNTSUBSCRIBEDTOWEBAPPRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"

namespace greentop {

class IsAccountSubscribedToWebAppResponse : public JsonResponse {
    public:
        IsAccountSubscribedToWebAppResponse();

        IsAccountSubscribedToWebAppResponse(const bool isAccountSubscribedToWebApp);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const bool getIsAccountSubscribedToWebApp() const;
        void setIsAccountSubscribedToWebApp(const bool isAccountSubscribedToWebApp);


    private:
        Optional<bool> isAccountSubscribedToWebApp;
};

}

#endif // ISACCOUNTSUBSCRIBEDTOWEBAPPRESPONSE_H


