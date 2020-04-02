/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PlaceExecutionReport.h"

namespace greentop {
namespace sport {


PlaceExecutionReport::PlaceExecutionReport(const std::string& customerRef,
    const ExecutionReportStatus& status,
    const ExecutionReportErrorCode& errorCode,
    const std::string& marketId,
    const std::vector<PlaceInstructionReport>& instructionReports) :
    customerRef(customerRef),
    status(status),
    errorCode(errorCode),
    marketId(marketId),
    instructionReports(instructionReports) {
}

void PlaceExecutionReport::fromJson(const Json::Value& json) {
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
                PlaceInstructionReport instructionReport;
                instructionReport.fromJson(json["instructionReports"][i]);
                instructionReports.push_back(instructionReport);
            }
        }
    }
}

Json::Value PlaceExecutionReport::toJson() const {
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

bool PlaceExecutionReport::isValid() const {
    return status.isValid();
}

const std::string& PlaceExecutionReport::getCustomerRef() const {
    return customerRef;
}
void PlaceExecutionReport::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}

const ExecutionReportStatus& PlaceExecutionReport::getStatus() const {
    return status;
}
void PlaceExecutionReport::setStatus(const ExecutionReportStatus& status) {
    this->status = status;
}

const ExecutionReportErrorCode& PlaceExecutionReport::getErrorCode() const {
    return errorCode;
}
void PlaceExecutionReport::setErrorCode(const ExecutionReportErrorCode& errorCode) {
    this->errorCode = errorCode;
}

const std::string& PlaceExecutionReport::getMarketId() const {
    return marketId;
}
void PlaceExecutionReport::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<PlaceInstructionReport>& PlaceExecutionReport::getInstructionReports() const {
    return instructionReports;
}
void PlaceExecutionReport::setInstructionReports(const std::vector<PlaceInstructionReport>& instructionReports) {
    this->instructionReports = instructionReports;
}


}
}
