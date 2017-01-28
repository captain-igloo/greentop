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
#include "greentop/sport/enum/InstructionReportErrorCode.h"
#include "greentop/sport/enum/InstructionReportStatus.h"
#include "greentop/sport/enum/OrderStatus.h"

namespace greentop {

/**
 * Response to a PlaceInstruction
 */
class PlaceInstructionReport : public JsonMember {
    public:
        PlaceInstructionReport();

        PlaceInstructionReport(const InstructionReportStatus& status,
            const InstructionReportErrorCode& errorCode = InstructionReportErrorCode(),
            const OrderStatus& orderStatus = OrderStatus(),
            const PlaceInstruction& instruction = PlaceInstruction(),
            const std::string& betId = std::string(),
            const std::tm& placedDate = std::tm(),
            const Optional<double>& averagePriceMatched = Optional<double>(),
            const Optional<double>& sizeMatched = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const InstructionReportStatus& getStatus() const;
        void setStatus(const InstructionReportStatus& status);

        const InstructionReportErrorCode& getErrorCode() const;
        void setErrorCode(const InstructionReportErrorCode& errorCode);

        const OrderStatus& getOrderStatus() const;
        void setOrderStatus(const OrderStatus& orderStatus);

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
        InstructionReportStatus status;
        /**
         * cause of failure, or null if command succeeds
         */
        InstructionReportErrorCode errorCode;
        /**
         * The status of the order, if the instruction succeeded. If the instruction was
         * unsuccessful, no value is provided.
         */
        OrderStatus orderStatus;
        /**
         * The instruction that was requested
         */
        PlaceInstruction instruction;
        /**
         * The bet ID of the new bet. Will be null on failure or if order was placed
         * asynchronously.
         */
        std::string betId;
        /**
         * Will be null if order was placed asynchronously
         */
        std::tm placedDate;
        /**
         * Will be null if order was placed asynchronously
         */
        Optional<double> averagePriceMatched;
        /**
         * Will be null if order was placed asynchronously
         */
        Optional<double> sizeMatched;
};

}

#endif // PLACEINSTRUCTIONREPORT_H


