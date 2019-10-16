/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/MarketChangeMessage.h"

namespace greentop {
namespace stream {


MarketChangeMessage::MarketChangeMessage(const std::string& op,
    const Optional<int32_t>& id,
    const std::string& ct,
    const std::string& clk,
    const Optional<int64_t>& heartbeatMs,
    const Optional<int64_t>& pt,
    const std::string& initialClk,
    const std::vector<MarketChange>& mc,
    const Optional<int64_t>& conflateMs,
    const std::string& segmentType,
    const Optional<int32_t>& status) :
    op(op),
    id(id),
    ct(ct),
    clk(clk),
    heartbeatMs(heartbeatMs),
    pt(pt),
    initialClk(initialClk),
    mc(mc),
    conflateMs(conflateMs),
    segmentType(segmentType),
    status(status) {
}

void MarketChangeMessage::fromJson(const Json::Value& json) {
    if (json.isMember("op")) {
        op = json["op"].asString();
    }
    if (json.isMember("id")) {
        id = json["id"].asInt();
    }
    if (json.isMember("ct")) {
        ct = json["ct"].asString();
    }
    if (json.isMember("clk")) {
        clk = json["clk"].asString();
    }
    if (json.isMember("heartbeatMs")) {
        heartbeatMs = json["heartbeatMs"].asInt64();
    }
    if (json.isMember("pt")) {
        pt = json["pt"].asInt64();
    }
    if (json.isMember("initialClk")) {
        initialClk = json["initialClk"].asString();
    }
    if (json.isMember("mc")) {
        for (unsigned i = 0; i < json["mc"].size(); ++i) {
            MarketChange marketChange;
            marketChange.fromJson(json["mc"][i]);
            mc.push_back(marketChange);
        }
    }
    if (json.isMember("conflateMs")) {
        conflateMs = json["conflateMs"].asInt64();
    }
    if (json.isMember("segmentType")) {
        segmentType = json["segmentType"].asString();
    }
    if (json.isMember("status")) {
        status = json["status"].asInt();
    }
}

Json::Value MarketChangeMessage::toJson() const {
    Json::Value json(Json::objectValue);
    if (op != "") {
        json["op"] = op;
    }
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    if (ct != "") {
        json["ct"] = ct;
    }
    if (clk != "") {
        json["clk"] = clk;
    }
    if (heartbeatMs.isValid()) {
        json["heartbeatMs"] = heartbeatMs.toJson();
    }
    if (pt.isValid()) {
        json["pt"] = pt.toJson();
    }
    if (initialClk != "") {
        json["initialClk"] = initialClk;
    }
    if (mc.size() > 0) {
        for (unsigned i = 0; i < mc.size(); ++i) {
            json["mc"].append(mc[i].toJson());
        }
    }
    if (conflateMs.isValid()) {
        json["conflateMs"] = conflateMs.toJson();
    }
    if (segmentType != "") {
        json["segmentType"] = segmentType;
    }
    if (status.isValid()) {
        json["status"] = status.toJson();
    }
    return json;
}

bool MarketChangeMessage::isValid() const {
    return true;
}

const std::string& MarketChangeMessage::getOp() const {
    return op;
}
void MarketChangeMessage::setOp(const std::string& op) {
    this->op = op;
}

const Optional<int32_t>& MarketChangeMessage::getId() const {
    return id;
}
void MarketChangeMessage::setId(const Optional<int32_t>& id) {
    this->id = id;
}

const std::string& MarketChangeMessage::getCt() const {
    return ct;
}
void MarketChangeMessage::setCt(const std::string& ct) {
    this->ct = ct;
}

const std::string& MarketChangeMessage::getClk() const {
    return clk;
}
void MarketChangeMessage::setClk(const std::string& clk) {
    this->clk = clk;
}

const Optional<int64_t>& MarketChangeMessage::getHeartbeatMs() const {
    return heartbeatMs;
}
void MarketChangeMessage::setHeartbeatMs(const Optional<int64_t>& heartbeatMs) {
    this->heartbeatMs = heartbeatMs;
}

const Optional<int64_t>& MarketChangeMessage::getPt() const {
    return pt;
}
void MarketChangeMessage::setPt(const Optional<int64_t>& pt) {
    this->pt = pt;
}

const std::string& MarketChangeMessage::getInitialClk() const {
    return initialClk;
}
void MarketChangeMessage::setInitialClk(const std::string& initialClk) {
    this->initialClk = initialClk;
}

const std::vector<MarketChange>& MarketChangeMessage::getMc() const {
    return mc;
}
void MarketChangeMessage::setMc(const std::vector<MarketChange>& mc) {
    this->mc = mc;
}

const Optional<int64_t>& MarketChangeMessage::getConflateMs() const {
    return conflateMs;
}
void MarketChangeMessage::setConflateMs(const Optional<int64_t>& conflateMs) {
    this->conflateMs = conflateMs;
}

const std::string& MarketChangeMessage::getSegmentType() const {
    return segmentType;
}
void MarketChangeMessage::setSegmentType(const std::string& segmentType) {
    this->segmentType = segmentType;
}

const Optional<int32_t>& MarketChangeMessage::getStatus() const {
    return status;
}
void MarketChangeMessage::setStatus(const Optional<int32_t>& status) {
    this->status = status;
}


}
}
