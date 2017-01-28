/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/GrantType.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string GrantType::AUTHORIZATION_CODE = "AUTHORIZATION_CODE";
const std::string GrantType::REFRESH_TOKEN = "REFRESH_TOKEN";

GrantType::GrantType() {
    valid = false;
};

GrantType::GrantType(const std::string& v) {

    if (v != AUTHORIZATION_CODE &&
        v != REFRESH_TOKEN) {
        throw std::invalid_argument("Invalid GrantType: " + v);
    }

    value = v;
    valid = true;
}

bool GrantType::operator<(const GrantType& other) const {
    return value < other.value;
}

bool GrantType::operator==(const GrantType& other) const {
    return value == other.value;
}

bool GrantType::operator!=(const GrantType& other) const {
    return value != other.value;
}

}

