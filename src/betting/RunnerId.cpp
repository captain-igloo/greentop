/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/RunnerId.h"

namespace greentop {
RunnerId::RunnerId()  : selectionId(0){
}

RunnerId::RunnerId(const std::string& marketId,
    const uint64_t selectionId,
    const Optional<double>& handicap) :
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap) {
}

void RunnerId::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asUInt64();
    }
    if (json.isMember("handicap")) {
        handicap.fromJson(json["handicap"]);
    }
}

Json::Value RunnerId::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (selectionId > 0) {
        json["selectionId"] = selectionId;
    }
    if (handicap.isValid()) {
        json["handicap"] = handicap.toJson();
    }
    return json;
}

bool RunnerId::isValid() const {
    return marketId != "" && selectionId > 0;
}

const std::string& RunnerId::getMarketId() const {
    return marketId;
}
void RunnerId::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const uint64_t RunnerId::getSelectionId() const {
    return selectionId;
}
void RunnerId::setSelectionId(const uint64_t selectionId) {
    this->selectionId = selectionId;
}

const Optional<double>& RunnerId::getHandicap() const {
    return handicap;
}
void RunnerId::setHandicap(const Optional<double>& handicap) {
    this->handicap = handicap;
}


}



