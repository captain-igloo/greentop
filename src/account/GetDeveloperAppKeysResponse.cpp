/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetDeveloperAppKeysResponse.h"

namespace greentop {

GetDeveloperAppKeysResponse::GetDeveloperAppKeysResponse() {
}

GetDeveloperAppKeysResponse::GetDeveloperAppKeysResponse(const std::vector<DeveloperApp>& developerApps) :
    developerApps(developerApps) {
}

void GetDeveloperAppKeysResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            DeveloperApp developerApp;
            developerApp.fromJson(json[i]);
            developerApps.push_back(developerApp);
        }
    }
}

Json::Value GetDeveloperAppKeysResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (developerApps.size() > 0) {
        for (unsigned i = 0; i < developerApps.size(); ++i) {
            json.append(developerApps[i].toJson());
        }
    }
    return json;
}

bool GetDeveloperAppKeysResponse::isValid() const {
    return developerApps.size() > 0;
}

const std::vector<DeveloperApp>& GetDeveloperAppKeysResponse::getDeveloperApps() const {
    return developerApps;
}
void GetDeveloperAppKeysResponse::setDeveloperApps(const std::vector<DeveloperApp>& developerApps) {
    this->developerApps = developerApps;
}


}



