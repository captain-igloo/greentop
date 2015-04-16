#include "greentop/betting/PlaceInstructionReport.h"

namespace greentop {
PlaceInstructionReport::PlaceInstructionReport()  : averagePriceMatched(-1), sizeMatched(-1){
}

PlaceInstructionReport::PlaceInstructionReport(const InstructionReportStatus& status,
    const InstructionReportErrorCode& errorCode,
    const PlaceInstruction& instruction,
    const std::string& betId,
    const std::tm& placedDate,
    const double averagePriceMatched,
    const double sizeMatched) :
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
    Json::Value json;
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (errorCode.isValid()) {
        json["errorCode"] = errorCode.getValue();
    }
    if (instruction.isValid()) {
        json["instruction"] = instruction.toJson();
    }
    if (betId != "") {
        json["betId"] = betId;
    }
    if (false) {
        // placedDate not implemented;
    }
    if (averagePriceMatched >= 0) {
        json["averagePriceMatched"] = averagePriceMatched;
    }
    if (sizeMatched >= 0) {
        json["sizeMatched"] = sizeMatched;
    }
    return json;
}

bool PlaceInstructionReport::isValid() const {
    return status.isValid() && instruction.isValid();
}

const InstructionReportStatus& PlaceInstructionReport::getStatus() const {
    return status;
}
void PlaceInstructionReport::setStatus(const InstructionReportStatus& status) {
    this->status = status;
}

const InstructionReportErrorCode& PlaceInstructionReport::getErrorCode() const {
    return errorCode;
}
void PlaceInstructionReport::setErrorCode(const InstructionReportErrorCode& errorCode) {
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

const double PlaceInstructionReport::getAveragePriceMatched() const {
    return averagePriceMatched;
}
void PlaceInstructionReport::setAveragePriceMatched(const double averagePriceMatched) {
    this->averagePriceMatched = averagePriceMatched;
}

const double PlaceInstructionReport::getSizeMatched() const {
    return sizeMatched;
}
void PlaceInstructionReport::setSizeMatched(const double sizeMatched) {
    this->sizeMatched = sizeMatched;
}


}



