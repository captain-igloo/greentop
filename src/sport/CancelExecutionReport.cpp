/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/CancelExecutionReport.h"

namespace greentop {


CancelExecutionReport::CancelExecutionReport(const std::string& customerRef,
    const std::string& status,
    const std::string& errorCode,
    const std::string& marketId,
    const std::vector<CancelInstructionReport>& instructionReports) :
    customerRef(customerRef),
    status(status),
    errorCode(errorCode),
    marketId(marketId),
    instructionReports(instructionReports) {
}

void CancelExecutionReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("customerRef")) {
            customerRef = json["customerRef"].asString();
;
        }
        if (json.isMember("status")) {
            status = json["status"].asString();
;
        }
        if (json.isMember("errorCode")) {
            errorCode = json["errorCode"].asString();
;
        }
        if (json.isMember("marketId")) {
            marketId = json["marketId"].asString();
;
        }
        if (json.isMember("instructionReports")) {
            for (unsigned i = 0; i < json["instructionReports"].size(); ++i) {
            CancelInstructionReport instructionReport;
            instructionReport.fromJson(json["instructionReports"][i]);
            instructionReports.push_back(instructionReport);
        }
;
        }
    }
}

Json::Value CancelExecutionReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (customerRef != "") {
        json["customerRef"] = customerRef;
    }
    if (status != "") {
        json["status"] = status;
    }
    if (errorCode != "") {
        json["errorCode"] = errorCode;
    }
    json["marketId"] = marketId;
    if (instructionReports.size() > 0) {
        for (unsigned i = 0; i < instructionReports.size(); ++i) {
            json["instructionReports"].append(instructionReports[i].toJson());
        }
    }
    return json;
}

bool CancelExecutionReport::isValid() const {
    return status != "";
}

const std::string& CancelExecutionReport::getCustomerRef() const {
    return customerRef;
}
void CancelExecutionReport::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}

const std::string& CancelExecutionReport::getStatus() const {
    return status;
}
void CancelExecutionReport::setStatus(const std::string& status) {
    this->status = status;
}

const std::string& CancelExecutionReport::getErrorCode() const {
    return errorCode;
}
void CancelExecutionReport::setErrorCode(const std::string& errorCode) {
    this->errorCode = errorCode;
}

const std::string& CancelExecutionReport::getMarketId() const {
    return marketId;
}
void CancelExecutionReport::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<CancelInstructionReport>& CancelExecutionReport::getInstructionReports() const {
    return instructionReports;
}
void CancelExecutionReport::setInstructionReports(const std::vector<CancelInstructionReport>& instructionReports) {
    this->instructionReports = instructionReports;
}


}



