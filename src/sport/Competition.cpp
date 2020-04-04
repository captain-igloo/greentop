/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/Competition.h"

namespace greentop {
namespace sport {


Competition::Competition(const std::string& id,
    const std::string& name) :
    id(id),
    name(name) {
}

void Competition::fromJson(const Json::Value& json) {
    if (json.isMember("id")) {
        id = json["id"].asString();
    }
    if (json.isMember("name")) {
        name = json["name"].asString();
    }
}

Json::Value Competition::toJson() const {
    Json::Value json(Json::objectValue);
    if (id != "") {
        json["id"] = id;
    }
    if (name != "") {
        json["name"] = name;
    }
    return json;
}

bool Competition::isValid() const {
    return true;
}

const std::string& Competition::getId() const {
    return id;
}
void Competition::setId(const std::string& id) {
    this->id = id;
}

const std::string& Competition::getName() const {
    return name;
}
void Competition::setName(const std::string& name) {
    this->name = name;
}


}
}
