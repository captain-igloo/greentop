/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UpdateInstructionReport.h"

namespace greentop {

UpdateInstructionReport::UpdateInstructionReport() {
}

UpdateInstructionReport::UpdateInstructionReport(const std::string& status,
    const std::string& errorCode,
    const UpdateInstruction& instruction) :
    status(status),
    errorCode(errorCode),
    instruction(instruction) {
}

void UpdateInstructionReport::fromJson(const Json::Value& json) {
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("errorCode")) {
        errorCode = json["errorCode"].asString();
    }
    if (json.isMember("instruction")) {
        instruction.fromJson(json["instruction"]);
    }
}

Json::Value UpdateInstructionReport::toJson() const {
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
    return json;
}

bool UpdateInstructionReport::isValid() const {
    return status != "" && instruction.isValid();
}

const std::string& UpdateInstructionReport::getStatus() const {
    return status;
}
void UpdateInstructionReport::setStatus(const std::string& status) {
    this->status = status;
}

const std::string& UpdateInstructionReport::getErrorCode() const {
    return errorCode;
}
void UpdateInstructionReport::setErrorCode(const std::string& errorCode) {
    this->errorCode = errorCode;
}

const UpdateInstruction& UpdateInstructionReport::getInstruction() const {
    return instruction;
}
void UpdateInstructionReport::setInstruction(const UpdateInstruction& instruction) {
    this->instruction = instruction;
}


}



