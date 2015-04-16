#include "greentop/betting/CancelInstruction.h"

namespace greentop {
CancelInstruction::CancelInstruction()  : sizeReduction(-1){
}

CancelInstruction::CancelInstruction(const std::string& betId,
    const double sizeReduction) :
    betId(betId),
    sizeReduction(sizeReduction) {
}

void CancelInstruction::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("sizeReduction")) {
        sizeReduction = json["sizeReduction"].asDouble();
    }
}

Json::Value CancelInstruction::toJson() const {
    Json::Value json;
    if (betId != "") {
        json["betId"] = betId;
    }
    if (sizeReduction >= 0) {
        json["sizeReduction"] = sizeReduction;
    }
    return json;
}

bool CancelInstruction::isValid() const {
    return betId != "";
}

const std::string& CancelInstruction::getBetId() const {
    return betId;
}
void CancelInstruction::setBetId(const std::string& betId) {
    this->betId = betId;
}

const double CancelInstruction::getSizeReduction() const {
    return sizeReduction;
}
void CancelInstruction::setSizeReduction(const double sizeReduction) {
    this->sizeReduction = sizeReduction;
}


}



