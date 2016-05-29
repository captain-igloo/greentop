/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/IncludeItem.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string IncludeItem::ALL = "ALL";
const std::string IncludeItem::DEPOSITS_WITHDRAWALS = "DEPOSITS_WITHDRAWALS";
const std::string IncludeItem::EXCHANGE = "EXCHANGE";
const std::string IncludeItem::POKER_ROOM = "POKER_ROOM";

IncludeItem::IncludeItem() {
    valid = false;
};

IncludeItem::IncludeItem(const std::string& v) {

    if (v != ALL &&
        v != DEPOSITS_WITHDRAWALS &&
        v != EXCHANGE &&
        v != POKER_ROOM) {
        throw std::invalid_argument("Invalid IncludeItem: " + v);
    }

    value = v;
    valid = true;
}

bool IncludeItem::operator<(const IncludeItem& other) const {
    return value < other.value;
}

bool IncludeItem::operator==(const IncludeItem& other) const {
    return value == other.value;
}

bool IncludeItem::operator!=(const IncludeItem& other) const {
    return value != other.value;
}

}

