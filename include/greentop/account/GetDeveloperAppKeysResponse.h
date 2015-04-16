#ifndef GETDEVELOPERAPPKEYSRESPONSE_H
#define GETDEVELOPERAPPKEYSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/DeveloperApp.h"

namespace greentop {

class GetDeveloperAppKeysResponse : public JsonResponse {
    public:
        GetDeveloperAppKeysResponse();

        GetDeveloperAppKeysResponse(const std::vector<DeveloperApp>& developerAppKeys);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<DeveloperApp>& getDeveloperAppKeys() const;
        void setDeveloperAppKeys(const std::vector<DeveloperApp>& developerAppKeys);


    private:
        std::vector<DeveloperApp> developerAppKeys;
};

}

#endif // GETDEVELOPERAPPKEYSRESPONSE_H


