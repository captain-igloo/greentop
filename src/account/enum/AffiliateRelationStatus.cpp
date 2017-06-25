/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/AffiliateRelationStatus.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string AffiliateRelationStatus::INVALID_USER = "INVALID_USER";
const std::string AffiliateRelationStatus::AFFILIATED = "AFFILIATED";
const std::string AffiliateRelationStatus::NOT_AFFILIATED = "NOT_AFFILIATED";

AffiliateRelationStatus::AffiliateRelationStatus() {
    valid = false;
}

AffiliateRelationStatus::AffiliateRelationStatus(const std::string& v) {
    if (v != INVALID_USER &&
        v != AFFILIATED &&
        v != NOT_AFFILIATED) {
        throw std::invalid_argument("Invalid AffiliateRelationStatus: " + v);
    }
    value = v;
    valid = true;
}

bool AffiliateRelationStatus::operator<(const AffiliateRelationStatus& other) const {
    return value < other.value;
}

bool AffiliateRelationStatus::operator==(const AffiliateRelationStatus& other) const {
    return value == other.value;
}

bool AffiliateRelationStatus::operator!=(const AffiliateRelationStatus& other) const {
    return value != other.value;
}

}
