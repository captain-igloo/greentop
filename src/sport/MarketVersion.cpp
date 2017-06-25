/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketVersion.h"

namespace greentop {


MarketVersion::MarketVersion(const Optional<int64_t>& version) :
    version(version) {
}

void MarketVersion::fromJson(const Json::Value& json) {
    if (json.isMember("version")) {
        version = json["version"].asInt64();
    }
}

Json::Value MarketVersion::toJson() const {
    Json::Value json(Json::objectValue);
    if (version.isValid()) {
        json["version"] = version.toJson();
    }
    return json;
}

bool MarketVersion::isValid() const {
    return true;
}

const Optional<int64_t>& MarketVersion::getVersion() const {
    return version;
}
void MarketVersion::setVersion(const Optional<int64_t>& version) {
    this->version = version;
}


}



