#ifndef CANCELINSTRUCTIONREPORT_H
#define CANCELINSTRUCTIONREPORT_H

#include <ctime>
#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/betting/CancelInstruction.h"
#include "greentop/enum/InstructionReportErrorCode.h"
#include "greentop/enum/InstructionReportStatus.h"

namespace greentop {

class CancelInstructionReport : public JsonMember {
    public:
        CancelInstructionReport();

        CancelInstructionReport(const InstructionReportStatus& status,
            const InstructionReportErrorCode& errorCode = InstructionReportErrorCode(),
            const CancelInstruction& instruction = CancelInstruction(),
            const double sizeCancelled = -1,
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

        const double getSizeCancelled() const;
        void setSizeCancelled(const double sizeCancelled);

        const std::tm& getCancelledDate() const;
        void setCancelledDate(const std::tm& cancelledDate);


    private:
        InstructionReportStatus status;
        InstructionReportErrorCode errorCode;
        CancelInstruction instruction;
        double sizeCancelled;
        std::tm cancelledDate;
};

}

#endif // CANCELINSTRUCTIONREPORT_H


