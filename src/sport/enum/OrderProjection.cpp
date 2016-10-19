/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/OrderProjection.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string OrderProjection::ALL = "ALL";
const std::string OrderProjection::EXECUTABLE = "EXECUTABLE";
const std::string OrderProjection::EXECUTION_COMPLETE = "EXECUTION_COMPLETE";

OrderProjection::OrderProjection() {
    valid = false;
};

OrderProjection::OrderProjection(const std::string& v) {

    if (v != ALL &&
        v != EXECUTABLE &&
        v != EXECUTION_COMPLETE) {
        throw std::invalid_argument("Invalid OrderProjection: " + v);
    }

    value = v;
    valid = true;
}

bool OrderProjection::operator<(const OrderProjection& other) const {
    return value < other.value;
}

bool OrderProjection::operator==(const OrderProjection& other) const {
    return value == other.value;
}

bool OrderProjection::operator!=(const OrderProjection& other) const {
    return value != other.value;
}

}

