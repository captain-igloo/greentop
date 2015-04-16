#include "greentop/heartbeat/HeartbeatReport.h"

namespace greentop {

HeartbeatReport::HeartbeatReport(const ActionPerformed& actionPerformed,
    const int actualTimeoutSeconds) :
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
    Json::Value json;
    if (actionPerformed.isValid()) {
        json["actionPerformed"] = actionPerformed.getValue();
    }
    if (actualTimeoutSeconds >= 0) {
        json["actualTimeoutSeconds"] = actualTimeoutSeconds;
    }
    return json;
}

bool HeartbeatReport::isValid() const {
    return true;
}

const ActionPerformed& HeartbeatReport::getActionPerformed() const {
    return actionPerformed;
}
void HeartbeatReport::setActionPerformed(const ActionPerformed& actionPerformed) {
    this->actionPerformed = actionPerformed;
}

const int HeartbeatReport::getActualTimeoutSeconds() const {
    return actualTimeoutSeconds;
}
void HeartbeatReport::setActualTimeoutSeconds(const int actualTimeoutSeconds) {
    this->actualTimeoutSeconds = actualTimeoutSeconds;
}


}



