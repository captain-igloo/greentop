/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/KeyLineSelection.h"

namespace greentop {

KeyLineSelection::KeyLineSelection() {
}

KeyLineSelection::KeyLineSelection(const Optional<int64_t>& selectionId,
    const Optional<double>& handicap) :
    selectionId(selectionId),
    handicap(handicap) {
}

void KeyLineSelection::fromJson(const Json::Value& json) {
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
}

Json::Value KeyLineSelection::toJson() const {
    Json::Value json(Json::objectValue);
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
    }
    return json;
}

bool KeyLineSelection::isValid() const {
    return selectionId.isValid() && handicap.isValid();
}

const Optional<int64_t>& KeyLineSelection::getSelectionId() const {
    return selectionId;
}
void KeyLineSelection::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& KeyLineSelection::getHandicap() const {
    return handicap;
}
void KeyLineSelection::setHandicap(const Optional<double>& handicap) {
    this->handicap = handicap;
}


}



