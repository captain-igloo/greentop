/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/KeyLineDefinition.h"

namespace greentop {
namespace stream {


KeyLineDefinition::KeyLineDefinition(const std::vector<KeyLineSelection>& kl) :
    kl(kl) {
}

void KeyLineDefinition::fromJson(const Json::Value& json) {
    if (json.isMember("kl")) {
        for (unsigned i = 0; i < json["kl"].size(); ++i) {
            KeyLineSelection keyLineSelection;
            keyLineSelection.fromJson(json["kl"][i]);
            kl.push_back(keyLineSelection);
        }
    }
}

Json::Value KeyLineDefinition::toJson() const {
    Json::Value json(Json::objectValue);
    if (kl.size() > 0) {
        for (unsigned i = 0; i < kl.size(); ++i) {
            json["kl"].append(kl[i].toJson());
        }
    }
    return json;
}

bool KeyLineDefinition::isValid() const {
    return true;
}

const std::vector<KeyLineSelection>& KeyLineDefinition::getKl() const {
    return kl;
}
void KeyLineDefinition::setKl(const std::vector<KeyLineSelection>& kl) {
    this->kl = kl;
}


}
}
