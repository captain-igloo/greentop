#include "greentop/betting/ClearedOrderSummaryReport.h"

namespace greentop {

ClearedOrderSummaryReport::ClearedOrderSummaryReport(const std::string& eventTypeId,
    const std::string& eventId,
    const std::string& marketId,
    const uint64_t selectionId,
    const double handicap,
    const std::string& betId,
    const std::tm& placedDate,
    const PersistenceType& persistenceType,
    const OrderType& orderType,
    const Side& side,
    const ItemDescription& itemDescription,
    const double priceRequested,
    const std::tm& settledDate,
    const uint64_t betCount,
    const double commission,
    const double priceMatched,
    const BoolJsonMember& priceReduced,
    const double sizeSettled,
    const double profit,
    const double sizeCancelled) :
    eventTypeId(eventTypeId),
    eventId(eventId),
    marketId(marketId),
    selectionId(selectionId),
    handicap(handicap),
    betId(betId),
    placedDate(placedDate),
    persistenceType(persistenceType),
    orderType(orderType),
    side(side),
    itemDescription(itemDescription),
    priceRequested(priceRequested),
    settledDate(settledDate),
    betCount(betCount),
    commission(commission),
    priceMatched(priceMatched),
    priceReduced(priceReduced),
    sizeSettled(sizeSettled),
    profit(profit),
    sizeCancelled(sizeCancelled) {
}

void ClearedOrderSummaryReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("eventTypeId")) {
            eventTypeId = json["eventTypeId"].asString();
        }
        if (json.isMember("eventId")) {
            eventId = json["eventId"].asString();
        }
        if (json.isMember("marketId")) {
            marketId = json["marketId"].asString();
        }
        if (json.isMember("selectionId")) {
            selectionId = json["selectionId"].asUInt();
        }
        if (json.isMember("handicap")) {
            handicap = json["handicap"].asDouble();
        }
        if (json.isMember("betId")) {
            betId = json["betId"].asString();
        }
        if (json.isMember("placedDate")) {
            strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
        }
        if (json.isMember("persistenceType")) {
            persistenceType = json["persistenceType"].asString();
        }
        if (json.isMember("orderType")) {
            orderType = json["orderType"].asString();
        }
        if (json.isMember("side")) {
            side = json["side"].asString();
        }
        if (json.isMember("itemDescription")) {
            itemDescription.fromJson(json["itemDescription"]);
        }
        if (json.isMember("priceRequested")) {
            priceRequested = json["priceRequested"].asDouble();
        }
        if (json.isMember("settledDate")) {
            strptime(json["settledDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &settledDate);
        }
        if (json.isMember("betCount")) {
            betCount = json["betCount"].asUInt();
        }
        if (json.isMember("commission")) {
            commission = json["commission"].asDouble();
        }
        if (json.isMember("priceMatched")) {
            priceMatched = json["priceMatched"].asDouble();
        }
        if (json.isMember("priceReduced")) {
            priceReduced.fromJson(json["priceReduced"]);
        }
        if (json.isMember("sizeSettled")) {
            sizeSettled = json["sizeSettled"].asDouble();
        }
        if (json.isMember("profit")) {
            profit = json["profit"].asDouble();
        }
        if (json.isMember("sizeCancelled")) {
            sizeCancelled = json["sizeCancelled"].asDouble();
        }
    }
}

