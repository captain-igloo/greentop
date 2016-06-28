/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/MarketBook.h"

namespace greentop {
MarketBook::MarketBook()  : isMarketDataDelayed(0), betDelay(-1), numberOfWinners(-1), numberOfRunners(-1), numberOfActiveRunners(-1), version(0){
}

MarketBook::MarketBook(const std::string& marketId,
    const bool isMarketDataDelayed,
    const MarketStatus& status,
    const int betDelay,
    const Optional<bool>& bspReconciled,
    const Optional<bool>& complete,
    const Optional<bool>& inplay,
    const int numberOfWinners,
    const int numberOfRunners,
    const int numberOfActiveRunners,
    const std::tm& lastMatchTime,
    const Optional<double>& totalMatched,
    const Optional<double>& totalAvailable,
    const Optional<bool>& crossMatching,
    const Optional<bool>& runnersVoidable,
    const uint64_t version,
    const std::vector<Runner>& runners) :
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
    runners(runners) {
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
        bspReconciled.fromJson(json["bspReconciled"]);
    }
    if (json.isMember("complete")) {
        complete.fromJson(json["complete"]);
    }
    if (json.isMember("inplay")) {
        inplay.fromJson(json["inplay"]);
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
        totalMatched.fromJson(json["totalMatched"]);
    }
    if (json.isMember("totalAvailable")) {
        totalAvailable.fromJson(json["totalAvailable"]);
    }
    if (json.isMember("crossMatching")) {
        crossMatching.fromJson(json["crossMatching"]);
    }
    if (json.isMember("runnersVoidable")) {
        runnersVoidable.fromJson(json["runnersVoidable"]);
    }
    if (json.isMember("version")) {
        version = json["version"].asUInt64();
    }
    if (json.isMember("runners")) {
        for (unsigned i = 0; i < json["runners"].size(); ++i) {
                Runner runner;
                runner.fromJson(json["runners"][i]);
                runners.push_back(runner);
            };
    }
}

Json::Value MarketBook::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    json["isMarketDataDelayed"] = isMarketDataDelayed;
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (betDelay >= 0) {
        json["betDelay"] = betDelay;
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
    if (numberOfWinners >= 0) {
        json["numberOfWinners"] = numberOfWinners;
    }
    if (numberOfRunners >= 0) {
        json["numberOfRunners"] = numberOfRunners;
    }
    if (numberOfActiveRunners >= 0) {
        json["numberOfActiveRunners"] = numberOfActiveRunners;
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
    if (version > 0) {
        json["version"] = version;
    }
    if (runners.size() > 0) {
        for (unsigned i = 0; i < runners.size(); ++i) {
            json["runners"].append(runners[i].toJson());
        };
    }
    return json;
}

bool MarketBook::isValid() const {
    return marketId != "" && true;
}

const std::string& MarketBook::getMarketId() const {
    return marketId;
}
void MarketBook::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const bool MarketBook::getIsMarketDataDelayed() const {
    return isMarketDataDelayed;
}
void MarketBook::setIsMarketDataDelayed(const bool isMarketDataDelayed) {
    this->isMarketDataDelayed = isMarketDataDelayed;
}

const MarketStatus& MarketBook::getStatus() const {
    return status;
}
void MarketBook::setStatus(const MarketStatus& status) {
    this->status = status;
}

const int MarketBook::getBetDelay() const {
    return betDelay;
}
void MarketBook::setBetDelay(const int betDelay) {
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

const int MarketBook::getNumberOfWinners() const {
    return numberOfWinners;
}
void MarketBook::setNumberOfWinners(const int numberOfWinners) {
    this->numberOfWinners = numberOfWinners;
}

const int MarketBook::getNumberOfRunners() const {
    return numberOfRunners;
}
void MarketBook::setNumberOfRunners(const int numberOfRunners) {
    this->numberOfRunners = numberOfRunners;
}

const int MarketBook::getNumberOfActiveRunners() const {
    return numberOfActiveRunners;
}
void MarketBook::setNumberOfActiveRunners(const int numberOfActiveRunners) {
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

const uint64_t MarketBook::getVersion() const {
    return version;
}
void MarketBook::setVersion(const uint64_t version) {
    this->version = version;
}

const std::vector<Runner>& MarketBook::getRunners() const {
    return runners;
}
void MarketBook::setRunners(const std::vector<Runner>& runners) {
    this->runners = runners;
}


}



