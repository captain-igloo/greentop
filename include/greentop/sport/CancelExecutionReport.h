/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_CANCELEXECUTIONREPORT_H
#define SPORT_CANCELEXECUTIONREPORT_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/CancelInstructionReport.h"
#include "greentop/sport/enum/ExecutionReportErrorCode.h"
#include "greentop/sport/enum/ExecutionReportStatus.h"

namespace greentop {
namespace sport {

class CancelExecutionReport : public JsonResponse {
    public:

        CancelExecutionReport(const std::string& customerRef = std::string(),
            const ExecutionReportStatus& status = ExecutionReportStatus(),
            const ExecutionReportErrorCode& errorCode = ExecutionReportErrorCode(),
            const std::string& marketId = std::string(),
            const std::vector<CancelInstructionReport>& instructionReports = std::vector<CancelInstructionReport>());

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

        const std::vector<CancelInstructionReport>& getInstructionReports() const;
        void setInstructionReports(const std::vector<CancelInstructionReport>& instructionReports);


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

        std::vector<CancelInstructionReport> instructionReports;
};

}
}

#endif // SPORT_CANCELEXECUTIONREPORT_H
