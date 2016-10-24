/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CANCELINSTRUCTIONREPORT_H
#define CANCELINSTRUCTIONREPORT_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/CancelInstruction.h"

namespace greentop {

class CancelInstructionReport : public JsonMember {
    public:
        CancelInstructionReport();

        CancelInstructionReport(const std::string& status,
            const std::string& errorCode = std::string(),
            const CancelInstruction& instruction = CancelInstruction(),
            const Optional<double>& sizeCancelled = Optional<double>(),
            const std::tm& cancelledDate = std::tm());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const std::string& getErrorCode() const;
        void setErrorCode(const std::string& errorCode);

        const CancelInstruction& getInstruction() const;
        void setInstruction(const CancelInstruction& instruction);

        const Optional<double>& getSizeCancelled() const;
        void setSizeCancelled(const Optional<double>& sizeCancelled);

        const std::tm& getCancelledDate() const;
        void setCancelledDate(const std::tm& cancelledDate);


    private:
        /**
         * whether the command succeeded or failed
         */
        std::string status;
        /**
         * cause of failure, or null if command succeeds
         */
        std::string errorCode;
        /**
         * The instruction that was requested
         */
        CancelInstruction instruction;
        Optional<double> sizeCancelled;
        std::tm cancelledDate;
};

}

#endif // CANCELINSTRUCTIONREPORT_H