Json::Value ClearedOrderSummaryReport::toJson() const {
    Json::Value json;
    if (eventTypeId != "") {
        json["eventTypeId"] = eventTypeId;
    }
    if (eventId != "") {
        json["eventId"] = eventId;
    }
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (selectionId >= 0) {
        json["selectionId"] = selectionId;
    }
    if (handicap >= 0) {
        json["handicap"] = handicap;
    }
    if (betId != "") {
        json["betId"] = betId;
    }
    if (false) {
        // placedDate not implemented;
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    if (orderType.isValid()) {
        json["orderType"] = orderType.getValue();
    }
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (itemDescription.isValid()) {
        json["itemDescription"] = itemDescription.toJson();
    }
    if (priceRequested >= 0) {
        json["priceRequested"] = priceRequested;
    }
    if (false) {
        // settledDate not implemented;
    }
    if (betCount >= 0) {
        json["betCount"] = betCount;
    }
    if (commission >= 0) {
        json["commission"] = commission;
    }
    if (priceMatched >= 0) {
        json["priceMatched"] = priceMatched;
    }
    if (priceReduced.isValid()) {
        json["priceReduced"] = priceReduced.toJson();
    }
    if (sizeSettled >= 0) {
        json["sizeSettled"] = sizeSettled;
    }
    if (profit >= 0) {
        json["profit"] = profit;
    }
    if (sizeCancelled >= 0) {
        json["sizeCancelled"] = sizeCancelled;
    }
    return json;
}

bool ClearedOrderSummaryReport::isValid() const {
    return true;
}

const std::string& ClearedOrderSummaryReport::getEventTypeId() const {
    return eventTypeId;
}
void ClearedOrderSummaryReport::setEventTypeId(const std::string& eventTypeId) {
    this->eventTypeId = eventTypeId;
}

const std::string& ClearedOrderSummaryReport::getEventId() const {
    return eventId;
}
void ClearedOrderSummaryReport::setEventId(const std::string& eventId) {
    this->eventId = eventId;
}

const std::string& ClearedOrderSummaryReport::getMarketId() const {
    return marketId;
}
void ClearedOrderSummaryReport::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const uint64_t ClearedOrderSummaryReport::getSelectionId() const {
    return selectionId;
}
void ClearedOrderSummaryReport::setSelectionId(const uint64_t selectionId) {
    this->selectionId = selectionId;
}

const double ClearedOrderSummaryReport::getHandicap() const {
    return handicap;
}
void ClearedOrderSummaryReport::setHandicap(const double handicap) {
    this->handicap = handicap;
}

const std::string& ClearedOrderSummaryReport::getBetId() const {
    return betId;
}
void ClearedOrderSummaryReport::setBetId(const std::string& betId) {
    this->betId = betId;
}

const std::tm& ClearedOrderSummaryReport::getPlacedDate() const {
    return placedDate;
}
void ClearedOrderSummaryReport::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const PersistenceType& ClearedOrderSummaryReport::getPersistenceType() const {
    return persistenceType;
}
void ClearedOrderSummaryReport::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}

const OrderType& ClearedOrderSummaryReport::getOrderType() const {
    return orderType;
}
void ClearedOrderSummaryReport::setOrderType(const OrderType& orderType) {
    this->orderType = orderType;
}

const Side& ClearedOrderSummaryReport::getSide() const {
    return side;
}
void ClearedOrderSummaryReport::setSide(const Side& side) {
    this->side = side;
}

const ItemDescription& ClearedOrderSummaryReport::getItemDescription() const {
    return itemDescription;
}
void ClearedOrderSummaryReport::setItemDescription(const ItemDescription& itemDescription) {
    this->itemDescription = itemDescription;
}

const double ClearedOrderSummaryReport::getPriceRequested() const {
    return priceRequested;
}
void ClearedOrderSummaryReport::setPriceRequested(const double priceRequested) {
    this->priceRequested = priceRequested;
}

const std::tm& ClearedOrderSummaryReport::getSettledDate() const {
    return settledDate;
}
void ClearedOrderSummaryReport::setSettledDate(const std::tm& settledDate) {
    this->settledDate = settledDate;
}

const uint64_t ClearedOrderSummaryReport::getBetCount() const {
    return betCount;
}
void ClearedOrderSummaryReport::setBetCount(const uint64_t betCount) {
    this->betCount = betCount;
}

const double ClearedOrderSummaryReport::getCommission() const {
    return commission;
}
void ClearedOrderSummaryReport::setCommission(const double commission) {
    this->commission = commission;
}

const double ClearedOrderSummaryReport::getPriceMatched() const {
    return priceMatched;
}
void ClearedOrderSummaryReport::setPriceMatched(const double priceMatched) {
    this->priceMatched = priceMatched;
}

const BoolJsonMember& ClearedOrderSummaryReport::getPriceReduced() const {
    return priceReduced;
}
void ClearedOrderSummaryReport::setPriceReduced(const BoolJsonMember& priceReduced) {
    this->priceReduced = priceReduced;
}

const double ClearedOrderSummaryReport::getSizeSettled() const {
    return sizeSettled;
}
void ClearedOrderSummaryReport::setSizeSettled(const double sizeSettled) {
    this->sizeSettled = sizeSettled;
}

const double ClearedOrderSummaryReport::getProfit() const {
    return profit;
}
void ClearedOrderSummaryReport::setProfit(const double profit) {
    this->profit = profit;
}

const double ClearedOrderSummaryReport::getSizeCancelled() const {
    return sizeCancelled;
}
void ClearedOrderSummaryReport::setSizeCancelled(const double sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}


}



