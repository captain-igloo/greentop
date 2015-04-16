#ifndef REPLACEINSTRUCTIONREPORT_H
#define REPLACEINSTRUCTIONREPORT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/betting/CancelInstructionReport.h"
#include "greentop/betting/PlaceInstructionReport.h"
#include "greentop/enum/InstructionReportErrorCode.h"
#include "greentop/enum/InstructionReportStatus.h"

namespace greentop {

class ReplaceInstructionReport : public JsonMember {
    public:
        ReplaceInstructionReport();

        ReplaceInstructionReport(const InstructionReportStatus& status,
            const InstructionReportErrorCode& errorCode = InstructionReportErrorCode(),
            const CancelInstructionReport& cancelInstructionReport = CancelInstructionReport(),
            const PlaceInstructionReport& placeInstructionReport = PlaceInstructionReport());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const InstructionReportStatus& getStatus() const;
        void setStatus(const InstructionReportStatus& status);

        const InstructionReportErrorCode& getErrorCode() const;
        void setErrorCode(const InstructionReportErrorCode& errorCode);

        const CancelInstructionReport& getCancelInstructionReport() const;
        void setCancelInstructionReport(const CancelInstructionReport& cancelInstructionReport);

        const PlaceInstructionReport& getPlaceInstructionReport() const;
        void setPlaceInstructionReport(const PlaceInstructionReport& placeInstructionReport);


    private:
        InstructionReportStatus status;
        InstructionReportErrorCode errorCode;
        CancelInstructionReport cancelInstructionReport;
        PlaceInstructionReport placeInstructionReport;
};

}

#endif // REPLACEINSTRUCTIONREPORT_H


