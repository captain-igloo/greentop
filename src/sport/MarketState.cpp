/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketState.h"

namespace greentop {
namespace sport {

MarketState::MarketState() {
}

MarketState::MarketState(const std::string& status,
    const Optional<int32_t>& betDelay,
    const Optional<bool>& bspReconciled,
    const Optional<bool>& complete,
    const Optional<bool>& inplay,
    const Optional<int32_t>& numberOfActiveRunners,
    const std::tm& lastMatchTime,
    const Optional<double>& totalMatched,
    const Optional<double>& totalAvailable,
    const KeyLineDescription& keyLineDescription) :
    status(status),
    betDelay(betDelay),
    bspReconciled(bspReconciled),
    complete(complete),
    inplay(inplay),
    numberOfActiveRunners(numberOfActiveRunners),
    lastMatchTime(lastMatchTime),
    totalMatched(totalMatched),
    totalAvailable(totalAvailable),
    keyLineDescription(keyLineDescription) {
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
    if (json.isMember("keyLineDescription")) {
        keyLineDescription.fromJson(json["keyLineDescription"]);
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
    if (totalMatched.isValid()) {
        json["totalMatched"] = totalMatched.toJson();
    }
    if (totalAvailable.isValid()) {
        json["totalAvailable"] = totalAvailable.toJson();
    }
    if (keyLineDescription.isValid()) {
        json["keyLineDescription"] = keyLineDescription.toJson();
    }
    return json;
}

bool MarketState::isValid() const {
    return status != "" && betDelay.isValid() && bspReconciled.isValid() && complete.isValid() && inplay.isValid() && numberOfActiveRunners.isValid() && lastMatchTime.tm_year > 0 && totalMatched.isValid() && totalAvailable.isValid();
}

const std::string& MarketState::getStatus() const {
    return status;
}
void MarketState::setStatus(const std::string& status) {
    this->status = status;
}

const Optional<int32_t>& MarketState::getBetDelay() const {
    return betDelay;
}
void MarketState::setBetDelay(const Optional<int32_t>& betDelay) {
    this->betDelay = betDelay;
}

const Optional<bool>& MarketState::getBspReconciled() const {
    return bspReconciled;
}
void MarketState::setBspReconciled(const Optional<bool>& bspReconciled) {
    this->bspReconciled = bspReconciled;
}

const Optional<bool>& MarketState::getComplete() const {
    return complete;
}
void MarketState::setComplete(const Optional<bool>& complete) {
    this->complete = complete;
}

const Optional<bool>& MarketState::getInplay() const {
    return inplay;
}
void MarketState::setInplay(const Optional<bool>& inplay) {
    this->inplay = inplay;
}

const Optional<int32_t>& MarketState::getNumberOfActiveRunners() const {
    return numberOfActiveRunners;
}
void MarketState::setNumberOfActiveRunners(const Optional<int32_t>& numberOfActiveRunners) {
    this->numberOfActiveRunners = numberOfActiveRunners;
}

const std::tm& MarketState::getLastMatchTime() const {
    return lastMatchTime;
}
void MarketState::setLastMatchTime(const std::tm& lastMatchTime) {
    this->lastMatchTime = lastMatchTime;
}

const Optional<double>& MarketState::getTotalMatched() const {
    return totalMatched;
}
void MarketState::setTotalMatched(const Optional<double>& totalMatched) {
    this->totalMatched = totalMatched;
}

const Optional<double>& MarketState::getTotalAvailable() const {
    return totalAvailable;
}
void MarketState::setTotalAvailable(const Optional<double>& totalAvailable) {
    this->totalAvailable = totalAvailable;
}

const KeyLineDescription& MarketState::getKeyLineDescription() const {
    return keyLineDescription;
}
void MarketState::setKeyLineDescription(const KeyLineDescription& keyLineDescription) {
    this->keyLineDescription = keyLineDescription;
}


}
}
