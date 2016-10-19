/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */
#include <stdexcept>

#include "greentop/account/enum/Status.h"
#include "greentop/Enum.h"

namespace greentop {

const std::string Status::SUCCESS = "SUCCESS";

Status::Status() {
    valid = false;
};

Status::Status(const std::string& v) {

    if (v != SUCCESS) {
        throw std::invalid_argument("Invalid Status: " + v);
    }

    value = v;
    valid = true;
}

bool Status::operator<(const Status& other) const {
    return value < other.value;
}

bool Status::operator==(const Status& other) const {
    return value == other.value;
}

bool Status::operator!=(const Status& other) const {
    return value != other.value;
}

}

