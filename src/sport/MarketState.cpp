/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketState.h"

namespace greentop {

MarketState::MarketState() : totalMatched(-1), totalAvailable(-1) {
}

MarketState::MarketState(const std::string& status,
    const int32_t betDelay,
    const bool bspReconciled,
    const bool complete,
    const bool inplay,
    const int32_t numberOfActiveRunners,
    const std::tm& lastMatchTime,
    const double totalMatched,
    const double totalAvailable) :
    status(status),
    betDelay(betDelay),
    bspReconciled(bspReconciled),
    complete(complete),
    inplay(inplay),
    numberOfActiveRunners(numberOfActiveRunners),
    lastMatchTime(lastMatchTime),
    totalMatched(totalMatched),
    totalAvailable(totalAvailable) {
}

void MarketState::fromJson(const Json::Value& json) {
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("betDelay")) {
        betDelay = json["betDelay"].asInt();
    }
    if (json.isMember("bspReconciled")) {
        bspReconciled = json["bspReconciled"].asBool();
    }
    if (json.isMember("complete")) {
        complete = json["complete"].asBool();
    }
    if (json.isMember("inplay")) {
        inplay = json["inplay"].asBool();
    }
    if (json.isMember("numberOfActiveRunners")) {
        numberOfActiveRunners = json["numberOfActiveRunners"].asInt();
    }
    if (json.isMember("lastMatchTime")) {
        strptime(json["lastMatchTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &lastMatchTime);
    }
    if (json.isMember("totalMatched")) {
        totalMatched = json["totalMatched"].asDouble();
    }
    if (json.isMember("totalAvailable")) {
        totalAvailable = json["totalAvailable"].asDouble();
    }
}

Json::Value MarketState::toJson() const {
    Json::Value json(Json::objectValue);
    if (status != "") {
        json["status"] = status;
    }
    if (betDelay.isValid()) {
        json["betDelay"] = betDelay.toJson();
    }
    if (bspReconciled.isValid()) {
        json["bspReconciled"] = bspReconciled.toJson();
    }
    if (complete.isValid()) {
        json["complete"] = complete.toJson();
    }
    if (inplay.isValid()) {
        json["inplay"] = inplay.toJson();
    }
    if (numberOfActiveRunners.isValid()) {
        json["numberOfActiveRunners"] = numberOfActiveRunners.toJson();
    }
    if (lastMatchTime.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &lastMatchTime);
        json["lastMatchTime"] = std::string(buffer);
    }
    json["totalMatched"] = totalMatched;
    json["totalAvailable"] = totalAvailable;
    return json;
}

bool MarketState::isValid() const {
    return status != "" && betDelay.isValid() && bspReconciled.isValid() && complete.isValid() && inplay.isValid() && numberOfActiveRunners.isValid() && lastMatchTime.tm_year > 0;
}

const std::string& MarketState::getStatus() const {
    return status;
}
void MarketState::setStatus(const std::string& status) {
    this->status = status;
}

const int32_t MarketState::getBetDelay() const {
    return betDelay;
}
void MarketState::setBetDelay(const int32_t betDelay) {
    this->betDelay = betDelay;
}

const bool MarketState::getBspReconciled() const {
    return bspReconciled;
}
void MarketState::setBspReconciled(const bool bspReconciled) {
    this->bspReconciled = bspReconciled;
}

const bool MarketState::getComplete() const {
    return complete;
}
void MarketState::setComplete(const bool complete) {
    this->complete = complete;
}

const bool MarketState::getInplay() const {
    return inplay;
}
void MarketState::setInplay(const bool inplay) {
    this->inplay = inplay;
}

const int32_t MarketState::getNumberOfActiveRunners() const {
    return numberOfActiveRunners;
}
void MarketState::setNumberOfActiveRunners(const int32_t numberOfActiveRunners) {
    this->numberOfActiveRunners = numberOfActiveRunners;
}

const std::tm& MarketState::getLastMatchTime() const {
    return lastMatchTime;
}
void MarketState::setLastMatchTime(const std::tm& lastMatchTime) {
    this->lastMatchTime = lastMatchTime;
}

const double MarketState::getTotalMatched() const {
    return totalMatched;
}
void MarketState::setTotalMatched(const double totalMatched) {
    this->totalMatched = totalMatched;
}

const double MarketState::getTotalAvailable() const {
    return totalAvailable;
}
void MarketState::setTotalAvailable(const double totalAvailable) {
    this->totalAvailable = totalAvailable;
}


}



