/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/heartbeat/enum/ActionPerformed.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string ActionPerformed::NONE = "NONE";
const std::string ActionPerformed::CANCELLATION_REQUEST_SUBMITTED = "CANCELLATION_REQUEST_SUBMITTED";
const std::string ActionPerformed::ALL_BETS_CANCELLED = "ALL_BETS_CANCELLED";
const std::string ActionPerformed::SOME_BETS_NOT_CANCELLED = "SOME_BETS_NOT_CANCELLED";
const std::string ActionPerformed::CANCELLATION_REQUEST_ERROR = "CANCELLATION_REQUEST_ERROR";
const std::string ActionPerformed::CANCELLATION_STATUS_UNKNOWN = "CANCELLATION_STATUS_UNKNOWN";

ActionPerformed::ActionPerformed() {
    valid = false;
}

ActionPerformed::ActionPerformed(const std::string& v) {
    if (v != NONE &&
        v != CANCELLATION_REQUEST_SUBMITTED &&
        v != ALL_BETS_CANCELLED &&
        v != SOME_BETS_NOT_CANCELLED &&
        v != CANCELLATION_REQUEST_ERROR &&
        v != CANCELLATION_STATUS_UNKNOWN) {
        throw std::invalid_argument("Invalid ActionPerformed: " + v);
    }
    value = v;
    valid = true;
}

bool ActionPerformed::operator<(const ActionPerformed& other) const {
    return value < other.value;
}

bool ActionPerformed::operator==(const ActionPerformed& other) const {
    return value == other.value;
}

bool ActionPerformed::operator!=(const ActionPerformed& other) const {
    return value != other.value;
}

}
