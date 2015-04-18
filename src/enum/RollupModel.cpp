/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/RollupModel.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string RollupModel::STAKE = "STAKE";
const std::string RollupModel::PAYOUT = "PAYOUT";
const std::string RollupModel::MANAGED_LIABILITY = "MANAGED_LIABILITY";
const std::string RollupModel::NONE = "NONE";

RollupModel::RollupModel() {
    valid = false;
};

RollupModel::RollupModel(const std::string& v) {

    if (v != STAKE &&
        v != PAYOUT &&
        v != MANAGED_LIABILITY &&
        v != NONE) {
        throw std::invalid_argument("Invalid RollupModel: " + v);
    }

    value = v;
    valid = true;
}

bool RollupModel::operator<(const RollupModel& other) const {
    return value < other.value;
}

bool RollupModel::operator==(const RollupModel& other) const {
    return value == other.value;
}

}

