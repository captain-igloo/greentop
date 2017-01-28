/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REPLACEEXECUTIONREPORT_H
#define REPLACEEXECUTIONREPORT_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/ReplaceInstructionReport.h"
#include "greentop/sport/enum/ExecutionReportErrorCode.h"
#include "greentop/sport/enum/ExecutionReportStatus.h"

namespace greentop {

class ReplaceExecutionReport : public JsonResponse {
    public:

        ReplaceExecutionReport(const std::string& customerRef = std::string(),
            const ExecutionReportStatus& status = ExecutionReportStatus(),
            const ExecutionReportErrorCode& errorCode = ExecutionReportErrorCode(),
            const std::string& marketId = std::string(),
            const std::vector<ReplaceInstructionReport>& instructionReports = std::vector<ReplaceInstructionReport>());

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

        const std::vector<ReplaceInstructionReport>& getInstructionReports() const;
        void setInstructionReports(const std::vector<ReplaceInstructionReport>& instructionReports);


    private:
        /**
         * Echo of the customerRef if passed.
         */
        std::string customerRef;
        ExecutionReportStatus status;
        ExecutionReportErrorCode errorCode;
        /**
         * Echo of marketId passed
         */
        std::string marketId;
        std::vector<ReplaceInstructionReport> instructionReports;
};

}

#endif // REPLACEEXECUTIONREPORT_H


