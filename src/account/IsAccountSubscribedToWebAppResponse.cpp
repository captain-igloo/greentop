/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/IsAccountSubscribedToWebAppResponse.h"

namespace greentop {

IsAccountSubscribedToWebAppResponse::IsAccountSubscribedToWebAppResponse() {
}

IsAccountSubscribedToWebAppResponse::IsAccountSubscribedToWebAppResponse(const Optional<bool>& isAccountSubscribedToWebApp) :
    isAccountSubscribedToWebApp(isAccountSubscribedToWebApp) {
}

void IsAccountSubscribedToWebAppResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        isAccountSubscribedToWebApp = json["isAccountSubscribedToWebApp"].asBool();
    }
}

Json::Value IsAccountSubscribedToWebAppResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (isAccountSubscribedToWebApp.isValid()) {
        json["isAccountSubscribedToWebApp"] = isAccountSubscribedToWebApp.toJson();
    }
    return json;
}

bool IsAccountSubscribedToWebAppResponse::isValid() const {
    return isAccountSubscribedToWebApp.isValid();
}

const Optional<bool>& IsAccountSubscribedToWebAppResponse::getIsAccountSubscribedToWebApp() const {
    return isAccountSubscribedToWebApp;
}
void IsAccountSubscribedToWebAppResponse::setIsAccountSubscribedToWebApp(const Optional<bool>& isAccountSubscribedToWebApp) {
    this->isAccountSubscribedToWebApp = isAccountSubscribedToWebApp;
}


}



