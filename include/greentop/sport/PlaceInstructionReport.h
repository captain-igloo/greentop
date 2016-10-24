/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEINSTRUCTIONREPORT_H
#define PLACEINSTRUCTIONREPORT_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/PlaceInstruction.h"

namespace greentop {

/**
 * Response to a PlaceInstruction
 */
class PlaceInstructionReport : public JsonMember {
    public:
        PlaceInstructionReport();

        PlaceInstructionReport(const std::string& status,
            const std::string& errorCode = std::string(),
            const PlaceInstruction& instruction = PlaceInstruction(),
            const std::string& betId = std::string(),
            const std::tm& placedDate = std::tm(),
            const Optional<double>& averagePriceMatched = Optional<double>(),
            const Optional<double>& sizeMatched = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const std::string& getErrorCode() const;
        void setErrorCode(const std::string& errorCode);

        const PlaceInstruction& getInstruction() const;
        void setInstruction(const PlaceInstruction& instruction);

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const Optional<double>& getAveragePriceMatched() const;
        void setAveragePriceMatched(const Optional<double>& averagePriceMatched);

        const Optional<double>& getSizeMatched() const;
        void setSizeMatched(const Optional<double>& sizeMatched);


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
        PlaceInstruction instruction;
        /**
         * The bet ID of the new bet. May be null on failure.
         */
        std::string betId;
        std::tm placedDate;
        Optional<double> averagePriceMatched;
        Optional<double> sizeMatched;
};

}

#endif // PLACEINSTRUCTIONREPORT_H


