/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/KeyLineDescription.h"

namespace greentop {
namespace sport {

KeyLineDescription::KeyLineDescription() {
}

KeyLineDescription::KeyLineDescription(const std::vector<KeyLineSelection>& keyLine) :
    keyLine(keyLine) {
}

void KeyLineDescription::fromJson(const Json::Value& json) {
    if (json.isMember("keyLine")) {
        for (unsigned i = 0; i < json["keyLine"].size(); ++i) {
            KeyLineSelection keyLineSelection;
            keyLineSelection.fromJson(json["keyLine"][i]);
            keyLine.push_back(keyLineSelection);
        }
    }
}

Json::Value KeyLineDescription::toJson() const {
    Json::Value json(Json::objectValue);
    if (keyLine.size() > 0) {
        for (unsigned i = 0; i < keyLine.size(); ++i) {
            json["keyLine"].append(keyLine[i].toJson());
        }
    }
    return json;
}

bool KeyLineDescription::isValid() const {
    return keyLine.size() > 0;
}

const std::vector<KeyLineSelection>& KeyLineDescription::getKeyLine() const {
    return keyLine;
}
void KeyLineDescription::setKeyLine(const std::vector<KeyLineSelection>& keyLine) {
    this->keyLine = keyLine;
}


}
}
