/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/TokenType.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string TokenType::BEARER = "BEARER";

TokenType::TokenType() {
    valid = false;
};

TokenType::TokenType(const std::string& v) {

    if (v != BEARER) {
        throw std::invalid_argument("Invalid TokenType: " + v);
    }

    value = v;
    valid = true;
}

bool TokenType::operator<(const TokenType& other) const {
    return value < other.value;
}

bool TokenType::operator==(const TokenType& other) const {
    return value == other.value;
}

bool TokenType::operator!=(const TokenType& other) const {
    return value != other.value;
}

}

