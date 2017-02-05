/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketLineRangeInfo.h"

namespace greentop {

MarketLineRangeInfo::MarketLineRangeInfo() {
}

MarketLineRangeInfo::MarketLineRangeInfo(const double maxUnitValue,
    const double minUnitValue,
    const double interval,
    const std::string& marketUnit) :
    maxUnitValue(maxUnitValue),
    minUnitValue(minUnitValue),
    interval(interval),
    marketUnit(marketUnit) {
}

void MarketLineRangeInfo::fromJson(const Json::Value& json) {
    if (json.isMember("maxUnitValue")) {
        maxUnitValue = json["maxUnitValue"].asDouble();
    }
    if (json.isMember("minUnitValue")) {
        minUnitValue = json["minUnitValue"].asDouble();
    }
    if (json.isMember("interval")) {
        interval = json["interval"].asDouble();
    }
    if (json.isMember("marketUnit")) {
        marketUnit = json["marketUnit"].asString();
    }
}

Json::Value MarketLineRangeInfo::toJson() const {
    Json::Value json(Json::objectValue);
    if (maxUnitValue.isValid()) {
        json["maxUnitValue"] = maxUnitValue.toJson();
    }
    if (minUnitValue.isValid()) {
        json["minUnitValue"] = minUnitValue.toJson();
    }
    if (interval.isValid()) {
        json["interval"] = interval.toJson();
    }
    if (marketUnit != "") {
        json["marketUnit"] = marketUnit;
    }
    return json;
}

bool MarketLineRangeInfo::isValid() const {
    return maxUnitValue.isValid() && minUnitValue.isValid() && interval.isValid() && marketUnit != "";
}

const double MarketLineRangeInfo::getMaxUnitValue() const {
    return maxUnitValue;
}
void MarketLineRangeInfo::setMaxUnitValue(const double maxUnitValue) {
    this->maxUnitValue = maxUnitValue;
}

const double MarketLineRangeInfo::getMinUnitValue() const {
    return minUnitValue;
}
void MarketLineRangeInfo::setMinUnitValue(const double minUnitValue) {
    this->minUnitValue = minUnitValue;
}

const double MarketLineRangeInfo::getInterval() const {
    return interval;
}
void MarketLineRangeInfo::setInterval(const double interval) {
    this->interval = interval;
}

const std::string& MarketLineRangeInfo::getMarketUnit() const {
    return marketUnit;
}
void MarketLineRangeInfo::setMarketUnit(const std::string& marketUnit) {
    this->marketUnit = marketUnit;
}


}



