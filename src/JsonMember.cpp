/**
 * Copyright 2018 Colin Doig.  Distributed under the MIT license.
 */
#include <memory>
#include <sstream>
#include "greentop/JsonMember.h"

namespace {
Json::StreamWriter* getJsonStreamWriter() {
    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";
    return builder.newStreamWriter();
}
}

namespace greentop {

JsonMember::JsonMember() {
    valid = false;
}

bool JsonMember::isValid() const {
    return valid;
}

std::string JsonMember::toString() const {
    std::unique_ptr<Json::StreamWriter> writer(getJsonStreamWriter());
    std::ostringstream out;
    writer->write(toJson(), &out);
    return out.str();
}

}

std::ostream& operator<<(std::ostream& os, const greentop::JsonMember& jm) {
    std::unique_ptr<Json::StreamWriter> writer(getJsonStreamWriter());
    writer->write(jm.toJson(), &os);
    return os;
}

std::istream& operator>>(std::istream& is, greentop::JsonMember& jm) {
    Json::Value json;
    is >> json;
    jm.fromJson(json);
    return is;
}

