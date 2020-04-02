/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/LimitBreachActionType.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string LimitBreachActionType::REJECT_BETS = "REJECT_BETS";
const std::string LimitBreachActionType::STOP_BETTING = "STOP_BETTING";
const std::string LimitBreachActionType::TEAR_DOWN_MARKET_GROUP = "TEAR_DOWN_MARKET_GROUP";

LimitBreachActionType::LimitBreachActionType() {
    valid = false;
}

LimitBreachActionType::LimitBreachActionType(const std::string& v) {
    if (v != REJECT_BETS &&
        v != STOP_BETTING &&
        v != TEAR_DOWN_MARKET_GROUP) {
        throw std::invalid_argument("Invalid LimitBreachActionType: " + v);
    }
    value = v;
    valid = true;
}

bool LimitBreachActionType::operator<(const LimitBreachActionType& other) const {
    return value < other.value;
}

bool LimitBreachActionType::operator==(const LimitBreachActionType& other) const {
    return value == other.value;
}

bool LimitBreachActionType::operator!=(const LimitBreachActionType& other) const {
    return value != other.value;
}

}
}
