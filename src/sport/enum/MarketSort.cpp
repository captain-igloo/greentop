/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/sport/enum/MarketSort.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string MarketSort::MINIMUM_TRADED = "MINIMUM_TRADED";
const std::string MarketSort::MAXIMUM_TRADED = "MAXIMUM_TRADED";
const std::string MarketSort::MINIMUM_AVAILABLE = "MINIMUM_AVAILABLE";
const std::string MarketSort::MAXIMUM_AVAILABLE = "MAXIMUM_AVAILABLE";
const std::string MarketSort::FIRST_TO_START = "FIRST_TO_START";
const std::string MarketSort::LAST_TO_START = "LAST_TO_START";

MarketSort::MarketSort() {
    valid = false;
};

MarketSort::MarketSort(const std::string& v) {

    if (v != MINIMUM_TRADED &&
        v != MAXIMUM_TRADED &&
        v != MINIMUM_AVAILABLE &&
        v != MAXIMUM_AVAILABLE &&
        v != FIRST_TO_START &&
        v != LAST_TO_START) {
        throw std::invalid_argument("Invalid MarketSort: " + v);
    }

    value = v;
    valid = true;
}

bool MarketSort::operator<(const MarketSort& other) const {
    return value < other.value;
}

bool MarketSort::operator==(const MarketSort& other) const {
    return value == other.value;
}

bool MarketSort::operator!=(const MarketSort& other) const {
    return value != other.value;
}

}

