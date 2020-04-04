/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketGroup.h"

namespace greentop {
namespace sport {

MarketGroup::MarketGroup() {
}

MarketGroup::MarketGroup(const MarketGroupType& type,
    const MarketGroupId& id) :
    type(type),
    id(id) {
}

void MarketGroup::fromJson(const Json::Value& json) {
    if (json.isMember("type")) {
        type = json["type"].asString();
    }
    if (json.isMember("id")) {
        id.fromJson(json["id"]);
    }
}

Json::Value MarketGroup::toJson() const {
    Json::Value json(Json::objectValue);
    if (type.isValid()) {
        json["type"] = type.getValue();
    }
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    return json;
}

bool MarketGroup::isValid() const {
    return type.isValid() && id.isValid();
}

const MarketGroupType& MarketGroup::getType() const {
    return type;
}
void MarketGroup::setType(const MarketGroupType& type) {
    this->type = type;
}

const MarketGroupId& MarketGroup::getId() const {
    return id;
}
void MarketGroup::setId(const MarketGroupId& id) {
    this->id = id;
}


}
}
