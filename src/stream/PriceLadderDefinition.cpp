/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/PriceLadderDefinition.h"

namespace greentop {
namespace stream {


PriceLadderDefinition::PriceLadderDefinition(const std::string& type) :
    type(type) {
}

void PriceLadderDefinition::fromJson(const Json::Value& json) {
    if (json.isMember("type")) {
        type = json["type"].asString();
    }
}

Json::Value PriceLadderDefinition::toJson() const {
    Json::Value json(Json::objectValue);
    if (type != "") {
        json["type"] = type;
    }
    return json;
}

bool PriceLadderDefinition::isValid() const {
    return true;
}

const std::string& PriceLadderDefinition::getType() const {
    return type;
}
void PriceLadderDefinition::setType(const std::string& type) {
    this->type = type;
}


}
}
