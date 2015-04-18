/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/MarketProjection.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string MarketProjection::COMPETITION = "COMPETITION";
const std::string MarketProjection::EVENT = "EVENT";
const std::string MarketProjection::EVENT_TYPE = "EVENT_TYPE";
const std::string MarketProjection::MARKET_START_TIME = "MARKET_START_TIME";
const std::string MarketProjection::MARKET_DESCRIPTION = "MARKET_DESCRIPTION";
const std::string MarketProjection::RUNNER_DESCRIPTION = "RUNNER_DESCRIPTION";
const std::string MarketProjection::RUNNER_METADATA = "RUNNER_METADATA";

MarketProjection::MarketProjection() {
    valid = false;
};

MarketProjection::MarketProjection(const std::string& v) {

    if (v != COMPETITION &&
        v != EVENT &&
        v != EVENT_TYPE &&
        v != MARKET_START_TIME &&
        v != MARKET_DESCRIPTION &&
        v != RUNNER_DESCRIPTION &&
        v != RUNNER_METADATA) {
        throw std::invalid_argument("Invalid MarketProjection: " + v);
    }

    value = v;
    valid = true;
}

bool MarketProjection::operator<(const MarketProjection& other) const {
    return value < other.value;
}

bool MarketProjection::operator==(const MarketProjection& other) const {
    return value == other.value;
}

}

