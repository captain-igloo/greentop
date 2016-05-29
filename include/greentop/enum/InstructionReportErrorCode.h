/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef INSTRUCTIONREPORTERRORCODE_H
#define INSTRUCTIONREPORTERRORCODE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class InstructionReportErrorCode : public Enum<InstructionReportErrorCode> {

    public:

        static const std::string INVALID_BET_SIZE;
        static const std::string INVALID_RUNNER;
        static const std::string BET_TAKEN_OR_LAPSED;
        static const std::string BET_IN_PROGRESS;
        static const std::string RUNNER_REMOVED;
        static const std::string MARKET_NOT_OPEN_FOR_BETTING;
        static const std::string LOSS_LIMIT_EXCEEDED;
        static const std::string MARKET_NOT_OPEN_FOR_BSP_BETTING;
        static const std::string INVALID_PRICE_EDIT;
        static const std::string INVALID_ODDS;
        static const std::string INSUFFICIENT_FUNDS;

        InstructionReportErrorCode();

        InstructionReportErrorCode(const std::string& v);

        bool operator<(const InstructionReportErrorCode& other) const;

        bool operator==(const InstructionReportErrorCode& other) const;

		bool operator!=(const InstructionReportErrorCode& other) const;
};

}

#endif // INSTRUCTIONREPORTERRORCODE_H
