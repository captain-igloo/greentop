/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/SubscriptionStatus.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string SubscriptionStatus::ALL = "ALL";
const std::string SubscriptionStatus::ACTIVATED = "ACTIVATED";
const std::string SubscriptionStatus::UNACTIVATED = "UNACTIVATED";
const std::string SubscriptionStatus::CANCELLED = "CANCELLED";
const std::string SubscriptionStatus::EXPIRED = "EXPIRED";

SubscriptionStatus::SubscriptionStatus() {
    valid = false;
};

SubscriptionStatus::SubscriptionStatus(const std::string& v) {

    if (v != ALL &&
        v != ACTIVATED &&
        v != UNACTIVATED &&
        v != CANCELLED &&
        v != EXPIRED) {
        throw std::invalid_argument("Invalid SubscriptionStatus: " + v);
    }

    value = v;
    valid = true;
}

bool SubscriptionStatus::operator<(const SubscriptionStatus& other) const {
    return value < other.value;
}

bool SubscriptionStatus::operator==(const SubscriptionStatus& other) const {
    return value == other.value;
}

bool SubscriptionStatus::operator!=(const SubscriptionStatus& other) const {
    return value != other.value;
}

}

