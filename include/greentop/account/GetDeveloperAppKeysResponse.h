/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETDEVELOPERAPPKEYSRESPONSE_H
#define ACCOUNT_GETDEVELOPERAPPKEYSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/DeveloperApp.h"

namespace greentop {
namespace account {

class GetDeveloperAppKeysResponse : public JsonResponse {
    public:
        GetDeveloperAppKeysResponse();

        GetDeveloperAppKeysResponse(const std::vector<DeveloperApp>& developerApps);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<DeveloperApp>& getDeveloperApps() const;
        void setDeveloperApps(const std::vector<DeveloperApp>& developerApps);


    private:

        std::vector<DeveloperApp> developerApps;
};

}
}

#endif // ACCOUNT_GETDEVELOPERAPPKEYSRESPONSE_H
