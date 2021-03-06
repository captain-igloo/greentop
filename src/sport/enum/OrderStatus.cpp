/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/OrderStatus.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string OrderStatus::PENDING = "PENDING";
const std::string OrderStatus::EXECUTION_COMPLETE = "EXECUTION_COMPLETE";
const std::string OrderStatus::EXECUTABLE = "EXECUTABLE";
const std::string OrderStatus::EXPIRED = "EXPIRED";

OrderStatus::OrderStatus() {
    valid = false;
}

OrderStatus::OrderStatus(const std::string& v) {
    if (v != PENDING &&
        v != EXECUTION_COMPLETE &&
        v != EXECUTABLE &&
        v != EXPIRED) {
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

bool OrderStatus::operator!=(const OrderStatus& other) const {
    return value != other.value;
}

}
}
