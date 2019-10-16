/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/KeyLineSelection.h"

namespace greentop {
namespace stream {


KeyLineSelection::KeyLineSelection(const Optional<int64_t>& id,
    const Optional<double>& hc) :
    id(id),
    hc(hc) {
}

void KeyLineSelection::fromJson(const Json::Value& json) {
    if (json.isMember("id")) {
        id = json["id"].asInt64();
    }
    if (json.isMember("hc")) {
        hc = json["hc"].asDouble();
    }
}

Json::Value KeyLineSelection::toJson() const {
    Json::Value json(Json::objectValue);
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    if (hc.isValid()) {
        json["hc"] = hc.toJson();
    }
    return json;
}

bool KeyLineSelection::isValid() const {
    return true;
}

const Optional<int64_t>& KeyLineSelection::getId() const {
    return id;
}
void KeyLineSelection::setId(const Optional<int64_t>& id) {
    this->id = id;
}

const Optional<double>& KeyLineSelection::getHc() const {
    return hc;
}
void KeyLineSelection::setHc(const Optional<double>& hc) {
    this->hc = hc;
}


}
}
