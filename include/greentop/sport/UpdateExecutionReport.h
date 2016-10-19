/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEEXECUTIONREPORT_H
#define UPDATEEXECUTIONREPORT_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/UpdateInstructionReport.h"

namespace greentop {

class UpdateExecutionReport : public JsonResponse {
    public:

        UpdateExecutionReport(const std::string& customerRef = std::string(),
            const std::string& status = std::string(),
            const std::string& errorCode = std::string(),
            const std::string& marketId = std::string(),
            const std::vector<UpdateInstructionReport>& instructionReports = std::vector<UpdateInstructionReport>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const std::string& getErrorCode() const;
        void setErrorCode(const std::string& errorCode);

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<UpdateInstructionReport>& getInstructionReports() const;
        void setInstructionReports(const std::vector<UpdateInstructionReport>& instructionReports);


    private:
        std::string customerRef;
        std::string status;
        std::string errorCode;
        std::string marketId;
        std::vector<UpdateInstructionReport> instructionReports;
};

}

#endif // UPDATEEXECUTIONREPORT_H


