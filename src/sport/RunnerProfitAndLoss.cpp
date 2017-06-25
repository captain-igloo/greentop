/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RunnerProfitAndLoss.h"

namespace greentop {


RunnerProfitAndLoss::RunnerProfitAndLoss(const Optional<int64_t>& selectionId,
    const Optional<double>& ifWin,
    const Optional<double>& ifLose,
    const Optional<double>& ifPlace) :
    selectionId(selectionId),
    ifWin(ifWin),
    ifLose(ifLose),
    ifPlace(ifPlace) {
}

void RunnerProfitAndLoss::fromJson(const Json::Value& json) {
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("ifWin")) {
        ifWin = json["ifWin"].asDouble();
    }
    if (json.isMember("ifLose")) {
        ifLose = json["ifLose"].asDouble();
    }
    if (json.isMember("ifPlace")) {
        ifPlace = json["ifPlace"].asDouble();
    }
}

Json::Value RunnerProfitAndLoss::toJson() const {
    Json::Value json(Json::objectValue);
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (ifWin.isValid()) {
        json["ifWin"] = ifWin.toJson();
    }
    if (ifLose.isValid()) {
        json["ifLose"] = ifLose.toJson();
    }
    if (ifPlace.isValid()) {
        json["ifPlace"] = ifPlace.toJson();
    }
    return json;
}

bool RunnerProfitAndLoss::isValid() const {
    return true;
}

const Optional<int64_t>& RunnerProfitAndLoss::getSelectionId() const {
    return selectionId;
}
void RunnerProfitAndLoss::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& RunnerProfitAndLoss::getIfWin() const {
    return ifWin;
}
void RunnerProfitAndLoss::setIfWin(const Optional<double>& ifWin) {
    this->ifWin = ifWin;
}

const Optional<double>& RunnerProfitAndLoss::getIfLose() const {
    return ifLose;
}
void RunnerProfitAndLoss::setIfLose(const Optional<double>& ifLose) {
    this->ifLose = ifLose;
}

const Optional<double>& RunnerProfitAndLoss::getIfPlace() const {
    return ifPlace;
}
void RunnerProfitAndLoss::setIfPlace(const Optional<double>& ifPlace) {
    this->ifPlace = ifPlace;
}


}



