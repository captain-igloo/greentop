/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/SortDir.h"
#include "greentop/Enum.h"

namespace greentop {
namespace sport {

const std::string SortDir::EARLIEST_TO_LATEST = "EARLIEST_TO_LATEST";
const std::string SortDir::LATEST_TO_EARLIEST = "LATEST_TO_EARLIEST";

SortDir::SortDir() {
    valid = false;
}

SortDir::SortDir(const std::string& v) {
    if (v != EARLIEST_TO_LATEST &&
        v != LATEST_TO_EARLIEST) {
        throw std::invalid_argument("Invalid SortDir: " + v);
    }
    value = v;
    valid = true;
}

bool SortDir::operator<(const SortDir& other) const {
    return value < other.value;
}

bool SortDir::operator==(const SortDir& other) const {
    return value == other.value;
}

bool SortDir::operator!=(const SortDir& other) const {
    return value != other.value;
}

}
}
