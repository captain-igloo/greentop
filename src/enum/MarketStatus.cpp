/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/MarketStatus.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string MarketStatus::INACTIVE = "INACTIVE";
const std::string MarketStatus::OPEN = "OPEN";
const std::string MarketStatus::SUSPENDED = "SUSPENDED";
const std::string MarketStatus::CLOSED = "CLOSED";

MarketStatus::MarketStatus() {
    valid = false;
};

MarketStatus::MarketStatus(const std::string& v) {

    if (v != INACTIVE &&
        v != OPEN &&
        v != SUSPENDED &&
        v != CLOSED) {
        throw std::invalid_argument("Invalid MarketStatus: " + v);
    }

    value = v;
    valid = true;
}

bool MarketStatus::operator<(const MarketStatus& other) const {
    return value < other.value;
}

bool MarketStatus::operator==(const MarketStatus& other) const {
    return value == other.value;
}

}

