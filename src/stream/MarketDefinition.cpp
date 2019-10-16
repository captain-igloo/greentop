/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/MarketDefinition.h"

namespace greentop {
namespace stream {


MarketDefinition::MarketDefinition(const std::string& venue,
    const std::string& raceType,
    const std::string& settledTime,
    const std::string& timezone,
    const Optional<double>& eachWayDivisor,
    const std::set<std::string>& regulators,
    const std::string& marketType,
    const Optional<double>& marketBaseRate,
    const Optional<int32_t>& numberOfWinners,
    const std::string& countryCode,
    const Optional<double>& lineMaxUnit,
    const Optional<bool>& inPlay,
    const Optional<int32_t>& betDelay,
    const Optional<bool>& bspMarket,
    const std::string& bettingType,
    const Optional<int32_t>& numberOfActiveRunners,
    const Optional<double>& lineMinUnit,
    const std::string& eventId,
    const Optional<bool>& crossMatching,
    const Optional<bool>& runnersVoidable,
    const Optional<bool>& turnInPlayEnabled,
    const PriceLadderDefinition& priceLadderDefinition,
    const KeyLineDefinition& keyLineDefinition,
    const std::string& suspendTime,
    const Optional<bool>& discountAllowed,
    const Optional<bool>& persistenceEnabled,
    const std::vector<RunnerDefinition>& runners,
    const Optional<int64_t>& version,
    const std::string& eventTypeId,
    const Optional<bool>& complete,
    const std::string& openDate,
    const std::string& marketTime,
    const Optional<bool>& bspReconciled,
    const Optional<double>& lineInterval,
    const std::string& status) :
    venue(venue),
    raceType(raceType),
    settledTime(settledTime),
    timezone(timezone),
    eachWayDivisor(eachWayDivisor),
    regulators(regulators),
    marketType(marketType),
    marketBaseRate(marketBaseRate),
    numberOfWinners(numberOfWinners),
    countryCode(countryCode),
    lineMaxUnit(lineMaxUnit),
    inPlay(inPlay),
    betDelay(betDelay),
    bspMarket(bspMarket),
    bettingType(bettingType),
    numberOfActiveRunners(numberOfActiveRunners),
    lineMinUnit(lineMinUnit),
    eventId(eventId),
    crossMatching(crossMatching),
    runnersVoidable(runnersVoidable),
    turnInPlayEnabled(turnInPlayEnabled),
    priceLadderDefinition(priceLadderDefinition),
    keyLineDefinition(keyLineDefinition),
    suspendTime(suspendTime),
    discountAllowed(discountAllowed),
    persistenceEnabled(persistenceEnabled),
    runners(runners),
    version(version),
    eventTypeId(eventTypeId),
    complete(complete),
    openDate(openDate),
    marketTime(marketTime),
    bspReconciled(bspReconciled),
    lineInterval(lineInterval),
    status(status) {
}

void MarketDefinition::fromJson(const Json::Value& json) {
    if (json.isMember("venue")) {
        venue = json["venue"].asString();
    }
    if (json.isMember("raceType")) {
        raceType = json["raceType"].asString();
    }
    if (json.isMember("settledTime")) {
        settledTime = json["settledTime"].asString();
    }
    if (json.isMember("timezone")) {
        timezone = json["timezone"].asString();
    }
    if (json.isMember("eachWayDivisor")) {
        eachWayDivisor = json["eachWayDivisor"].asDouble();
    }
    if (json.isMember("regulators")) {
        for (unsigned i = 0; i < json["regulators"].size(); ++i) {
            regulators.insert(json["regulators"][i].asString());
        }
    }
    if (json.isMember("marketType")) {
        marketType = json["marketType"].asString();
    }
    if (json.isMember("marketBaseRate")) {
        marketBaseRate = json["marketBaseRate"].asDouble();
    }
    if (json.isMember("numberOfWinners")) {
        numberOfWinners = json["numberOfWinners"].asInt();
    }
    if (json.isMember("countryCode")) {
        countryCode = json["countryCode"].asString();
    }
    if (json.isMember("lineMaxUnit")) {
        lineMaxUnit = json["lineMaxUnit"].asDouble();
    }
    if (json.isMember("inPlay")) {
        inPlay = json["inPlay"].asBool();
    }
    if (json.isMember("betDelay")) {
        betDelay = json["betDelay"].asInt();
    }
    if (json.isMember("bspMarket")) {
        bspMarket = json["bspMarket"].asBool();
    }
    if (json.isMember("bettingType")) {
        bettingType = json["bettingType"].asString();
    }
    if (json.isMember("numberOfActiveRunners")) {
        numberOfActiveRunners = json["numberOfActiveRunners"].asInt();
    }
    if (json.isMember("lineMinUnit")) {
        lineMinUnit = json["lineMinUnit"].asDouble();
    }
    if (json.isMember("eventId")) {
        eventId = json["eventId"].asString();
    }
    if (json.isMember("crossMatching")) {
        crossMatching = json["crossMatching"].asBool();
    }
    if (json.isMember("runnersVoidable")) {
        runnersVoidable = json["runnersVoidable"].asBool();
    }
    if (json.isMember("turnInPlayEnabled")) {
        turnInPlayEnabled = json["turnInPlayEnabled"].asBool();
    }
    if (json.isMember("priceLadderDefinition")) {
        priceLadderDefinition.fromJson(json["priceLadderDefinition"]);
    }
    if (json.isMember("keyLineDefinition")) {
        keyLineDefinition.fromJson(json["keyLineDefinition"]);
    }
    if (json.isMember("suspendTime")) {
        suspendTime = json["suspendTime"].asString();
    }
    if (json.isMember("discountAllowed")) {
        discountAllowed = json["discountAllowed"].asBool();
    }
    if (json.isMember("persistenceEnabled")) {
        persistenceEnabled = json["persistenceEnabled"].asBool();
    }
    if (json.isMember("runners")) {
        for (unsigned i = 0; i < json["runners"].size(); ++i) {
            RunnerDefinition runner;
            runner.fromJson(json["runners"][i]);
            runners.push_back(runner);
        }
    }
    if (json.isMember("version")) {
        version = json["version"].asInt64();
    }
    if (json.isMember("eventTypeId")) {
        eventTypeId = json["eventTypeId"].asString();
    }
    if (json.isMember("complete")) {
        complete = json["complete"].asBool();
    }
    if (json.isMember("openDate")) {
        openDate = json["openDate"].asString();
    }
    if (json.isMember("marketTime")) {
        marketTime = json["marketTime"].asString();
    }
    if (json.isMember("bspReconciled")) {
        bspReconciled = json["bspReconciled"].asBool();
    }
    if (json.isMember("lineInterval")) {
        lineInterval = json["lineInterval"].asDouble();
    }
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
}

Json::Value MarketDefinition::toJson() const {
    Json::Value json(Json::objectValue);
    if (venue != "") {
        json["venue"] = venue;
    }
    if (raceType != "") {
        json["raceType"] = raceType;
    }
    if (settledTime != "") {
        json["settledTime"] = settledTime;
    }
    if (timezone != "") {
        json["timezone"] = timezone;
    }
    if (eachWayDivisor.isValid()) {
        json["eachWayDivisor"] = eachWayDivisor.toJson();
    }
    if (regulators.size() > 0) {
        for (std::set<std::string>::const_iterator it = regulators.begin(); it != regulators.end(); ++it) {
            json["regulators"].append(*it);
        }
    }
    if (marketType != "") {
        json["marketType"] = marketType;
    }
    if (marketBaseRate.isValid()) {
        json["marketBaseRate"] = marketBaseRate.toJson();
    }
    if (numberOfWinners.isValid()) {
        json["numberOfWinners"] = numberOfWinners.toJson();
    }
    if (countryCode != "") {
        json["countryCode"] = countryCode;
    }
    if (lineMaxUnit.isValid()) {
        json["lineMaxUnit"] = lineMaxUnit.toJson();
    }
    if (inPlay.isValid()) {
        json["inPlay"] = inPlay.toJson();
    }
    if (betDelay.isValid()) {
        json["betDelay"] = betDelay.toJson();
    }
    if (bspMarket.isValid()) {
        json["bspMarket"] = bspMarket.toJson();
    }
    if (bettingType != "") {
        json["bettingType"] = bettingType;
    }
    if (numberOfActiveRunners.isValid()) {
        json["numberOfActiveRunners"] = numberOfActiveRunners.toJson();
    }
    if (lineMinUnit.isValid()) {
        json["lineMinUnit"] = lineMinUnit.toJson();
    }
    if (eventId != "") {
        json["eventId"] = eventId;
    }
    if (crossMatching.isValid()) {
        json["crossMatching"] = crossMatching.toJson();
    }
    if (runnersVoidable.isValid()) {
        json["runnersVoidable"] = runnersVoidable.toJson();
    }
    if (turnInPlayEnabled.isValid()) {
        json["turnInPlayEnabled"] = turnInPlayEnabled.toJson();
    }
    if (priceLadderDefinition.isValid()) {
        json["priceLadderDefinition"] = priceLadderDefinition.toJson();
    }
    if (keyLineDefinition.isValid()) {
        json["keyLineDefinition"] = keyLineDefinition.toJson();
    }
    if (suspendTime != "") {
        json["suspendTime"] = suspendTime;
    }
    if (discountAllowed.isValid()) {
        json["discountAllowed"] = discountAllowed.toJson();
    }
    if (persistenceEnabled.isValid()) {
        json["persistenceEnabled"] = persistenceEnabled.toJson();
    }
    if (runners.size() > 0) {
        for (unsigned i = 0; i < runners.size(); ++i) {
            json["runners"].append(runners[i].toJson());
        }
    }
    if (version.isValid()) {
        json["version"] = version.toJson();
    }
    if (eventTypeId != "") {
        json["eventTypeId"] = eventTypeId;
    }
    if (complete.isValid()) {
        json["complete"] = complete.toJson();
    }
    if (openDate != "") {
        json["openDate"] = openDate;
    }
    if (marketTime != "") {
        json["marketTime"] = marketTime;
    }
    if (bspReconciled.isValid()) {
        json["bspReconciled"] = bspReconciled.toJson();
    }
    if (lineInterval.isValid()) {
        json["lineInterval"] = lineInterval.toJson();
    }
    if (status != "") {
        json["status"] = status;
    }
    return json;
}

bool MarketDefinition::isValid() const {
    return true;
}

const std::string& MarketDefinition::getVenue() const {
    return venue;
}
void MarketDefinition::setVenue(const std::string& venue) {
    this->venue = venue;
}

const std::string& MarketDefinition::getRaceType() const {
    return raceType;
}
void MarketDefinition::setRaceType(const std::string& raceType) {
    this->raceType = raceType;
}

const std::string& MarketDefinition::getSettledTime() const {
    return settledTime;
}
void MarketDefinition::setSettledTime(const std::string& settledTime) {
    this->settledTime = settledTime;
}

const std::string& MarketDefinition::getTimezone() const {
    return timezone;
}
void MarketDefinition::setTimezone(const std::string& timezone) {
    this->timezone = timezone;
}

const Optional<double>& MarketDefinition::getEachWayDivisor() const {
    return eachWayDivisor;
}
void MarketDefinition::setEachWayDivisor(const Optional<double>& eachWayDivisor) {
    this->eachWayDivisor = eachWayDivisor;
}

const std::set<std::string>& MarketDefinition::getRegulators() const {
    return regulators;
}
void MarketDefinition::setRegulators(const std::set<std::string>& regulators) {
    this->regulators = regulators;
}

const std::string& MarketDefinition::getMarketType() const {
    return marketType;
}
void MarketDefinition::setMarketType(const std::string& marketType) {
    this->marketType = marketType;
}

const Optional<double>& MarketDefinition::getMarketBaseRate() const {
    return marketBaseRate;
}
void MarketDefinition::setMarketBaseRate(const Optional<double>& marketBaseRate) {
    this->marketBaseRate = marketBaseRate;
}

const Optional<int32_t>& MarketDefinition::getNumberOfWinners() const {
    return numberOfWinners;
}
void MarketDefinition::setNumberOfWinners(const Optional<int32_t>& numberOfWinners) {
    this->numberOfWinners = numberOfWinners;
}

const std::string& MarketDefinition::getCountryCode() const {
    return countryCode;
}
void MarketDefinition::setCountryCode(const std::string& countryCode) {
    this->countryCode = countryCode;
}

const Optional<double>& MarketDefinition::getLineMaxUnit() const {
    return lineMaxUnit;
}
void MarketDefinition::setLineMaxUnit(const Optional<double>& lineMaxUnit) {
    this->lineMaxUnit = lineMaxUnit;
}

const Optional<bool>& MarketDefinition::getInPlay() const {
    return inPlay;
}
void MarketDefinition::setInPlay(const Optional<bool>& inPlay) {
    this->inPlay = inPlay;
}

const Optional<int32_t>& MarketDefinition::getBetDelay() const {
    return betDelay;
}
void MarketDefinition::setBetDelay(const Optional<int32_t>& betDelay) {
    this->betDelay = betDelay;
}

const Optional<bool>& MarketDefinition::getBspMarket() const {
    return bspMarket;
}
void MarketDefinition::setBspMarket(const Optional<bool>& bspMarket) {
    this->bspMarket = bspMarket;
}

const std::string& MarketDefinition::getBettingType() const {
    return bettingType;
}
void MarketDefinition::setBettingType(const std::string& bettingType) {
    this->bettingType = bettingType;
}

const Optional<int32_t>& MarketDefinition::getNumberOfActiveRunners() const {
    return numberOfActiveRunners;
}
void MarketDefinition::setNumberOfActiveRunners(const Optional<int32_t>& numberOfActiveRunners) {
    this->numberOfActiveRunners = numberOfActiveRunners;
}

const Optional<double>& MarketDefinition::getLineMinUnit() const {
    return lineMinUnit;
}
void MarketDefinition::setLineMinUnit(const Optional<double>& lineMinUnit) {
    this->lineMinUnit = lineMinUnit;
}

const std::string& MarketDefinition::getEventId() const {
    return eventId;
}
void MarketDefinition::setEventId(const std::string& eventId) {
    this->eventId = eventId;
}

const Optional<bool>& MarketDefinition::getCrossMatching() const {
    return crossMatching;
}
void MarketDefinition::setCrossMatching(const Optional<bool>& crossMatching) {
    this->crossMatching = crossMatching;
}

const Optional<bool>& MarketDefinition::getRunnersVoidable() const {
    return runnersVoidable;
}
void MarketDefinition::setRunnersVoidable(const Optional<bool>& runnersVoidable) {
    this->runnersVoidable = runnersVoidable;
}

const Optional<bool>& MarketDefinition::getTurnInPlayEnabled() const {
    return turnInPlayEnabled;
}
void MarketDefinition::setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled) {
    this->turnInPlayEnabled = turnInPlayEnabled;
}

const PriceLadderDefinition& MarketDefinition::getPriceLadderDefinition() const {
    return priceLadderDefinition;
}
void MarketDefinition::setPriceLadderDefinition(const PriceLadderDefinition& priceLadderDefinition) {
    this->priceLadderDefinition = priceLadderDefinition;
}

const KeyLineDefinition& MarketDefinition::getKeyLineDefinition() const {
    return keyLineDefinition;
}
void MarketDefinition::setKeyLineDefinition(const KeyLineDefinition& keyLineDefinition) {
    this->keyLineDefinition = keyLineDefinition;
}

const std::string& MarketDefinition::getSuspendTime() const {
    return suspendTime;
}
void MarketDefinition::setSuspendTime(const std::string& suspendTime) {
    this->suspendTime = suspendTime;
}

const Optional<bool>& MarketDefinition::getDiscountAllowed() const {
    return discountAllowed;
}
void MarketDefinition::setDiscountAllowed(const Optional<bool>& discountAllowed) {
    this->discountAllowed = discountAllowed;
}

const Optional<bool>& MarketDefinition::getPersistenceEnabled() const {
    return persistenceEnabled;
}
void MarketDefinition::setPersistenceEnabled(const Optional<bool>& persistenceEnabled) {
    this->persistenceEnabled = persistenceEnabled;
}

const std::vector<RunnerDefinition>& MarketDefinition::getRunners() const {
    return runners;
}
void MarketDefinition::setRunners(const std::vector<RunnerDefinition>& runners) {
    this->runners = runners;
}

const Optional<int64_t>& MarketDefinition::getVersion() const {
    return version;
}
void MarketDefinition::setVersion(const Optional<int64_t>& version) {
    this->version = version;
}

const std::string& MarketDefinition::getEventTypeId() const {
    return eventTypeId;
}
void MarketDefinition::setEventTypeId(const std::string& eventTypeId) {
    this->eventTypeId = eventTypeId;
}

const Optional<bool>& MarketDefinition::getComplete() const {
    return complete;
}
void MarketDefinition::setComplete(const Optional<bool>& complete) {
    this->complete = complete;
}

const std::string& MarketDefinition::getOpenDate() const {
    return openDate;
}
void MarketDefinition::setOpenDate(const std::string& openDate) {
    this->openDate = openDate;
}

const std::string& MarketDefinition::getMarketTime() const {
    return marketTime;
}
void MarketDefinition::setMarketTime(const std::string& marketTime) {
    this->marketTime = marketTime;
}

const Optional<bool>& MarketDefinition::getBspReconciled() const {
    return bspReconciled;
}
void MarketDefinition::setBspReconciled(const Optional<bool>& bspReconciled) {
    this->bspReconciled = bspReconciled;
}

const Optional<double>& MarketDefinition::getLineInterval() const {
    return lineInterval;
}
void MarketDefinition::setLineInterval(const Optional<double>& lineInterval) {
    this->lineInterval = lineInterval;
}

const std::string& MarketDefinition::getStatus() const {
    return status;
}
void MarketDefinition::setStatus(const std::string& status) {
    this->status = status;
}


}
}
