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
void Optional<int64_t>::fromJson(const Json::Value& json) {
    value = json.asInt64();
    valid = true;
}

template<>
Json::Value Optional<bool>::toJson() const {
    Json::Value json(value);
    return json;
}

template<>
Json::Value Optional<double>::toJson() const {
    Json::Value json(value);
    return json;
}

template<>
Json::Value Optional<int>::toJson() const {
    Json::Value::Int json(value);
    return json;
}

template<>
Json::Value Optional<int64_t>::toJson() const {
    Json::Value::Int64 json(value);
    return json;
}

}
