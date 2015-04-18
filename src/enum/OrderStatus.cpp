/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/OrderStatus.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string OrderStatus::EXECUTION_COMPLETE = "EXECUTION_COMPLETE";
const std::string OrderStatus::EXECUTABLE = "EXECUTABLE";

OrderStatus::OrderStatus() {
    valid = false;
};

OrderStatus::OrderStatus(const std::string& v) {

    if (v != EXECUTION_COMPLETE &&
        v != EXECUTABLE) {
        throw std::invalid_argument("Invalid OrderStatus: " + v);
    }

    value = v;
    valid = true;
}

bool OrderStatus::operator<(const OrderStatus& other) const {
    return value < other.value;
}

bool OrderStatus::operator==(const OrderStatus& other) const {
    return value == other.value;
}

}

