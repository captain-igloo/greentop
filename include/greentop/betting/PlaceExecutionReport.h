/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEEXECUTIONREPORT_H
#define PLACEEXECUTIONREPORT_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/PlaceInstructionReport.h"
#include "greentop/enum/ExecutionReportErrorCode.h"
#include "greentop/enum/ExecutionReportStatus.h"

namespace greentop {

class PlaceExecutionReport : public JsonResponse {
    public:

        PlaceExecutionReport(const std::string& customerRef = std::string(),
            const ExecutionReportStatus& status = ExecutionReportStatus(),
            const ExecutionReportErrorCode& errorCode = ExecutionReportErrorCode(),
            const std::string& marketId = std::string(),
            const std::vector<PlaceInstructionReport>& instructionReports = std::vector<PlaceInstructionReport>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);

        const ExecutionReportStatus& getStatus() const;
        void setStatus(const ExecutionReportStatus& status);

        const ExecutionReportErrorCode& getErrorCode() const;
        void setErrorCode(const ExecutionReportErrorCode& errorCode);

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<PlaceInstructionReport>& getInstructionReports() const;
        void setInstructionReports(const std::vector<PlaceInstructionReport>& instructionReports);


    private:
        std::string customerRef;
        ExecutionReportStatus status;
        ExecutionReportErrorCode errorCode;
        std::string marketId;
        std::vector<PlaceInstructionReport> instructionReports;
};

}

#endif // PLACEEXECUTIONREPORT_H


