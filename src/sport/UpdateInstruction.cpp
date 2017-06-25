/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UpdateInstruction.h"

namespace greentop {

UpdateInstruction::UpdateInstruction() {
}

UpdateInstruction::UpdateInstruction(const std::string& betId,
    const PersistenceType& newPersistenceType) :
    betId(betId),
    newPersistenceType(newPersistenceType) {
}

void UpdateInstruction::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("newPersistenceType")) {
        newPersistenceType = json["newPersistenceType"].asString();
    }
}

Json::Value UpdateInstruction::toJson() const {
    Json::Value json(Json::objectValue);
    if (betId != "") {
        json["betId"] = betId;
    }
    if (newPersistenceType.isValid()) {
        json["newPersistenceType"] = newPersistenceType.getValue();
    }
    return json;
}

bool UpdateInstruction::isValid() const {
    return betId != "" && newPersistenceType.isValid();
}

const std::string& UpdateInstruction::getBetId() const {
    return betId;
}
void UpdateInstruction::setBetId(const std::string& betId) {
    this->betId = betId;
}

const PersistenceType& UpdateInstruction::getNewPersistenceType() const {
    return newPersistenceType;
}
void UpdateInstruction::setNewPersistenceType(const PersistenceType& newPersistenceType) {
    this->newPersistenceType = newPersistenceType;
}


}



