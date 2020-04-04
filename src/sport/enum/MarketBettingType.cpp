/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/MarketBettingType.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string MarketBettingType::ODDS = "ODDS";
const std::string MarketBettingType::LINE = "LINE";
const std::string MarketBettingType::RANGE = "RANGE";
const std::string MarketBettingType::ASIAN_HANDICAP_DOUBLE_LINE = "ASIAN_HANDICAP_DOUBLE_LINE";
const std::string MarketBettingType::ASIAN_HANDICAP_SINGLE_LINE = "ASIAN_HANDICAP_SINGLE_LINE";
const std::string MarketBettingType::FIXED_ODDS = "FIXED_ODDS";

MarketBettingType::MarketBettingType() {
    valid = false;
}

MarketBettingType::MarketBettingType(const std::string& v) {
    if (v != ODDS &&
        v != LINE &&
        v != RANGE &&
        v != ASIAN_HANDICAP_DOUBLE_LINE &&
        v != ASIAN_HANDICAP_SINGLE_LINE &&
        v != FIXED_ODDS) {
        throw std::invalid_argument("Invalid MarketBettingType: " + v);
    }
    value = v;
    valid = true;
}

bool MarketBettingType::operator<(const MarketBettingType& other) const {
    return value < other.value;
}

bool MarketBettingType::operator==(const MarketBettingType& other) const {
    return value == other.value;
}

bool MarketBettingType::operator!=(const MarketBettingType& other) const {
    return value != other.value;
}

}
}
