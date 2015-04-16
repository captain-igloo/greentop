#include "greentop/betting/StatementLegacyData.h"

namespace greentop {

StatementLegacyData::StatementLegacyData(const double avgPrice,
    const double betSize,
    const std::string& betType,
    const std::string& betCategoryType,
    const std::string& commissionRate,
    const uint64_t eventId,
    const uint64_t eventTypeId,
    const std::string& fullMarketName,
    const double grossBetAmount,
    const std::string& marketName,
    const std::string& marketType,
    const std::tm& placedDate,
    const uint64_t selectionId,
    const std::string& selectionName,
    const std::tm& startDate,
    const std::string& transactionType,
    const uint64_t transactionId,
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
        eventId = json["eventId"].asUInt();
    }
    if (json.isMember("eventTypeId")) {
        eventTypeId = json["eventTypeId"].asUInt();
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
        selectionId = json["selectionId"].asUInt();
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
        transactionId = json["transactionId"].asUInt();
    }
    if (json.isMember("winLose")) {
        winLose = json["winLose"].asString();
    }
}

Json::Value StatementLegacyData::toJson() const {
    Json::Value json;
    if (avgPrice >= 0) {
        json["avgPrice"] = avgPrice;
    }
    if (betSize >= 0) {
        json["betSize"] = betSize;
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
    if (eventId >= 0) {
        json["eventId"] = eventId;
    }
    if (eventTypeId >= 0) {
        json["eventTypeId"] = eventTypeId;
    }
    if (fullMarketName != "") {
        json["fullMarketName"] = fullMarketName;
    }
    if (grossBetAmount >= 0) {
        json["grossBetAmount"] = grossBetAmount;
    }
    if (marketName != "") {
        json["marketName"] = marketName;
    }
    if (marketType != "") {
        json["marketType"] = marketType;
    }
    if (false) {
        // placedDate not implemented;
    }
    if (selectionId >= 0) {
        json["selectionId"] = selectionId;
    }
    if (selectionName != "") {
        json["selectionName"] = selectionName;
    }
    if (false) {
        // startDate not implemented;
    }
    if (transactionType != "") {
        json["transactionType"] = transactionType;
    }
    if (transactionId >= 0) {
        json["transactionId"] = transactionId;
    }
    if (winLose != "") {
        json["winLose"] = winLose;
    }
    return json;
}

bool StatementLegacyData::isValid() const {
    return true;
}

const double StatementLegacyData::getAvgPrice() const {
    return avgPrice;
}
void StatementLegacyData::setAvgPrice(const double avgPrice) {
    this->avgPrice = avgPrice;
}

const double StatementLegacyData::getBetSize() const {
    return betSize;
}
void StatementLegacyData::setBetSize(const double betSize) {
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

const uint64_t StatementLegacyData::getEventId() const {
    return eventId;
}
void StatementLegacyData::setEventId(const uint64_t eventId) {
    this->eventId = eventId;
}

const uint64_t StatementLegacyData::getEventTypeId() const {
    return eventTypeId;
}
void StatementLegacyData::setEventTypeId(const uint64_t eventTypeId) {
    this->eventTypeId = eventTypeId;
}

const std::string& StatementLegacyData::getFullMarketName() const {
    return fullMarketName;
}
void StatementLegacyData::setFullMarketName(const std::string& fullMarketName) {
    this->fullMarketName = fullMarketName;
}

const double StatementLegacyData::getGrossBetAmount() const {
    return grossBetAmount;
}
void StatementLegacyData::setGrossBetAmount(const double grossBetAmount) {
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

const uint64_t StatementLegacyData::getSelectionId() const {
    return selectionId;
}
void StatementLegacyData::setSelectionId(const uint64_t selectionId) {
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

const uint64_t StatementLegacyData::getTransactionId() const {
    return transactionId;
}
void StatementLegacyData::setTransactionId(const uint64_t transactionId) {
    this->transactionId = transactionId;
}

const std::string& StatementLegacyData::getWinLose() const {
    return winLose;
}
void StatementLegacyData::setWinLose(const std::string& winLose) {
    this->winLose = winLose;
}


}



