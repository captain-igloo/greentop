#include "greentop/account/DeveloperApp.h"

namespace greentop {
DeveloperApp::DeveloperApp()  : appId(0){
}

DeveloperApp::DeveloperApp(const std::string& appName,
    const uint64_t appId,
    const std::vector<DeveloperAppVersion>& appVersions) :
    appName(appName),
    appId(appId),
    appVersions(appVersions) {
}

void DeveloperApp::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("appName")) {
            appName = json["appName"].asString();
        }
        if (json.isMember("appId")) {
            appId = json["appId"].asUInt();
        }
        if (json.isMember("appVersions")) {
            for (unsigned i = 0; i < json["appVersions"].size(); ++i) {
                DeveloperAppVersion appVersion;
                appVersion.fromJson(json["appVersions"][i]);
                appVersions.push_back(appVersion);
            };
        }
    }
}

Json::Value DeveloperApp::toJson() const {
    Json::Value json;
    if (appName != "") {
        json["appName"] = appName;
    }
    if (appId >= 0) {
        json["appId"] = appId;
    }
    if (appVersions.size() > 0) {
        for (unsigned i = 0; i < appVersions.size(); ++i) {
            json["appVersions"].append(appVersions[i].toJson());
        };
    }
    return json;
}

bool DeveloperApp::isValid() const {
    return appName != "" && appId >= 0 && appVersions.size() > 0;
}

const std::string& DeveloperApp::getAppName() const {
    return appName;
}
void DeveloperApp::setAppName(const std::string& appName) {
    this->appName = appName;
}

const uint64_t DeveloperApp::getAppId() const {
    return appId;
}
void DeveloperApp::setAppId(const uint64_t appId) {
    this->appId = appId;
}

const std::vector<DeveloperAppVersion>& DeveloperApp::getAppVersions() const {
    return appVersions;
}
void DeveloperApp::setAppVersions(const std::vector<DeveloperAppVersion>& appVersions) {
    this->appVersions = appVersions;
}


}



