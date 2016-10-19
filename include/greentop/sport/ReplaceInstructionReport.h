/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REPLACEINSTRUCTIONREPORT_H
#define REPLACEINSTRUCTIONREPORT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/sport/CancelInstructionReport.h"
#include "greentop/sport/PlaceInstructionReport.h"

namespace greentop {

class ReplaceInstructionReport : public JsonMember {
    public:
        ReplaceInstructionReport();

        ReplaceInstructionReport(const std::string& status,
            const std::string& errorCode = std::string(),
            const CancelInstructionReport& cancelInstructionReport = CancelInstructionReport(),
            const PlaceInstructionReport& placeInstructionReport = PlaceInstructionReport());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const std::string& getErrorCode() const;
        void setErrorCode(const std::string& errorCode);

        const CancelInstructionReport& getCancelInstructionReport() const;
        void setCancelInstructionReport(const CancelInstructionReport& cancelInstructionReport);

        const PlaceInstructionReport& getPlaceInstructionReport() const;
        void setPlaceInstructionReport(const PlaceInstructionReport& placeInstructionReport);


    private:
        std::string status;
        std::string errorCode;
        CancelInstructionReport cancelInstructionReport;
        PlaceInstructionReport placeInstructionReport;
};

}

#endif // REPLACEINSTRUCTIONREPORT_H


