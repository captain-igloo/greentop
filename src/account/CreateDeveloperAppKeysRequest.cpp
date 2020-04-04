/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/CreateDeveloperAppKeysRequest.h"

namespace greentop {
namespace account {

CreateDeveloperAppKeysRequest::CreateDeveloperAppKeysRequest() {
}

CreateDeveloperAppKeysRequest::CreateDeveloperAppKeysRequest(const std::string& appName) :
    appName(appName) {
}

void CreateDeveloperAppKeysRequest::fromJson(const Json::Value& json) {
    if (json.isMember("appName")) {
        appName = json["appName"].asString();
    }
}

Json::Value CreateDeveloperAppKeysRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (appName != "") {
        json["appName"] = appName;
    }
    return json;
}

bool CreateDeveloperAppKeysRequest::isValid() const {
    return appName != "";
}

const std::string& CreateDeveloperAppKeysRequest::getAppName() const {
    return appName;
}
void CreateDeveloperAppKeysRequest::setAppName(const std::string& appName) {
    this->appName = appName;
}


}
}
