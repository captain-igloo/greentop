/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/RunnerId.h"

namespace greentop {
RunnerId::RunnerId()  : handicap(-1){
}

RunnerId::RunnerId(const std::string& marketId,
    const std::string& selectionId,
    const double handicap) :
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap) {
}

void RunnerId::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asString();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
}

Json::Value RunnerId::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (selectionId != "") {
        json["selectionId"] = selectionId;
    }
    if (handicap >= 0) {
        json["handicap"] = handicap;
    }
    return json;
}

bool RunnerId::isValid() const {
    return marketId != "" && selectionId != "";
}

const std::string& RunnerId::getMarketId() const {
    return marketId;
}
void RunnerId::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::string& RunnerId::getSelectionId() const {
    return selectionId;
}
void RunnerId::setSelectionId(const std::string& selectionId) {
    this->selectionId = selectionId;
}

const double RunnerId::getHandicap() const {
    return handicap;
}
void RunnerId::setHandicap(const double handicap) {
    this->handicap = handicap;
}


}



