/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/StatementLegacyData.h"

namespace greentop {
namespace account {


StatementLegacyData::StatementLegacyData(const Optional<double>& avgPrice,
    const Optional<double>& betSize,
    const std::string& betType,
    const std::string& betCategoryType,
    const std::string& commissionRate,
    const Optional<int64_t>& eventId,
    const Optional<int64_t>& eventTypeId,
    const std::string& fullMarketName,
    const Optional<double>& grossBetAmount,
    const std::string& marketName,
    const std::string& marketType,
    const std::tm& placedDate,
    const Optional<int64_t>& selectionId,
    const std::string& selectionName,
    const std::tm& startDate,
    const std::string& transactionType,
    const Optional<int64_t>& transactionId,
    const std::string& winLose) :
    avgPrice(avgPrice),
    betSize(betSize),
    betType(betType),
    betCategoryType(betCategoryType),
    commissionRate(commissionRate),
    eventId(eventId),
    eventTypeId(eventTypeId),
    fullMarketName(fullMarketName),
    grossBetAmount(grossBetAmount),
    marketName(marketName),
    marketType(marketType),
    placedDate(placedDate),
    selectionId(selectionId),
    selectionName(selectionName),
    startDate(startDate),
    transactionType(transactionType),
    transactionId(transactionId),
    winLose(winLose) {
}

void StatementLegacyData::fromJson(const Json::Value& json) {
    if (json.isMember("avgPrice")) {
        avgPrice = json["avgPrice"].asDouble();
    }
    if (json.isMember("betSize")) {
        betSize = json["betSize"].asDouble();
    }
    if (json.isMember("betType")) {
        betType = json["betType"].asString();
    }
    if (json.isMember("betCategoryType")) {
        betCategoryType = json["betCategoryType"].asString();
    }
    if (json.isMember("commissionRate")) {
        commissionRate = json["commissionRate"].asString();
    }
    if (json.isMember("eventId")) {
        eventId = json["eventId"].asInt64();
    }
    if (json.isMember("eventTypeId")) {
        eventTypeId = json["eventTypeId"].asInt64();
    }
    if (json.isMember("fullMarketName")) {
        fullMarketName = json["fullMarketName"].asString();
    }
    if (json.isMember("grossBetAmount")) {
        grossBetAmount = json["grossBetAmount"].asDouble();
    }
    if (json.isMember("marketName")) {
        marketName = json["marketName"].asString();
    }
    if (json.isMember("marketType")) {
        marketType = json["marketType"].asString();
    }
    if (json.isMember("placedDate")) {
        strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
    }
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asInt64();
    }
    if (json.isMember("selectionName")) {
        selectionName = json["selectionName"].asString();
    }
    if (json.isMember("startDate")) {
        strptime(json["startDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &startDate);
    }
    if (json.isMember("transactionType")) {
        transactionType = json["transactionType"].asString();
    }
    if (json.isMember("transactionId")) {
        transactionId = json["transactionId"].asInt64();
    }
    if (json.isMember("winLose")) {
        winLose = json["winLose"].asString();
    }
}

Json::Value StatementLegacyData::toJson() const {
    Json::Value json(Json::objectValue);
    if (avgPrice.isValid()) {
        json["avgPrice"] = avgPrice.toJson();
    }
    if (betSize.isValid()) {
        json["betSize"] = betSize.toJson();
    }
    if (betType != "") {
        json["betType"] = betType;
    }
    if (betCategoryType != "") {
        json["betCategoryType"] = betCategoryType;
    }
    if (commissionRate != "") {
        json["commissionRate"] = commissionRate;
    }
    if (eventId.isValid()) {
        json["eventId"] = eventId.toJson();
    }
    if (eventTypeId.isValid()) {
        json["eventTypeId"] = eventTypeId.toJson();
    }
    if (fullMarketName != "") {
        json["fullMarketName"] = fullMarketName;
    }
    if (grossBetAmount.isValid()) {
        json["grossBetAmount"] = grossBetAmount.toJson();
    }
    if (marketName != "") {
        json["marketName"] = marketName;
    }
    if (marketType != "") {
        json["marketType"] = marketType;
    }
    if (placedDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
        json["placedDate"] = std::string(buffer);
    }
    if (selectionId.isValid()) {
        json["selectionId"] = selectionId.toJson();
    }
    if (selectionName != "") {
        json["selectionName"] = selectionName;
    }
    if (startDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &startDate);
        json["startDate"] = std::string(buffer);
    }
    if (transactionType != "") {
        json["transactionType"] = transactionType;
    }
    if (transactionId.isValid()) {
        json["transactionId"] = transactionId.toJson();
    }
    if (winLose != "") {
        json["winLose"] = winLose;
    }
    return json;
}

bool StatementLegacyData::isValid() const {
    return true;
}

const Optional<double>& StatementLegacyData::getAvgPrice() const {
    return avgPrice;
}
void StatementLegacyData::setAvgPrice(const Optional<double>& avgPrice) {
    this->avgPrice = avgPrice;
}

const Optional<double>& StatementLegacyData::getBetSize() const {
    return betSize;
}
void StatementLegacyData::setBetSize(const Optional<double>& betSize) {
    this->betSize = betSize;
}

const std::string& StatementLegacyData::getBetType() const {
    return betType;
}
void StatementLegacyData::setBetType(const std::string& betType) {
    this->betType = betType;
}

const std::string& StatementLegacyData::getBetCategoryType() const {
    return betCategoryType;
}
void StatementLegacyData::setBetCategoryType(const std::string& betCategoryType) {
    this->betCategoryType = betCategoryType;
}

const std::string& StatementLegacyData::getCommissionRate() const {
    return commissionRate;
}
void StatementLegacyData::setCommissionRate(const std::string& commissionRate) {
    this->commissionRate = commissionRate;
}

const Optional<int64_t>& StatementLegacyData::getEventId() const {
    return eventId;
}
void StatementLegacyData::setEventId(const Optional<int64_t>& eventId) {
    this->eventId = eventId;
}

const Optional<int64_t>& StatementLegacyData::getEventTypeId() const {
    return eventTypeId;
}
void StatementLegacyData::setEventTypeId(const Optional<int64_t>& eventTypeId) {
    this->eventTypeId = eventTypeId;
}

const std::string& StatementLegacyData::getFullMarketName() const {
    return fullMarketName;
}
void StatementLegacyData::setFullMarketName(const std::string& fullMarketName) {
    this->fullMarketName = fullMarketName;
}

const Optional<double>& StatementLegacyData::getGrossBetAmount() const {
    return grossBetAmount;
}
void StatementLegacyData::setGrossBetAmount(const Optional<double>& grossBetAmount) {
    this->grossBetAmount = grossBetAmount;
}

const std::string& StatementLegacyData::getMarketName() const {
    return marketName;
}
void StatementLegacyData::setMarketName(const std::string& marketName) {
    this->marketName = marketName;
}

const std::string& StatementLegacyData::getMarketType() const {
    return marketType;
}
void StatementLegacyData::setMarketType(const std::string& marketType) {
    this->marketType = marketType;
}

const std::tm& StatementLegacyData::getPlacedDate() const {
    return placedDate;
}
void StatementLegacyData::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const Optional<int64_t>& StatementLegacyData::getSelectionId() const {
    return selectionId;
}
void StatementLegacyData::setSelectionId(const Optional<int64_t>& selectionId) {
    this->selectionId = selectionId;
}

const std::string& StatementLegacyData::getSelectionName() const {
    return selectionName;
}
void StatementLegacyData::setSelectionName(const std::string& selectionName) {
    this->selectionName = selectionName;
}

const std::tm& StatementLegacyData::getStartDate() const {
    return startDate;
}
void StatementLegacyData::setStartDate(const std::tm& startDate) {
    this->startDate = startDate;
}

const std::string& StatementLegacyData::getTransactionType() const {
    return transactionType;
}
void StatementLegacyData::setTransactionType(const std::string& transactionType) {
    this->transactionType = transactionType;
}

const Optional<int64_t>& StatementLegacyData::getTransactionId() const {
    return transactionId;
}
void StatementLegacyData::setTransactionId(const Optional<int64_t>& transactionId) {
    this->transactionId = transactionId;
}

const std::string& StatementLegacyData::getWinLose() const {
    return winLose;
}
void StatementLegacyData::setWinLose(const std::string& winLose) {
    this->winLose = winLose;
}


}
}
