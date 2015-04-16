#include "greentop/betting/ReplaceInstructionReport.h"

namespace greentop {
ReplaceInstructionReport::ReplaceInstructionReport() {
}

ReplaceInstructionReport::ReplaceInstructionReport(const InstructionReportStatus& status,
    const InstructionReportErrorCode& errorCode,
    const CancelInstructionReport& cancelInstructionReport,
    const PlaceInstructionReport& placeInstructionReport) :
    status(status),
    errorCode(errorCode),
    cancelInstructionReport(cancelInstructionReport),
    placeInstructionReport(placeInstructionReport) {
}

void ReplaceInstructionReport::fromJson(const Json::Value& json) {
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("errorCode")) {
        errorCode = json["errorCode"].asString();
    }
    if (json.isMember("cancelInstructionReport")) {
        cancelInstructionReport.fromJson(json["cancelInstructionReport"]);
    }
    if (json.isMember("placeInstructionReport")) {
        placeInstructionReport.fromJson(json["placeInstructionReport"]);
    }
}

Json::Value ReplaceInstructionReport::toJson() const {
    Json::Value json;
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (errorCode.isValid()) {
        json["errorCode"] = errorCode.getValue();
    }
    if (cancelInstructionReport.isValid()) {
        json["cancelInstructionReport"] = cancelInstructionReport.toJson();
    }
    if (placeInstructionReport.isValid()) {
        json["placeInstructionReport"] = placeInstructionReport.toJson();
    }
    return json;
}

bool ReplaceInstructionReport::isValid() const {
    return status.isValid();
}

const InstructionReportStatus& ReplaceInstructionReport::getStatus() const {
    return status;
}
void ReplaceInstructionReport::setStatus(const InstructionReportStatus& status) {
    this->status = status;
}

const InstructionReportErrorCode& ReplaceInstructionReport::getErrorCode() const {
    return errorCode;
}
void ReplaceInstructionReport::setErrorCode(const InstructionReportErrorCode& errorCode) {
    this->errorCode = errorCode;
}

const CancelInstructionReport& ReplaceInstructionReport::getCancelInstructionReport() const {
    return cancelInstructionReport;
}
void ReplaceInstructionReport::setCancelInstructionReport(const CancelInstructionReport& cancelInstructionReport) {
    this->cancelInstructionReport = cancelInstructionReport;
}

const PlaceInstructionReport& ReplaceInstructionReport::getPlaceInstructionReport() const {
    return placeInstructionReport;
}
void ReplaceInstructionReport::setPlaceInstructionReport(const PlaceInstructionReport& placeInstructionReport) {
    this->placeInstructionReport = placeInstructionReport;
}


}



