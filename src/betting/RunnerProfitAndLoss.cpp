/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/RunnerProfitAndLoss.h"

namespace greentop {

RunnerProfitAndLoss::RunnerProfitAndLoss(const uint64_t selectionId,
    const Optional<double>& ifWin,
    const Optional<double>& ifLose) :
    selectionId(selectionId),
    ifWin(ifWin),
    ifLose(ifLose) {
}

void RunnerProfitAndLoss::fromJson(const Json::Value& json) {
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asUInt64();
    }
    if (json.isMember("ifWin")) {
        ifWin.fromJson(json["ifWin"]);
    }
    if (json.isMember("ifLose")) {
        ifLose.fromJson(json["ifLose"]);
    }
}

Json::Value RunnerProfitAndLoss::toJson() const {
    Json::Value json(Json::objectValue);
    if (selectionId > 0) {
        json["selectionId"] = selectionId;
    }
    if (ifWin.isValid()) {
        json["ifWin"] = ifWin.toJson();
    }
    if (ifLose.isValid()) {
        json["ifLose"] = ifLose.toJson();
    }
    return json;
}

bool RunnerProfitAndLoss::isValid() const {
    return true;
}

const uint64_t RunnerProfitAndLoss::getSelectionId() const {
    return selectionId;
}
void RunnerProfitAndLoss::setSelectionId(const uint64_t selectionId) {
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


}



