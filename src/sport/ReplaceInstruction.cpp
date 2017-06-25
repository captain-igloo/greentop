/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ReplaceInstruction.h"

namespace greentop {

ReplaceInstruction::ReplaceInstruction() {
}

ReplaceInstruction::ReplaceInstruction(const std::string& betId,
    const Optional<double>& newPrice) :
    betId(betId),
    newPrice(newPrice) {
}

void ReplaceInstruction::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("newPrice")) {
        newPrice = json["newPrice"].asDouble();
    }
}

Json::Value ReplaceInstruction::toJson() const {
    Json::Value json(Json::objectValue);
    if (betId != "") {
        json["betId"] = betId;
    }
    if (newPrice.isValid()) {
        json["newPrice"] = newPrice.toJson();
    }
    return json;
}

bool ReplaceInstruction::isValid() const {
    return betId != "" && newPrice.isValid();
}

const std::string& ReplaceInstruction::getBetId() const {
    return betId;
}
void ReplaceInstruction::setBetId(const std::string& betId) {
    this->betId = betId;
}

const Optional<double>& ReplaceInstruction::getNewPrice() const {
    return newPrice;
}
void ReplaceInstruction::setNewPrice(const Optional<double>& newPrice) {
    this->newPrice = newPrice;
}


}



