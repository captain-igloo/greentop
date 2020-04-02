/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/Matches.h"

namespace greentop {
namespace sport {


Matches::Matches(const std::vector<Match>& matches) :
    matches(matches) {
}

void Matches::fromJson(const Json::Value& json) {
    if (json.isMember("matches")) {
        for (unsigned i = 0; i < json["matches"].size(); ++i) {
            Match matche;
            matche.fromJson(json["matches"][i]);
            matches.push_back(matche);
        }
    }
}

Json::Value Matches::toJson() const {
    Json::Value json(Json::objectValue);
    if (matches.size() > 0) {
        for (unsigned i = 0; i < matches.size(); ++i) {
            json["matches"].append(matches[i].toJson());
        }
    }
    return json;
}

bool Matches::isValid() const {
    return true;
}

const std::vector<Match>& Matches::getMatches() const {
    return matches;
}
void Matches::setMatches(const std::vector<Match>& matches) {
    this->matches = matches;
}


}
}
