/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketBook.h"

namespace greentop {

MarketBook::MarketBook() {
}

MarketBook::MarketBook(const std::string& marketId,
    const Optional<bool>& isMarketDataDelayed,
    const MarketStatus& status,
    const Optional<int32_t>& betDelay,
    const Optional<bool>& bspReconciled,
    const Optional<bool>& complete,
    const Optional<bool>& inplay,
    const Optional<int32_t>& numberOfWinners,
    const Optional<int32_t>& numberOfRunners,
    const Optional<int32_t>& numberOfActiveRunners,
    const std::tm& lastMatchTime,
    const Optional<double>& totalMatched,
    const Optional<double>& totalAvailable,
    const Optional<bool>& crossMatching,
    const Optional<bool>& runnersVoidable,
    const Optional<int64_t>& version,
    const std::vector<Runner>& runners,
    const KeyLineDescription& keyLineDescription) :
    marketId(marketId),
    isMarketDataDelayed(isMarketDataDelayed),
    status(status),
    betDelay(betDelay),
    bspReconciled(bspReconciled),
    complete(complete),
    inplay(inplay),
    numberOfWinners(numberOfWinners),
    numberOfRunners(numberOfRunners),
    numberOfActiveRunners(numberOfActiveRunners),
    lastMatchTime(lastMatchTime),
    totalMatched(totalMatched),
    totalAvailable(totalAvailable),
    crossMatching(crossMatching),
    runnersVoidable(runnersVoidable),
    version(version),
    runners(runners),
    keyLineDescription(keyLineDescription) {
}

void MarketBook::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("isMarketDataDelayed")) {
        isMarketDataDelayed = json["isMarketDataDelayed"].asBool();
    }
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
    if (json.isMember("numberOfWinners")) {
        numberOfWinners = json["numberOfWinners"].asInt();
    }
    if (json.isMember("numberOfRunners")) {
        numberOfRunners = json["numberOfRunners"].asInt();
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
    if (json.isMember("crossMatching")) {
        crossMatching = json["crossMatching"].asBool();
    }
    if (json.isMember("runnersVoidable")) {
        runnersVoidable = json["runnersVoidable"].asBool();
    }
    if (json.isMember("version")) {
        version = json["version"].asInt64();
    }
    if (json.isMember("runners")) {
        for (unsigned i = 0; i < json["runners"].size(); ++i) {
            Runner runner;
            runner.fromJson(json["runners"][i]);
            runners.push_back(runner);
        }
    }
    if (json.isMember("keyLineDescription")) {
        keyLineDescription.fromJson(json["keyLineDescription"]);
    }
}

Json::Value MarketBook::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (isMarketDataDelayed.isValid()) {
        json["isMarketDataDelayed"] = isMarketDataDelayed.toJson();
    }
    if (status.isValid()) {
        json["status"] = status.getValue();
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
    if (numberOfWinners.isValid()) {
        json["numberOfWinners"] = numberOfWinners.toJson();
    }
    if (numberOfRunners.isValid()) {
        json["numberOfRunners"] = numberOfRunners.toJson();
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
    if (crossMatching.isValid()) {
        json["crossMatching"] = crossMatching.toJson();
    }
    if (runnersVoidable.isValid()) {
        json["runnersVoidable"] = runnersVoidable.toJson();
    }
    if (version.isValid()) {
        json["version"] = version.toJson();
    }
    if (runners.size() > 0) {
        for (unsigned i = 0; i < runners.size(); ++i) {
            json["runners"].append(runners[i].toJson());
        }
    }
    if (keyLineDescription.isValid()) {
        json["keyLineDescription"] = keyLineDescription.toJson();
    }
    return json;
}

bool MarketBook::isValid() const {
    return marketId != "" && isMarketDataDelayed.isValid();
}

const std::string& MarketBook::getMarketId() const {
    return marketId;
}
void MarketBook::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const Optional<bool>& MarketBook::getIsMarketDataDelayed() const {
    return isMarketDataDelayed;
}
void MarketBook::setIsMarketDataDelayed(const Optional<bool>& isMarketDataDelayed) {
    this->isMarketDataDelayed = isMarketDataDelayed;
}

const MarketStatus& MarketBook::getStatus() const {
    return status;
}
void MarketBook::setStatus(const MarketStatus& status) {
    this->status = status;
}

const Optional<int32_t>& MarketBook::getBetDelay() const {
    return betDelay;
}
void MarketBook::setBetDelay(const Optional<int32_t>& betDelay) {
    this->betDelay = betDelay;
}

const Optional<bool>& MarketBook::getBspReconciled() const {
    return bspReconciled;
}
void MarketBook::setBspReconciled(const Optional<bool>& bspReconciled) {
    this->bspReconciled = bspReconciled;
}

const Optional<bool>& MarketBook::getComplete() const {
    return complete;
}
void MarketBook::setComplete(const Optional<bool>& complete) {
    this->complete = complete;
}

const Optional<bool>& MarketBook::getInplay() const {
    return inplay;
}
void MarketBook::setInplay(const Optional<bool>& inplay) {
    this->inplay = inplay;
}

const Optional<int32_t>& MarketBook::getNumberOfWinners() const {
    return numberOfWinners;
}
void MarketBook::setNumberOfWinners(const Optional<int32_t>& numberOfWinners) {
    this->numberOfWinners = numberOfWinners;
}

const Optional<int32_t>& MarketBook::getNumberOfRunners() const {
    return numberOfRunners;
}
void MarketBook::setNumberOfRunners(const Optional<int32_t>& numberOfRunners) {
    this->numberOfRunners = numberOfRunners;
}

const Optional<int32_t>& MarketBook::getNumberOfActiveRunners() const {
    return numberOfActiveRunners;
}
void MarketBook::setNumberOfActiveRunners(const Optional<int32_t>& numberOfActiveRunners) {
    this->numberOfActiveRunners = numberOfActiveRunners;
}

const std::tm& MarketBook::getLastMatchTime() const {
    return lastMatchTime;
}
void MarketBook::setLastMatchTime(const std::tm& lastMatchTime) {
    this->lastMatchTime = lastMatchTime;
}

const Optional<double>& MarketBook::getTotalMatched() const {
    return totalMatched;
}
void MarketBook::setTotalMatched(const Optional<double>& totalMatched) {
    this->totalMatched = totalMatched;
}

const Optional<double>& MarketBook::getTotalAvailable() const {
    return totalAvailable;
}
void MarketBook::setTotalAvailable(const Optional<double>& totalAvailable) {
    this->totalAvailable = totalAvailable;
}

const Optional<bool>& MarketBook::getCrossMatching() const {
    return crossMatching;
}
void MarketBook::setCrossMatching(const Optional<bool>& crossMatching) {
    this->crossMatching = crossMatching;
}

const Optional<bool>& MarketBook::getRunnersVoidable() const {
    return runnersVoidable;
}
void MarketBook::setRunnersVoidable(const Optional<bool>& runnersVoidable) {
    this->runnersVoidable = runnersVoidable;
}

const Optional<int64_t>& MarketBook::getVersion() const {
    return version;
}
void MarketBook::setVersion(const Optional<int64_t>& version) {
    this->version = version;
}

const std::vector<Runner>& MarketBook::getRunners() const {
    return runners;
}
void MarketBook::setRunners(const std::vector<Runner>& runners) {
    this->runners = runners;
}

const KeyLineDescription& MarketBook::getKeyLineDescription() const {
    return keyLineDescription;
}
void MarketBook::setKeyLineDescription(const KeyLineDescription& keyLineDescription) {
    this->keyLineDescription = keyLineDescription;
}


}



