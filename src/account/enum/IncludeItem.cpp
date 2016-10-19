/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/IncludeItem.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string IncludeItem::ALL = "ALL";
const std::string IncludeItem::EXCHANGE = "EXCHANGE";
const std::string IncludeItem::POKER_ROOM = "POKER_ROOM";
const std::string IncludeItem::DEPOSITS_WITHDRAWALS = "DEPOSITS_WITHDRAWALS";

IncludeItem::IncludeItem() {
    valid = false;
};

IncludeItem::IncludeItem(const std::string& v) {

    if (v != ALL &&
        v != EXCHANGE &&
        v != POKER_ROOM &&
        v != DEPOSITS_WITHDRAWALS) {
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

