/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEEXECUTIONREPORT_H
#define UPDATEEXECUTIONREPORT_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/UpdateInstructionReport.h"
#include "greentop/sport/enum/ExecutionReportErrorCode.h"
#include "greentop/sport/enum/ExecutionReportStatus.h"

namespace greentop {

class UpdateExecutionReport : public JsonResponse {
    public:

        UpdateExecutionReport(const std::string& customerRef = std::string(),
            const ExecutionReportStatus& status = ExecutionReportStatus(),
            const ExecutionReportErrorCode& errorCode = ExecutionReportErrorCode(),
            const std::string& marketId = std::string(),
            const std::vector<UpdateInstructionReport>& instructionReports = std::vector<UpdateInstructionReport>());

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

        const std::vector<UpdateInstructionReport>& getInstructionReports() const;
        void setInstructionReports(const std::vector<UpdateInstructionReport>& instructionReports);


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

        std::vector<UpdateInstructionReport> instructionReports;
};

}

#endif // UPDATEEXECUTIONREPORT_H
