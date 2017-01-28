/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEINSTRUCTIONREPORT_H
#define UPDATEINSTRUCTIONREPORT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/UpdateInstruction.h"
#include "greentop/sport/enum/InstructionReportErrorCode.h"
#include "greentop/sport/enum/InstructionReportStatus.h"

namespace greentop {

class UpdateInstructionReport : public JsonMember {
    public:
        UpdateInstructionReport();

        UpdateInstructionReport(const InstructionReportStatus& status,
            const InstructionReportErrorCode& errorCode = InstructionReportErrorCode(),
            const UpdateInstruction& instruction = UpdateInstruction());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const InstructionReportStatus& getStatus() const;
        void setStatus(const InstructionReportStatus& status);

        const InstructionReportErrorCode& getErrorCode() const;
        void setErrorCode(const InstructionReportErrorCode& errorCode);

        const UpdateInstruction& getInstruction() const;
        void setInstruction(const UpdateInstruction& instruction);


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
        UpdateInstruction instruction;
};

}

#endif // UPDATEINSTRUCTIONREPORT_H


