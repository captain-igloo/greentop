#include "greentop/betting/RunnerProfitAndLoss.h"

namespace greentop {

RunnerProfitAndLoss::RunnerProfitAndLoss(const double selectionId,
    const double ifWin,
    const double ifLose) :
    selectionId(selectionId),
    ifWin(ifWin),
    ifLose(ifLose) {
}

void RunnerProfitAndLoss::fromJson(const Json::Value& json) {
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asDouble();
    }
    if (json.isMember("ifWin")) {
        ifWin = json["ifWin"].asDouble();
    }
    if (json.isMember("ifLose")) {
        ifLose = json["ifLose"].asDouble();
    }
}

Json::Value RunnerProfitAndLoss::toJson() const {
    Json::Value json;
    if (selectionId >= 0) {
        json["selectionId"] = selectionId;
    }
    if (ifWin >= 0) {
        json["ifWin"] = ifWin;
    }
    if (ifLose >= 0) {
        json["ifLose"] = ifLose;
    }
    return json;
}

bool RunnerProfitAndLoss::isValid() const {
    return true;
}

const double RunnerProfitAndLoss::getSelectionId() const {
    return selectionId;
}
void RunnerProfitAndLoss::setSelectionId(const double selectionId) {
    this->selectionId = selectionId;
}

const double RunnerProfitAndLoss::getIfWin() const {
    return ifWin;
}
void RunnerProfitAndLoss::setIfWin(const double ifWin) {
    this->ifWin = ifWin;
}

const double RunnerProfitAndLoss::getIfLose() const {
    return ifLose;
}
void RunnerProfitAndLoss::setIfLose(const double ifLose) {
    this->ifLose = ifLose;
}


}



