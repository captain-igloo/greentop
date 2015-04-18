/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ReplaceInstruction.h"

namespace greentop {
ReplaceInstruction::ReplaceInstruction()  : newPrice(-1){
}

ReplaceInstruction::ReplaceInstruction(const std::string& betId,
    const double newPrice) :
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
    if (newPrice >= 0) {
        json["newPrice"] = newPrice;
    }
    return json;
}

bool ReplaceInstruction::isValid() const {
    return betId != "" && newPrice >= 0;
}

const std::string& ReplaceInstruction::getBetId() const {
    return betId;
}
void ReplaceInstruction::setBetId(const std::string& betId) {
    this->betId = betId;
}

const double ReplaceInstruction::getNewPrice() const {
    return newPrice;
}
void ReplaceInstruction::setNewPrice(const double newPrice) {
    this->newPrice = newPrice;
}


}



