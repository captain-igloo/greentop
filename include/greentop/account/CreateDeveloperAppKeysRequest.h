#ifndef CREATEDEVELOPERAPPKEYSREQUEST_H
#define CREATEDEVELOPERAPPKEYSREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

class CreateDeveloperAppKeysRequest : public JsonRequest {
    public:
        CreateDeveloperAppKeysRequest();

        CreateDeveloperAppKeysRequest(const std::string& appName);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getAppName() const;
        void setAppName(const std::string& appName);


    private:
        std::string appName;
};

}

#endif // CREATEDEVELOPERAPPKEYSREQUEST_H


