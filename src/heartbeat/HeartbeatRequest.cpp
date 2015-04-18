/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/heartbeat/HeartbeatRequest.h"

namespace greentop {
HeartbeatRequest::HeartbeatRequest()  : preferredTimeoutSeconds(-1){
}

HeartbeatRequest::HeartbeatRequest(const int preferredTimeoutSeconds) :
    preferredTimeoutSeconds(preferredTimeoutSeconds) {
}

void HeartbeatRequest::fromJson(const Json::Value& json) {
    if (json.isMember("preferredTimeoutSeconds")) {
        preferredTimeoutSeconds = json["preferredTimeoutSeconds"].asInt();
    }
}

Json::Value HeartbeatRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (preferredTimeoutSeconds >= 0) {
        json["preferredTimeoutSeconds"] = preferredTimeoutSeconds;
    }
    return json;
}

bool HeartbeatRequest::isValid() const {
    return preferredTimeoutSeconds >= 0;
}

const int HeartbeatRequest::getPreferredTimeoutSeconds() const {
    return preferredTimeoutSeconds;
}
void HeartbeatRequest::setPreferredTimeoutSeconds(const int preferredTimeoutSeconds) {
    this->preferredTimeoutSeconds = preferredTimeoutSeconds;
}


}



