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

namespace greentop {

class ReplaceExecutionReport : public JsonResponse {
    public:

        ReplaceExecutionReport(const std::string& customerRef = std::string(),
            const std::string& status = std::string(),
            const std::string& errorCode = std::string(),
            const std::string& marketId = std::string(),
            const std::vector<ReplaceInstructionReport>& instructionReports = std::vector<ReplaceInstructionReport>());

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

        const std::vector<ReplaceInstructionReport>& getInstructionReports() const;
        void setInstructionReports(const std::vector<ReplaceInstructionReport>& instructionReports);


    private:
        /**
         * Echo of the customerRef if passed.
         */
        std::string customerRef;
        std::string status;
        std::string errorCode;
        /**
         * Echo of marketId passed
         */
        std::string marketId;
        std::vector<ReplaceInstructionReport> instructionReports;
};

}

#endif // REPLACEEXECUTIONREPORT_H


