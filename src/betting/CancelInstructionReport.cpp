/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/CancelInstructionReport.h"

namespace greentop {
CancelInstructionReport::CancelInstructionReport()  : sizeCancelled(-1){
}

CancelInstructionReport::CancelInstructionReport(const InstructionReportStatus& status,
    const InstructionReportErrorCode& errorCode,
    const CancelInstruction& instruction,
    const double sizeCancelled,
    const std::tm& cancelledDate) :
    status(status),
    errorCode(errorCode),
    instruction(instruction),
    sizeCancelled(sizeCancelled),
    cancelledDate(cancelledDate) {
}

void CancelInstructionReport::fromJson(const Json::Value& json) {
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("errorCode")) {
        errorCode = json["errorCode"].asString();
    }
    if (json.isMember("instruction")) {
        instruction.fromJson(json["instruction"]);
    }
    if (json.isMember("sizeCancelled")) {
        sizeCancelled = json["sizeCancelled"].asDouble();
    }
    if (json.isMember("cancelledDate")) {
        strptime(json["cancelledDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &cancelledDate);
    }
}

Json::Value CancelInstructionReport::toJson() const {
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
    if (sizeCancelled >= 0) {
        json["sizeCancelled"] = sizeCancelled;
    }
    if (cancelledDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &cancelledDate);
        json["cancelledDate"] = std::string(buffer);
    }
    return json;
}

bool CancelInstructionReport::isValid() const {
    return status.isValid() && sizeCancelled >= 0;
}

const InstructionReportStatus& CancelInstructionReport::getStatus() const {
    return status;
}
void CancelInstructionReport::setStatus(const InstructionReportStatus& status) {
    this->status = status;
}

const InstructionReportErrorCode& CancelInstructionReport::getErrorCode() const {
    return errorCode;
}
void CancelInstructionReport::setErrorCode(const InstructionReportErrorCode& errorCode) {
    this->errorCode = errorCode;
}

const CancelInstruction& CancelInstructionReport::getInstruction() const {
    return instruction;
}
void CancelInstructionReport::setInstruction(const CancelInstruction& instruction) {
    this->instruction = instruction;
}

const double CancelInstructionReport::getSizeCancelled() const {
    return sizeCancelled;
}
void CancelInstructionReport::setSizeCancelled(const double sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}

const std::tm& CancelInstructionReport::getCancelledDate() const {
    return cancelledDate;
}
void CancelInstructionReport::setCancelledDate(const std::tm& cancelledDate) {
    this->cancelledDate = cancelledDate;
}


}



