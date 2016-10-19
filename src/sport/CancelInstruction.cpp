/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/CancelInstruction.h"

namespace greentop {

CancelInstruction::CancelInstruction() {
}

CancelInstruction::CancelInstruction(const std::string& betId,
    const Optional<double>& sizeReduction) :
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
    Json::Value json(Json::objectValue);
    if (betId != "") {
        json["betId"] = betId;
    }
    if (sizeReduction.isValid()) {
        json["sizeReduction"] = sizeReduction.toJson();
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

const Optional<double>& CancelInstruction::getSizeReduction() const {
    return sizeReduction;
}
void CancelInstruction::setSizeReduction(const Optional<double>& sizeReduction) {
    this->sizeReduction = sizeReduction;
}


}



