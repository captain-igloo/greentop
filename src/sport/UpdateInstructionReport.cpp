/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UpdateInstructionReport.h"

namespace greentop {

UpdateInstructionReport::UpdateInstructionReport() {
}

UpdateInstructionReport::UpdateInstructionReport(const InstructionReportStatus& status,
    const InstructionReportErrorCode& errorCode,
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
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (errorCode.isValid()) {
        json["errorCode"] = errorCode.getValue();
    }
    if (instruction.isValid()) {
        json["instruction"] = instruction.toJson();
    }
    return json;
}

bool UpdateInstructionReport::isValid() const {
    return status.isValid() && instruction.isValid();
}

const InstructionReportStatus& UpdateInstructionReport::getStatus() const {
    return status;
}
void UpdateInstructionReport::setStatus(const InstructionReportStatus& status) {
    this->status = status;
}

const InstructionReportErrorCode& UpdateInstructionReport::getErrorCode() const {
    return errorCode;
}
void UpdateInstructionReport::setErrorCode(const InstructionReportErrorCode& errorCode) {
    this->errorCode = errorCode;
}

const UpdateInstruction& UpdateInstructionReport::getInstruction() const {
    return instruction;
}
void UpdateInstructionReport::setInstruction(const UpdateInstruction& instruction) {
    this->instruction = instruction;
}


}



