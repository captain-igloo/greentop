#include "greentop/betting/MarketBook.h"

namespace greentop {
MarketBook::MarketBook()  : betDelay(-1), numberOfWinners(-1), numberOfRunners(-1), numberOfActiveRunners(-1), totalMatched(-1), totalAvailable(-1), version(0){
}

MarketBook::MarketBook(const std::string& marketId,
    const BoolJsonMember& isMarketDataDelayed,
    const MarketStatus& status,
    const int betDelay,
    const BoolJsonMember& bspReconciled,
    const BoolJsonMember& complete,
    const BoolJsonMember& inplay,
    const int numberOfWinners,
    const int numberOfRunners,
    const int numberOfActiveRunners,
    const std::tm& lastMatchTime,
    const double totalMatched,
    const double totalAvailable,
    const BoolJsonMember& crossMatching,
    const BoolJsonMember& runnersVoidable,
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
        isMarketDataDelayed.fromJson(json["isMarketDataDelayed"]);
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
        totalMatched = json["totalMatched"].asDouble();
    }
    if (json.isMember("totalAvailable")) {
        totalAvailable = json["totalAvailable"].asDouble();
    }
    if (json.isMember("crossMatching")) {
        crossMatching.fromJson(json["crossMatching"]);
    }
    if (json.isMember("runnersVoidable")) {
        runnersVoidable.fromJson(json["runnersVoidable"]);
    }
    if (json.isMember("version")) {
        version = json["version"].asUInt();
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
    Json::Value json;
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (isMarketDataDelayed.isValid()) {
        json["isMarketDataDelayed"] = isMarketDataDelayed.toJson();
    }
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
    if (false) {
        // lastMatchTime not implemented;
    }
    if (totalMatched >= 0) {
        json["totalMatched"] = totalMatched;
    }
    if (totalAvailable >= 0) {
        json["totalAvailable"] = totalAvailable;
    }
    if (crossMatching.isValid()) {
        json["crossMatching"] = crossMatching.toJson();
    }
    if (runnersVoidable.isValid()) {
        json["runnersVoidable"] = runnersVoidable.toJson();
    }
    if (version >= 0) {
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
    return marketId != "" && isMarketDataDelayed.isValid();
}

const std::string& MarketBook::getMarketId() const {
    return marketId;
}
void MarketBook::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const BoolJsonMember& MarketBook::getIsMarketDataDelayed() const {
    return isMarketDataDelayed;
}
void MarketBook::setIsMarketDataDelayed(const BoolJsonMember& isMarketDataDelayed) {
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

const BoolJsonMember& MarketBook::getBspReconciled() const {
    return bspReconciled;
}
void MarketBook::setBspReconciled(const BoolJsonMember& bspReconciled) {
    this->bspReconciled = bspReconciled;
}

const BoolJsonMember& MarketBook::getComplete() const {
    return complete;
}
void MarketBook::setComplete(const BoolJsonMember& complete) {
    this->complete = complete;
}

const BoolJsonMember& MarketBook::getInplay() const {
    return inplay;
}
void MarketBook::setInplay(const BoolJsonMember& inplay) {
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

const double MarketBook::getTotalMatched() const {
    return totalMatched;
}
void MarketBook::setTotalMatched(const double totalMatched) {
    this->totalMatched = totalMatched;
}

const double MarketBook::getTotalAvailable() const {
    return totalAvailable;
}
void MarketBook::setTotalAvailable(const double totalAvailable) {
    this->totalAvailable = totalAvailable;
}

const BoolJsonMember& MarketBook::getCrossMatching() const {
    return crossMatching;
}
void MarketBook::setCrossMatching(const BoolJsonMember& crossMatching) {
    this->crossMatching = crossMatching;
}

const BoolJsonMember& MarketBook::getRunnersVoidable() const {
    return runnersVoidable;
}
void MarketBook::setRunnersVoidable(const BoolJsonMember& runnersVoidable) {
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



