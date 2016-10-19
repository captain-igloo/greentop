/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/RunnerStatus.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string RunnerStatus::ACTIVE = "ACTIVE";
const std::string RunnerStatus::WINNER = "WINNER";
const std::string RunnerStatus::LOSER = "LOSER";
const std::string RunnerStatus::REMOVED_VACANT = "REMOVED_VACANT";
const std::string RunnerStatus::REMOVED = "REMOVED";

RunnerStatus::RunnerStatus() {
    valid = false;
};

RunnerStatus::RunnerStatus(const std::string& v) {

    if (v != ACTIVE &&
        v != WINNER &&
        v != LOSER &&
        v != REMOVED_VACANT &&
        v != REMOVED) {
        throw std::invalid_argument("Invalid RunnerStatus: " + v);
    }

    value = v;
    valid = true;
}

bool RunnerStatus::operator<(const RunnerStatus& other) const {
    return value < other.value;
}

bool RunnerStatus::operator==(const RunnerStatus& other) const {
    return value == other.value;
}

bool RunnerStatus::operator!=(const RunnerStatus& other) const {
    return value != other.value;
}

}

