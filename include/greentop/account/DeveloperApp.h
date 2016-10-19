/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef DEVELOPERAPP_H
#define DEVELOPERAPP_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/DeveloperAppVersion.h"

namespace greentop {

class DeveloperApp : public JsonResponse {
    public:
        DeveloperApp();

        DeveloperApp(const std::string& appName,
            const int64_t appId,
            const std::vector<DeveloperAppVersion>& appVersions);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getAppName() const;
        void setAppName(const std::string& appName);

        const int64_t getAppId() const;
        void setAppId(const int64_t appId);

        const std::vector<DeveloperAppVersion>& getAppVersions() const;
        void setAppVersions(const std::vector<DeveloperAppVersion>& appVersions);


    private:
        std::string appName;
        int64_t appId;
        std::vector<DeveloperAppVersion> appVersions;
};

}

#endif // DEVELOPERAPP_H


