/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PriceLadderDescription.h"

namespace greentop {

PriceLadderDescription::PriceLadderDescription() {
}

PriceLadderDescription::PriceLadderDescription(const PriceLadderType& type) :
    type(type) {
}

void PriceLadderDescription::fromJson(const Json::Value& json) {
    if (json.isMember("type")) {
        type = json["type"].asString();
    }
}

Json::Value PriceLadderDescription::toJson() const {
    Json::Value json(Json::objectValue);
    if (type.isValid()) {
        json["type"] = type.getValue();
    }
    return json;
}

bool PriceLadderDescription::isValid() const {
    return type.isValid();
}

const PriceLadderType& PriceLadderDescription::getType() const {
    return type;
}
void PriceLadderDescription::setType(const PriceLadderType& type) {
    this->type = type;
}


}



