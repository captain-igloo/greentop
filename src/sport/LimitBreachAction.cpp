/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/LimitBreachAction.h"

namespace greentop {
namespace sport {

LimitBreachAction::LimitBreachAction() {
}

LimitBreachAction::LimitBreachAction(const LimitBreachActionType& actionType) :
    actionType(actionType) {
}

void LimitBreachAction::fromJson(const Json::Value& json) {
    if (json.isMember("actionType")) {
        actionType = json["actionType"].asString();
    }
}

Json::Value LimitBreachAction::toJson() const {
    Json::Value json(Json::objectValue);
    if (actionType.isValid()) {
        json["actionType"] = actionType.getValue();
    }
    return json;
}

bool LimitBreachAction::isValid() const {
    return actionType.isValid();
}

const LimitBreachActionType& LimitBreachAction::getActionType() const {
    return actionType;
}
void LimitBreachAction::setActionType(const LimitBreachActionType& actionType) {
    this->actionType = actionType;
}


}
}
