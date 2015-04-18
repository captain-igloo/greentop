/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEINSTRUCTIONREPORT_H
#define PLACEINSTRUCTIONREPORT_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/betting/PlaceInstruction.h"
#include "greentop/enum/InstructionReportErrorCode.h"
#include "greentop/enum/InstructionReportStatus.h"

namespace greentop {

class PlaceInstructionReport : public JsonMember {
    public:
        PlaceInstructionReport();

        PlaceInstructionReport(const InstructionReportStatus& status,
            const InstructionReportErrorCode& errorCode = InstructionReportErrorCode(),
            const PlaceInstruction& instruction = PlaceInstruction(),
            const std::string& betId = std::string(),
            const std::tm& placedDate = std::tm(),
            const double averagePriceMatched = -1,
            const double sizeMatched = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const InstructionReportStatus& getStatus() const;
        void setStatus(const InstructionReportStatus& status);

        const InstructionReportErrorCode& getErrorCode() const;
        void setErrorCode(const InstructionReportErrorCode& errorCode);

        const PlaceInstruction& getInstruction() const;
        void setInstruction(const PlaceInstruction& instruction);

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const double getAveragePriceMatched() const;
        void setAveragePriceMatched(const double averagePriceMatched);

        const double getSizeMatched() const;
        void setSizeMatched(const double sizeMatched);


    private:
        InstructionReportStatus status;
        InstructionReportErrorCode errorCode;
        PlaceInstruction instruction;
        std::string betId;
        std::tm placedDate;
        double averagePriceMatched;
        double sizeMatched;
};

}

#endif // PLACEINSTRUCTIONREPORT_H


