/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/JsonMember.h"

namespace greentop {

JsonMember::JsonMember() {
    valid = false;
}

bool JsonMember::isValid() const {
    return valid;
}

std::string JsonMember::toString() const {
    Json::FastWriter writer;
    return writer.write(toJson());
}

JsonMember::~JsonMember() {
}

}

std::ostream& operator<<(std::ostream& os, const greentop::JsonMember& jm) {

    Json::FastWriter writer;
    os << writer.write(jm.toJson());

    return os;
}

std::istream& operator>>(std::istream& is, greentop::JsonMember& jm) {

    Json::Value json;

    is >> json;

    jm.fromJson(json);

    return is;
}

