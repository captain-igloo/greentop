#include "greentop/betting/Order.h"

namespace greentop {
Order::Order()  : price(-1), size(-1), bspLiability(-1), avgPriceMatched(-1), sizeMatched(-1), sizeRemaining(-1), sizeLapsed(-1), sizeCancelled(-1), sizeVoided(-1){
}

Order::Order(const std::string& betId,
    const OrderType& orderType,
    const OrderStatus& status,
    const PersistenceType& persistenceType,
    const Side& side,
    const double price,
    const double size,
    const double bspLiability,
    const std::tm& placedDate,
    const double avgPriceMatched,
    const double sizeMatched,
    const double sizeRemaining,
    const double sizeLapsed,
    const double sizeCancelled,
    const double sizeVoided) :
    betId(betId),
    orderType(orderType),
    status(status),
    persistenceType(persistenceType),
    side(side),
    price(price),
    size(size),
    bspLiability(bspLiability),
    placedDate(placedDate),
    avgPriceMatched(avgPriceMatched),
    sizeMatched(sizeMatched),
    sizeRemaining(sizeRemaining),
    sizeLapsed(sizeLapsed),
    sizeCancelled(sizeCancelled),
    sizeVoided(sizeVoided) {
}

void Order::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("orderType")) {
        orderType = json["orderType"].asString();
    }
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
    if (json.isMember("persistenceType")) {
        persistenceType = json["persistenceType"].asString();
    }
    if (json.isMember("side")) {
        side = json["side"].asString();
    }
    if (json.isMember("price")) {
        price = json["price"].asDouble();
    }
    if (json.isMember("size")) {
        size = json["size"].asDouble();
    }
    if (json.isMember("bspLiability")) {
        bspLiability = json["bspLiability"].asDouble();
    }
    if (json.isMember("placedDate")) {
        strptime(json["placedDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &placedDate);
    }
    if (json.isMember("avgPriceMatched")) {
        avgPriceMatched = json["avgPriceMatched"].asDouble();
    }
    if (json.isMember("sizeMatched")) {
        sizeMatched = json["sizeMatched"].asDouble();
    }
    if (json.isMember("sizeRemaining")) {
        sizeRemaining = json["sizeRemaining"].asDouble();
    }
    if (json.isMember("sizeLapsed")) {
        sizeLapsed = json["sizeLapsed"].asDouble();
    }
    if (json.isMember("sizeCancelled")) {
        sizeCancelled = json["sizeCancelled"].asDouble();
    }
    if (json.isMember("sizeVoided")) {
        sizeVoided = json["sizeVoided"].asDouble();
    }
}

Json::Value Order::toJson() const {
    Json::Value json;
    if (betId != "") {
        json["betId"] = betId;
    }
    if (orderType.isValid()) {
        json["orderType"] = orderType.getValue();
    }
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (persistenceType.isValid()) {
        json["persistenceType"] = persistenceType.getValue();
    }
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (price >= 0) {
        json["price"] = price;
    }
    if (size >= 0) {
        json["size"] = size;
    }
    if (bspLiability >= 0) {
        json["bspLiability"] = bspLiability;
    }
    if (false) {
        // placedDate not implemented;
    }
    if (avgPriceMatched >= 0) {
        json["avgPriceMatched"] = avgPriceMatched;
    }
    if (sizeMatched >= 0) {
        json["sizeMatched"] = sizeMatched;
    }
    if (sizeRemaining >= 0) {
        json["sizeRemaining"] = sizeRemaining;
    }
    if (sizeLapsed >= 0) {
        json["sizeLapsed"] = sizeLapsed;
    }
    if (sizeCancelled >= 0) {
        json["sizeCancelled"] = sizeCancelled;
    }
    if (sizeVoided >= 0) {
        json["sizeVoided"] = sizeVoided;
    }
    return json;
}

bool Order::isValid() const {
    return betId != "" && orderType.isValid() && status.isValid() && persistenceType.isValid() && side.isValid() && price >= 0 && size >= 0 && bspLiability >= 0 && false;
}

const std::string& Order::getBetId() const {
    return betId;
}
void Order::setBetId(const std::string& betId) {
    this->betId = betId;
}

const OrderType& Order::getOrderType() const {
    return orderType;
}
void Order::setOrderType(const OrderType& orderType) {
    this->orderType = orderType;
}

const OrderStatus& Order::getStatus() const {
    return status;
}
void Order::setStatus(const OrderStatus& status) {
    this->status = status;
}

const PersistenceType& Order::getPersistenceType() const {
    return persistenceType;
}
void Order::setPersistenceType(const PersistenceType& persistenceType) {
    this->persistenceType = persistenceType;
}

const Side& Order::getSide() const {
    return side;
}
void Order::setSide(const Side& side) {
    this->side = side;
}

const double Order::getPrice() const {
    return price;
}
void Order::setPrice(const double price) {
    this->price = price;
}

const double Order::getSize() const {
    return size;
}
void Order::setSize(const double size) {
    this->size = size;
}

const double Order::getBspLiability() const {
    return bspLiability;
}
void Order::setBspLiability(const double bspLiability) {
    this->bspLiability = bspLiability;
}

const std::tm& Order::getPlacedDate() const {
    return placedDate;
}
void Order::setPlacedDate(const std::tm& placedDate) {
    this->placedDate = placedDate;
}

const double Order::getAvgPriceMatched() const {
    return avgPriceMatched;
}
void Order::setAvgPriceMatched(const double avgPriceMatched) {
    this->avgPriceMatched = avgPriceMatched;
}

const double Order::getSizeMatched() const {
    return sizeMatched;
}
void Order::setSizeMatched(const double sizeMatched) {
    this->sizeMatched = sizeMatched;
}

const double Order::getSizeRemaining() const {
    return sizeRemaining;
}
void Order::setSizeRemaining(const double sizeRemaining) {
    this->sizeRemaining = sizeRemaining;
}

const double Order::getSizeLapsed() const {
    return sizeLapsed;
}
void Order::setSizeLapsed(const double sizeLapsed) {
    this->sizeLapsed = sizeLapsed;
}

const double Order::getSizeCancelled() const {
    return sizeCancelled;
}
void Order::setSizeCancelled(const double sizeCancelled) {
    this->sizeCancelled = sizeCancelled;
}

const double Order::getSizeVoided() const {
    return sizeVoided;
}
void Order::setSizeVoided(const double sizeVoided) {
    this->sizeVoided = sizeVoided;
}


}



