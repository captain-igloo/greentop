/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetDeveloperAppKeysResponse.h"

namespace greentop {
GetDeveloperAppKeysResponse::GetDeveloperAppKeysResponse() {
}

GetDeveloperAppKeysResponse::GetDeveloperAppKeysResponse(const std::vector<DeveloperApp>& developerAppKeys) :
    developerAppKeys(developerAppKeys) {
}

void GetDeveloperAppKeysResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            DeveloperApp developerAppKey;
            developerAppKey.fromJson(json[i]);
            developerAppKeys.push_back(developerAppKey);
        };
    }
}

Json::Value GetDeveloperAppKeysResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (developerAppKeys.size() > 0) {
        for (unsigned i = 0; i < developerAppKeys.size(); ++i) {
            json.append(developerAppKeys[i].toJson());
        };
    }
    return json;
}

bool GetDeveloperAppKeysResponse::isValid() const {
    return developerAppKeys.size() > 0;
}

const std::vector<DeveloperApp>& GetDeveloperAppKeysResponse::getDeveloperAppKeys() const {
    return developerAppKeys;
}
void GetDeveloperAppKeysResponse::setDeveloperAppKeys(const std::vector<DeveloperApp>& developerAppKeys) {
    this->developerAppKeys = developerAppKeys;
}


}



