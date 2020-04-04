/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ReplaceExecutionReport.h"

namespace greentop {
namespace sport {


ReplaceExecutionReport::ReplaceExecutionReport(const std::string& customerRef,
    const ExecutionReportStatus& status,
    const ExecutionReportErrorCode& errorCode,
    const std::string& marketId,
    const std::vector<ReplaceInstructionReport>& instructionReports) :
    customerRef(customerRef),
    status(status),
    errorCode(errorCode),
    marketId(marketId),
    instructionReports(instructionReports) {
}

void ReplaceExecutionReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("customerRef")) {
            customerRef = json["customerRef"].asString();
        }
        if (json.isMember("status")) {
            status = json["status"].asString();
        }
        if (json.isMember("errorCode")) {
            errorCode = json["errorCode"].asString();
        }
        if (json.isMember("marketId")) {
            marketId = json["marketId"].asString();
        }
        if (json.isMember("instructionReports")) {
            for (unsigned i = 0; i < json["instructionReports"].size(); ++i) {
                ReplaceInstructionReport instructionReport;
                instructionReport.fromJson(json["instructionReports"][i]);
                instructionReports.push_back(instructionReport);
            }
        }
    }
}

Json::Value ReplaceExecutionReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (customerRef != "") {
        json["customerRef"] = customerRef;
    }
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (errorCode.isValid()) {
        json["errorCode"] = errorCode.getValue();
    }
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (instructionReports.size() > 0) {
        for (unsigned i = 0; i < instructionReports.size(); ++i) {
            json["instructionReports"].append(instructionReports[i].toJson());
        }
    }
    return json;
}

bool ReplaceExecutionReport::isValid() const {
    return status.isValid();
}

const std::string& ReplaceExecutionReport::getCustomerRef() const {
    return customerRef;
}
void ReplaceExecutionReport::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}

const ExecutionReportStatus& ReplaceExecutionReport::getStatus() const {
    return status;
}
void ReplaceExecutionReport::setStatus(const ExecutionReportStatus& status) {
    this->status = status;
}

const ExecutionReportErrorCode& ReplaceExecutionReport::getErrorCode() const {
    return errorCode;
}
void ReplaceExecutionReport::setErrorCode(const ExecutionReportErrorCode& errorCode) {
    this->errorCode = errorCode;
}

const std::string& ReplaceExecutionReport::getMarketId() const {
    return marketId;
}
void ReplaceExecutionReport::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<ReplaceInstructionReport>& ReplaceExecutionReport::getInstructionReports() const {
    return instructionReports;
}
void ReplaceExecutionReport::setInstructionReports(const std::vector<ReplaceInstructionReport>& instructionReports) {
    this->instructionReports = instructionReports;
}


}
}
