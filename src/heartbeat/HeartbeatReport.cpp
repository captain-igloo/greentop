/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/heartbeat/HeartbeatReport.h"

namespace greentop {

HeartbeatReport::HeartbeatReport() {
}

HeartbeatReport::HeartbeatReport(const ActionPerformed& actionPerformed,
    const Optional<int32_t>& actualTimeoutSeconds) :
    actionPerformed(actionPerformed),
    actualTimeoutSeconds(actualTimeoutSeconds) {
}

void HeartbeatReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("actionPerformed")) {
            actionPerformed = json["actionPerformed"].asString();
        }
        if (json.isMember("actualTimeoutSeconds")) {
            actualTimeoutSeconds = json["actualTimeoutSeconds"].asInt();
        }
    }
}

Json::Value HeartbeatReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (actionPerformed.isValid()) {
        json["actionPerformed"] = actionPerformed.getValue();
    }
    if (actualTimeoutSeconds.isValid()) {
        json["actualTimeoutSeconds"] = actualTimeoutSeconds.toJson();
    }
    return json;
}

bool HeartbeatReport::isValid() const {
    return actionPerformed.isValid() && actualTimeoutSeconds.isValid();
}

const ActionPerformed& HeartbeatReport::getActionPerformed() const {
    return actionPerformed;
}
void HeartbeatReport::setActionPerformed(const ActionPerformed& actionPerformed) {
    this->actionPerformed = actionPerformed;
}

const Optional<int32_t>& HeartbeatReport::getActualTimeoutSeconds() const {
    return actualTimeoutSeconds;
}
void HeartbeatReport::setActualTimeoutSeconds(const Optional<int32_t>& actualTimeoutSeconds) {
    this->actualTimeoutSeconds = actualTimeoutSeconds;
}


}



