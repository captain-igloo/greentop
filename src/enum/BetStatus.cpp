/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/BetStatus.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string BetStatus::SETTLED = "SETTLED";
const std::string BetStatus::VOIDED = "VOIDED";
const std::string BetStatus::LAPSED = "LAPSED";
const std::string BetStatus::CANCELLED = "CANCELLED";

BetStatus::BetStatus() {
    valid = false;
};

BetStatus::BetStatus(const std::string& v) {

    if (v != SETTLED &&
        v != VOIDED &&
        v != LAPSED &&
        v != CANCELLED) {
        throw std::invalid_argument("Invalid BetStatus: " + v);
    }

    value = v;
    valid = true;
}

bool BetStatus::operator<(const BetStatus& other) const {
    return value < other.value;
}

bool BetStatus::operator==(const BetStatus& other) const {
    return value == other.value;
}

bool BetStatus::operator!=(const BetStatus& other) const {
    return value != other.value;
}

}

