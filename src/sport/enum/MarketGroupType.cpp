/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/MarketGroupType.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string MarketGroupType::EVENT = "EVENT";

MarketGroupType::MarketGroupType() {
    valid = false;
}

MarketGroupType::MarketGroupType(const std::string& v) {
    if (v != EVENT) {
        throw std::invalid_argument("Invalid MarketGroupType: " + v);
    }
    value = v;
    valid = true;
}

bool MarketGroupType::operator<(const MarketGroupType& other) const {
    return value < other.value;
}

bool MarketGroupType::operator==(const MarketGroupType& other) const {
    return value == other.value;
}

bool MarketGroupType::operator!=(const MarketGroupType& other) const {
    return value != other.value;
}

}
