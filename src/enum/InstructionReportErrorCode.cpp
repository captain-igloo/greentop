/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/InstructionReportErrorCode.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string InstructionReportErrorCode::INVALID_BET_SIZE = "INVALID_BET_SIZE";
const std::string InstructionReportErrorCode::INVALID_RUNNER = "INVALID_RUNNER";
const std::string InstructionReportErrorCode::BET_TAKEN_OR_LAPSED = "BET_TAKEN_OR_LAPSED";
const std::string InstructionReportErrorCode::BET_IN_PROGRESS = "BET_IN_PROGRESS";
const std::string InstructionReportErrorCode::RUNNER_REMOVED = "RUNNER_REMOVED";
const std::string InstructionReportErrorCode::MARKET_NOT_OPEN_FOR_BETTING = "MARKET_NOT_OPEN_FOR_BETTING";
const std::string InstructionReportErrorCode::LOSS_LIMIT_EXCEEDED = "LOSS_LIMIT_EXCEEDED";
const std::string InstructionReportErrorCode::MARKET_NOT_OPEN_FOR_BSP_BETTING = "MARKET_NOT_OPEN_FOR_BSP_BETTING";
const std::string InstructionReportErrorCode::INVALID_PRICE_EDIT = "INVALID_PRICE_EDIT";
const std::string InstructionReportErrorCode::INVALID_ODDS = "INVALID_ODDS";
const std::string InstructionReportErrorCode::INSUFFICIENT_FUNDS = "INSUFFICIENT_FUNDS";

InstructionReportErrorCode::InstructionReportErrorCode() {
    valid = false;
};

InstructionReportErrorCode::InstructionReportErrorCode(const std::string& v) {

    if (v != INVALID_BET_SIZE &&
        v != INVALID_RUNNER &&
        v != BET_TAKEN_OR_LAPSED &&
        v != BET_IN_PROGRESS &&
        v != RUNNER_REMOVED &&
        v != MARKET_NOT_OPEN_FOR_BETTING &&
        v != LOSS_LIMIT_EXCEEDED &&
        v != MARKET_NOT_OPEN_FOR_BSP_BETTING &&
        v != INVALID_PRICE_EDIT &&
        v != INVALID_ODDS &&
        v != INSUFFICIENT_FUNDS) {
        throw std::invalid_argument("Invalid InstructionReportErrorCode: " + v);
    }

    value = v;
    valid = true;
}

bool InstructionReportErrorCode::operator<(const InstructionReportErrorCode& other) const {
    return value < other.value;
}

bool InstructionReportErrorCode::operator==(const InstructionReportErrorCode& other) const {
    return value == other.value;
}

}

