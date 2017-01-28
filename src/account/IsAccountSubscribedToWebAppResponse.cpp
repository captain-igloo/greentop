/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/IsAccountSubscribedToWebAppResponse.h"

namespace greentop {

IsAccountSubscribedToWebAppResponse::IsAccountSubscribedToWebAppResponse() {
}

IsAccountSubscribedToWebAppResponse::IsAccountSubscribedToWebAppResponse(const bool isAccountSubscribedToWebApp) :
    isAccountSubscribedToWebApp(isAccountSubscribedToWebApp) {
}

void IsAccountSubscribedToWebAppResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("isAccountSubscribedToWebApp")) {
            isAccountSubscribedToWebApp = json["isAccountSubscribedToWebApp"].asBool();
;
        }
    }
}

Json::Value IsAccountSubscribedToWebAppResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    json["isAccountSubscribedToWebApp"] = isAccountSubscribedToWebApp;
    return json;
}

bool IsAccountSubscribedToWebAppResponse::isValid() const {
    return true;
}

const bool IsAccountSubscribedToWebAppResponse::getIsAccountSubscribedToWebApp() const {
    return isAccountSubscribedToWebApp;
}
void IsAccountSubscribedToWebAppResponse::setIsAccountSubscribedToWebApp(const bool isAccountSubscribedToWebApp) {
    this->isAccountSubscribedToWebApp = isAccountSubscribedToWebApp;
}


}



