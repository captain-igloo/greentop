/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/BetTargetType.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string BetTargetType::PAYOUT = "PAYOUT";
const std::string BetTargetType::BACKERS_PROFIT = "BACKERS_PROFIT";

BetTargetType::BetTargetType() {
    valid = false;
}

BetTargetType::BetTargetType(const std::string& v) {
    if (v != PAYOUT &&
        v != BACKERS_PROFIT) {
        throw std::invalid_argument("Invalid BetTargetType: " + v);
    }
    value = v;
    valid = true;
}

bool BetTargetType::operator<(const BetTargetType& other) const {
    return value < other.value;
}

bool BetTargetType::operator==(const BetTargetType& other) const {
    return value == other.value;
}

bool BetTargetType::operator!=(const BetTargetType& other) const {
    return value != other.value;
}

}
