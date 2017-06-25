/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/TimeGranularity.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string TimeGranularity::DAYS = "DAYS";
const std::string TimeGranularity::HOURS = "HOURS";
const std::string TimeGranularity::MINUTES = "MINUTES";

TimeGranularity::TimeGranularity() {
    valid = false;
}

TimeGranularity::TimeGranularity(const std::string& v) {
    if (v != DAYS &&
        v != HOURS &&
        v != MINUTES) {
        throw std::invalid_argument("Invalid TimeGranularity: " + v);
    }
    value = v;
    valid = true;
}

bool TimeGranularity::operator<(const TimeGranularity& other) const {
    return value < other.value;
}

bool TimeGranularity::operator==(const TimeGranularity& other) const {
    return value == other.value;
}

bool TimeGranularity::operator!=(const TimeGranularity& other) const {
    return value != other.value;
}

}
