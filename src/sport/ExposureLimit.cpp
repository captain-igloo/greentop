/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ExposureLimit.h"

namespace greentop {


ExposureLimit::ExposureLimit(const Optional<double>& matched,
    const Optional<double>& total,
    const LimitBreachAction& limitBreachAction) :
    matched(matched),
    total(total),
    limitBreachAction(limitBreachAction) {
}

void ExposureLimit::fromJson(const Json::Value& json) {
    if (json.isMember("matched")) {
        matched = json["matched"].asDouble();
    }
    if (json.isMember("total")) {
        total = json["total"].asDouble();
    }
    if (json.isMember("limitBreachAction")) {
        limitBreachAction.fromJson(json["limitBreachAction"]);
    }
}

Json::Value ExposureLimit::toJson() const {
    Json::Value json(Json::objectValue);
    if (matched.isValid()) {
        json["matched"] = matched.toJson();
    }
    if (total.isValid()) {
        json["total"] = total.toJson();
    }
    if (limitBreachAction.isValid()) {
        json["limitBreachAction"] = limitBreachAction.toJson();
    }
    return json;
}

bool ExposureLimit::isValid() const {
    return true;
}

const Optional<double>& ExposureLimit::getMatched() const {
    return matched;
}
void ExposureLimit::setMatched(const Optional<double>& matched) {
    this->matched = matched;
}

const Optional<double>& ExposureLimit::getTotal() const {
    return total;
}
void ExposureLimit::setTotal(const Optional<double>& total) {
    this->total = total;
}

const LimitBreachAction& ExposureLimit::getLimitBreachAction() const {
    return limitBreachAction;
}
void ExposureLimit::setLimitBreachAction(const LimitBreachAction& limitBreachAction) {
    this->limitBreachAction = limitBreachAction;
}


}



