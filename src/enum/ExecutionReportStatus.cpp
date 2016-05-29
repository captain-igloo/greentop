/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/ExecutionReportStatus.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string ExecutionReportStatus::SUCCESS = "SUCCESS";
const std::string ExecutionReportStatus::FAILURE = "FAILURE";
const std::string ExecutionReportStatus::PROCESSED_WITH_ERRORS = "PROCESSED_WITH_ERRORS";
const std::string ExecutionReportStatus::TIMEOUT = "TIMEOUT";

ExecutionReportStatus::ExecutionReportStatus() {
    valid = false;
};

ExecutionReportStatus::ExecutionReportStatus(const std::string& v) {

    if (v != SUCCESS &&
        v != FAILURE &&
        v != PROCESSED_WITH_ERRORS &&
        v != TIMEOUT) {
        throw std::invalid_argument("Invalid ExecutionReportStatus: " + v);
    }

    value = v;
    valid = true;
}

bool ExecutionReportStatus::operator<(const ExecutionReportStatus& other) const {
    return value < other.value;
}

bool ExecutionReportStatus::operator==(const ExecutionReportStatus& other) const {
    return value == other.value;
}

bool ExecutionReportStatus::operator!=(const ExecutionReportStatus& other) const {
    return value != other.value;
}

}

