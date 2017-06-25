/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/TimeInForce.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string TimeInForce::FILL_OR_KILL = "FILL_OR_KILL";

TimeInForce::TimeInForce() {
    valid = false;
}

TimeInForce::TimeInForce(const std::string& v) {
    if (v != FILL_OR_KILL) {
        throw std::invalid_argument("Invalid TimeInForce: " + v);
    }
    value = v;
    valid = true;
}

bool TimeInForce::operator<(const TimeInForce& other) const {
    return value < other.value;
}

bool TimeInForce::operator==(const TimeInForce& other) const {
    return value == other.value;
}

bool TimeInForce::operator!=(const TimeInForce& other) const {
    return value != other.value;
}

}
