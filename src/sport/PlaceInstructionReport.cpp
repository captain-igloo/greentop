/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PlaceInstructionReport.h"

namespace greentop {

PlaceInstructionReport::PlaceInstructionReport() {
}

PlaceInstructionReport::PlaceInstructionReport(const std::string& status,
    const std::string& errorCode,
    const PlaceInstruction& instruction,
    const std::string& betId,
    const std::tm& placedDate,
    const Optional<double>& averagePriceMatched,
    const Optional<double>& sizeMatched) :
    status(status),
    errorCode(errorCode),
    instruction(instruction),
    betId(betId),
    placedDate(placedDate),
    averagePriceMatched(averagePriceMatched),
    sizeMatched(sizeMatched) {
}

void PlaceInstructionReport::fromJson(const Json::Value& json) {
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("errorCode")) {
        errorCode = json["errorCode"].asString();
    }
    if (json.isMember("instruction")) {
        instruction.fromJson(json["instruction"]);
    }
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("placedDate")) {
        strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
    }
    if (json.isMember("averagePriceMatched")) {
        averagePriceMatched = json["averagePriceMatched"].asDouble();
    }
    if (json.isMember("sizeMatched")) {
        sizeMatched = json["sizeMatched"].asDouble();
    }
}

Json::Value PlaceInstructionReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (status != "") {
        json["status"] = status;
    }
    if (errorCode != "") {
        json["errorCode"] = errorCode;
    }
    if (instruction.isValid()) {
        json["instruction"] = instruction.toJson();
    }
    if (betId != "") {
        json["betId"] = betId;
    }
    if (placedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
        json["placedDate"] = std::string(buffer);
    }
    if (averagePriceMatched.isValid()) {
        json["averagePriceMatched"] = averagePriceMatched.toJson();
    }
    if (sizeMatched.isValid()) {
        json["sizeMatched"] = sizeMatched.toJson();
    }
    return json;
}

bool PlaceInstructionReport::isValid() const {
    return status != "" && instruction.isValid();
}

const std::string& PlaceInstructionReport::getStatus() const {
    return status;
}
void PlaceInstructionReport::setStatus(const std::string& status) {
    this->status = status;
}

const std::string& PlaceInstructionReport::getErrorCode() const {
    return errorCode;
}
void PlaceInstructionReport::setErrorCode(const std::string& errorCode) {
    this->errorCode = errorCode;
}

const PlaceInstruction& PlaceInstructionReport::getInstruction() const {
    return instruction;
}
void PlaceInstructionReport::setInstruction(const PlaceInstruction& instruction) {
    this->instruction = instruction;
}

const std::string& PlaceInstructionReport::getBetId() const {
    return betId;
}
void PlaceInstructionReport::setBetId(const std::string& betId) {
    this->betId = betId;
}

const std::tm& PlaceInstructionReport::getPlacedDate() const {
    return placedDate;
}
void PlaceInstructionReport::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const Optional<double>& PlaceInstructionReport::getAveragePriceMatched() const {
    return averagePriceMatched;
}
void PlaceInstructionReport::setAveragePriceMatched(const Optional<double>& averagePriceMatched) {
    this->averagePriceMatched = averagePriceMatched;
}

const Optional<double>& PlaceInstructionReport::getSizeMatched() const {
    return sizeMatched;
}
void PlaceInstructionReport::setSizeMatched(const Optional<double>& sizeMatched) {
    this->sizeMatched = sizeMatched;
}


}



