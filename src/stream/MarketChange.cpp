/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/MarketChange.h"

namespace greentop {
namespace stream {


MarketChange::MarketChange(const std::vector<RunnerChange>& rc,
    const Optional<bool>& img,
    const Optional<double>& tv,
    const Optional<bool>& con,
    const MarketDefinition& marketDefinition,
    const std::string& id) :
    rc(rc),
    img(img),
    tv(tv),
    con(con),
    marketDefinition(marketDefinition),
    id(id) {
}

void MarketChange::fromJson(const Json::Value& json) {
    if (json.isMember("rc")) {
        for (unsigned i = 0; i < json["rc"].size(); ++i) {
            RunnerChange runnerChange;
            runnerChange.fromJson(json["rc"][i]);
            rc.push_back(runnerChange);
        }
    }
    if (json.isMember("img")) {
        img = json["img"].asBool();
    }
    if (json.isMember("tv")) {
        tv = json["tv"].asDouble();
    }
    if (json.isMember("con")) {
        con = json["con"].asBool();
    }
    if (json.isMember("marketDefinition")) {
        marketDefinition.fromJson(json["marketDefinition"]);
    }
    if (json.isMember("id")) {
        id = json["id"].asString();
    }
}

Json::Value MarketChange::toJson() const {
    Json::Value json(Json::objectValue);
    if (rc.size() > 0) {
        for (unsigned i = 0; i < rc.size(); ++i) {
            json["rc"].append(rc[i].toJson());
        }
    }
    if (img.isValid()) {
        json["img"] = img.toJson();
    }
    if (tv.isValid()) {
        json["tv"] = tv.toJson();
    }
    if (con.isValid()) {
        json["con"] = con.toJson();
    }
    if (marketDefinition.isValid()) {
        json["marketDefinition"] = marketDefinition.toJson();
    }
    if (id != "") {
        json["id"] = id;
    }
    return json;
}

bool MarketChange::isValid() const {
    return true;
}

const std::vector<RunnerChange>& MarketChange::getRc() const {
    return rc;
}
void MarketChange::setRc(const std::vector<RunnerChange>& rc) {
    this->rc = rc;
}

const Optional<bool>& MarketChange::getImg() const {
    return img;
}
void MarketChange::setImg(const Optional<bool>& img) {
    this->img = img;
}

const Optional<double>& MarketChange::getTv() const {
    return tv;
}
void MarketChange::setTv(const Optional<double>& tv) {
    this->tv = tv;
}

const Optional<bool>& MarketChange::getCon() const {
    return con;
}
void MarketChange::setCon(const Optional<bool>& con) {
    this->con = con;
}

const MarketDefinition& MarketChange::getMarketDefinition() const {
    return marketDefinition;
}
void MarketChange::setMarketDefinition(const MarketDefinition& marketDefinition) {
    this->marketDefinition = marketDefinition;
}

const std::string& MarketChange::getId() const {
    return id;
}
void MarketChange::setId(const std::string& id) {
    this->id = id;
}


}
}
