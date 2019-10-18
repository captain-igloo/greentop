/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/MarketSubscriptionMessage.h"

namespace greentop {
namespace stream {


MarketSubscriptionMessage::MarketSubscriptionMessage(const std::string& op,
    const Optional<int32_t>& id,
    const Optional<bool>& segmentationEnabled,
    const std::string& clk,
    const Optional<int64_t>& heartbeatMs,
    const std::string& initialClk,
    const MarketFilter& marketFilter,
    const Optional<int64_t>& conflateMs,
    const MarketDataFilter& marketDataFilter) :
    op(op),
    id(id),
    segmentationEnabled(segmentationEnabled),
    clk(clk),
    heartbeatMs(heartbeatMs),
    initialClk(initialClk),
    marketFilter(marketFilter),
    conflateMs(conflateMs),
    marketDataFilter(marketDataFilter) {
}

void MarketSubscriptionMessage::fromJson(const Json::Value& json) {
    if (json.isMember("op")) {
        op = json["op"].asString();
    }
    if (json.isMember("id")) {
        id = json["id"].asInt();
    }
    if (json.isMember("segmentationEnabled")) {
        segmentationEnabled = json["segmentationEnabled"].asBool();
    }
    if (json.isMember("clk")) {
        clk = json["clk"].asString();
    }
    if (json.isMember("heartbeatMs")) {
        heartbeatMs = json["heartbeatMs"].asInt64();
    }
    if (json.isMember("initialClk")) {
        initialClk = json["initialClk"].asString();
    }
    if (json.isMember("marketFilter")) {
        marketFilter.fromJson(json["marketFilter"]);
    }
    if (json.isMember("conflateMs")) {
        conflateMs = json["conflateMs"].asInt64();
    }
    if (json.isMember("marketDataFilter")) {
        marketDataFilter.fromJson(json["marketDataFilter"]);
    }
}

Json::Value MarketSubscriptionMessage::toJson() const {
    Json::Value json(Json::objectValue);
    if (op != "") {
        json["op"] = op;
    }
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    if (segmentationEnabled.isValid()) {
        json["segmentationEnabled"] = segmentationEnabled.toJson();
    }
    if (clk != "") {
        json["clk"] = clk;
    }
    if (heartbeatMs.isValid()) {
        json["heartbeatMs"] = heartbeatMs.toJson();
    }
    if (initialClk != "") {
        json["initialClk"] = initialClk;
    }
    if (marketFilter.isValid()) {
        json["marketFilter"] = marketFilter.toJson();
    }
    if (conflateMs.isValid()) {
        json["conflateMs"] = conflateMs.toJson();
    }
    if (marketDataFilter.isValid()) {
        json["marketDataFilter"] = marketDataFilter.toJson();
    }
    return json;
}

bool MarketSubscriptionMessage::isValid() const {
    return true;
}

const std::string& MarketSubscriptionMessage::getOp() const {
    return op;
}
void MarketSubscriptionMessage::setOp(const std::string& op) {
    this->op = op;
}

const Optional<int32_t>& MarketSubscriptionMessage::getId() const {
    return id;
}
void MarketSubscriptionMessage::setId(const Optional<int32_t>& id) {
    this->id = id;
}

const Optional<bool>& MarketSubscriptionMessage::getSegmentationEnabled() const {
    return segmentationEnabled;
}
void MarketSubscriptionMessage::setSegmentationEnabled(const Optional<bool>& segmentationEnabled) {
    this->segmentationEnabled = segmentationEnabled;
}

const std::string& MarketSubscriptionMessage::getClk() const {
    return clk;
}
void MarketSubscriptionMessage::setClk(const std::string& clk) {
    this->clk = clk;
}

const Optional<int64_t>& MarketSubscriptionMessage::getHeartbeatMs() const {
    return heartbeatMs;
}
void MarketSubscriptionMessage::setHeartbeatMs(const Optional<int64_t>& heartbeatMs) {
    this->heartbeatMs = heartbeatMs;
}

const std::string& MarketSubscriptionMessage::getInitialClk() const {
    return initialClk;
}
void MarketSubscriptionMessage::setInitialClk(const std::string& initialClk) {
    this->initialClk = initialClk;
}

const MarketFilter& MarketSubscriptionMessage::getMarketFilter() const {
    return marketFilter;
}
void MarketSubscriptionMessage::setMarketFilter(const MarketFilter& marketFilter) {
    this->marketFilter = marketFilter;
}

const Optional<int64_t>& MarketSubscriptionMessage::getConflateMs() const {
    return conflateMs;
}
void MarketSubscriptionMessage::setConflateMs(const Optional<int64_t>& conflateMs) {
    this->conflateMs = conflateMs;
}

const MarketDataFilter& MarketSubscriptionMessage::getMarketDataFilter() const {
    return marketDataFilter;
}
void MarketSubscriptionMessage::setMarketDataFilter(const MarketDataFilter& marketDataFilter) {
    this->marketDataFilter = marketDataFilter;
}


}
}
