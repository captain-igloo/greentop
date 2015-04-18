/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/enum/Status.h"

#include <stdexcept>

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

}

