/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/PersistenceType.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string PersistenceType::LAPSE = "LAPSE";
const std::string PersistenceType::PERSIST = "PERSIST";
const std::string PersistenceType::MARKET_ON_CLOSE = "MARKET_ON_CLOSE";

PersistenceType::PersistenceType() {
    valid = false;
}

PersistenceType::PersistenceType(const std::string& v) {
    if (v != LAPSE &&
        v != PERSIST &&
        v != MARKET_ON_CLOSE) {
        throw std::invalid_argument("Invalid PersistenceType: " + v);
    }
    value = v;
    valid = true;
}

bool PersistenceType::operator<(const PersistenceType& other) const {
    return value < other.value;
}

bool PersistenceType::operator==(const PersistenceType& other) const {
    return value == other.value;
}

bool PersistenceType::operator!=(const PersistenceType& other) const {
    return value != other.value;
}

}
