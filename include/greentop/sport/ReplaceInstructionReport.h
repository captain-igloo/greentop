/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REPLACEINSTRUCTIONREPORT_H
#define REPLACEINSTRUCTIONREPORT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/CancelInstructionReport.h"
#include "greentop/sport/PlaceInstructionReport.h"
#include "greentop/sport/enum/InstructionReportErrorCode.h"
#include "greentop/sport/enum/InstructionReportStatus.h"

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
        /**
         * whether the command succeeded or failed
         */
        InstructionReportStatus status;
        /**
         * cause of failure, or null if command succeeds
         */
        InstructionReportErrorCode errorCode;
        /**
         * Cancelation report for the original order
         */
        CancelInstructionReport cancelInstructionReport;
        /**
         * Placement report for the new order
         */
        PlaceInstructionReport placeInstructionReport;
};

}

#endif // REPLACEINSTRUCTIONREPORT_H


