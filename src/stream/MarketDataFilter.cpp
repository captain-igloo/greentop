/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/MarketDataFilter.h"

namespace greentop {
namespace stream {


MarketDataFilter::MarketDataFilter(const Optional<int32_t>& ladderLevels,
    const std::set<std::string>& fields) :
    ladderLevels(ladderLevels),
    fields(fields) {
}

void MarketDataFilter::fromJson(const Json::Value& json) {
    if (json.isMember("ladderLevels")) {
        ladderLevels = json["ladderLevels"].asInt();
    }
    if (json.isMember("fields")) {
        for (unsigned i = 0; i < json["fields"].size(); ++i) {
            fields.insert(json["fields"][i].asString());
        }
    }
}

Json::Value MarketDataFilter::toJson() const {
    Json::Value json(Json::objectValue);
    if (ladderLevels.isValid()) {
        json["ladderLevels"] = ladderLevels.toJson();
    }
    if (fields.size() > 0) {
        for (std::set<std::string>::const_iterator it = fields.begin(); it != fields.end(); ++it) {
            json["fields"].append(*it);
        }
    }
    return json;
}

bool MarketDataFilter::isValid() const {
    return true;
}

const Optional<int32_t>& MarketDataFilter::getLadderLevels() const {
    return ladderLevels;
}
void MarketDataFilter::setLadderLevels(const Optional<int32_t>& ladderLevels) {
    this->ladderLevels = ladderLevels;
}

const std::set<std::string>& MarketDataFilter::getFields() const {
    return fields;
}
void MarketDataFilter::setFields(const std::set<std::string>& fields) {
    this->fields = fields;
}


}
}
