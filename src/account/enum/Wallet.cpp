/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/Wallet.h"
#include "greentop/Enum.h"

namespace greentop {
namespace account {

const std::string Wallet::UK = "UK";
const std::string Wallet::AUSTRALIAN = "AUSTRALIAN";

Wallet::Wallet() {
    valid = false;
}

Wallet::Wallet(const std::string& v) {
    if (v != UK &&
        v != AUSTRALIAN) {
        throw std::invalid_argument("Invalid Wallet: " + v);
    }
    value = v;
    valid = true;
}

bool Wallet::operator<(const Wallet& other) const {
    return value < other.value;
}

bool Wallet::operator==(const Wallet& other) const {
    return value == other.value;
}

bool Wallet::operator!=(const Wallet& other) const {
    return value != other.value;
}

}
}
