/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */
#include "greentop/Optional.h"

namespace greentop {

template<>
void Optional<bool>::fromJson(const Json::Value& json) {
    value = json.asBool();
    valid = true;
}

template<>
void Optional<double>::fromJson(const Json::Value& json) {
    value = json.asDouble();
    valid = true;
}

template<>
void Optional<int>::fromJson(const Json::Value& json) {
    value = json.asInt();
    valid = true;
}

template<>
void Optional<uint64_t>::fromJson(const Json::Value& json) {
    value = json.asUInt64();
    valid = true;
}

}
