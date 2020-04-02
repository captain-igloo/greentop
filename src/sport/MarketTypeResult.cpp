/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketTypeResult.h"

namespace greentop {
namespace sport {


MarketTypeResult::MarketTypeResult(const std::string& marketType,
    const Optional<int32_t>& marketCount) :
    marketType(marketType),
    marketCount(marketCount) {
}

void MarketTypeResult::fromJson(const Json::Value& json) {
    if (json.isMember("marketType")) {
        marketType = json["marketType"].asString();
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asInt();
    }
}

Json::Value MarketTypeResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketType != "") {
        json["marketType"] = marketType;
    }
    if (marketCount.isValid()) {
        json["marketCount"] = marketCount.toJson();
    }
    return json;
}

bool MarketTypeResult::isValid() const {
    return true;
}

const std::string& MarketTypeResult::getMarketType() const {
    return marketType;
}
void MarketTypeResult::setMarketType(const std::string& marketType) {
    this->marketType = marketType;
}

const Optional<int32_t>& MarketTypeResult::getMarketCount() const {
    return marketCount;
}
void MarketTypeResult::setMarketCount(const Optional<int32_t>& marketCount) {
    this->marketCount = marketCount;
}


}
}
