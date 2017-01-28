/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CANCELINSTRUCTIONREPORT_H
#define CANCELINSTRUCTIONREPORT_H

#include <ctime>
#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/CancelInstruction.h"
#include "greentop/sport/enum/InstructionReportErrorCode.h"
#include "greentop/sport/enum/InstructionReportStatus.h"

namespace greentop {

class CancelInstructionReport : public JsonMember {
    public:
        CancelInstructionReport();

        CancelInstructionReport(const InstructionReportStatus& status,
            const InstructionReportErrorCode& errorCode = InstructionReportErrorCode(),
            const CancelInstruction& instruction = CancelInstruction(),
            const Optional<double>& sizeCancelled = Optional<double>(),
            const std::tm& cancelledDate = std::tm());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const InstructionReportStatus& getStatus() const;
        void setStatus(const InstructionReportStatus& status);

        const InstructionReportErrorCode& getErrorCode() const;
        void setErrorCode(const InstructionReportErrorCode& errorCode);

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
        InstructionReportStatus status;
        /**
         * cause of failure, or null if command succeeds
         */
        InstructionReportErrorCode errorCode;
        /**
         * The instruction that was requested
         */
        CancelInstruction instruction;
        Optional<double> sizeCancelled;
        std::tm cancelledDate;
};

}

#endif // CANCELINSTRUCTIONREPORT_H


