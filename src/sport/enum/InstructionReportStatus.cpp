/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/InstructionReportStatus.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string InstructionReportStatus::SUCCESS = "SUCCESS";
const std::string InstructionReportStatus::FAILURE = "FAILURE";
const std::string InstructionReportStatus::TIMEOUT = "TIMEOUT";

InstructionReportStatus::InstructionReportStatus() {
    valid = false;
}

InstructionReportStatus::InstructionReportStatus(const std::string& v) {
    if (v != SUCCESS &&
        v != FAILURE &&
        v != TIMEOUT) {
        throw std::invalid_argument("Invalid InstructionReportStatus: " + v);
    }
    value = v;
    valid = true;
}

bool InstructionReportStatus::operator<(const InstructionReportStatus& other) const {
    return value < other.value;
}

bool InstructionReportStatus::operator==(const InstructionReportStatus& other) const {
    return value == other.value;
}

bool InstructionReportStatus::operator!=(const InstructionReportStatus& other) const {
    return value != other.value;
}

}
}
