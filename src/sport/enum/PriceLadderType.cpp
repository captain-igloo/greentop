/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/PriceLadderType.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string PriceLadderType::CLASSIC = "CLASSIC";
const std::string PriceLadderType::FINEST = "FINEST";
const std::string PriceLadderType::LINE_RANGE = "LINE_RANGE";

PriceLadderType::PriceLadderType() {
    valid = false;
}

PriceLadderType::PriceLadderType(const std::string& v) {
    if (v != CLASSIC &&
        v != FINEST &&
        v != LINE_RANGE) {
        throw std::invalid_argument("Invalid PriceLadderType: " + v);
    }
    value = v;
    valid = true;
}

bool PriceLadderType::operator<(const PriceLadderType& other) const {
    return value < other.value;
}

bool PriceLadderType::operator==(const PriceLadderType& other) const {
    return value == other.value;
}

bool PriceLadderType::operator!=(const PriceLadderType& other) const {
    return value != other.value;
}

}
}
