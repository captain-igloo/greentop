/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/Match.h"

namespace greentop {

Match::Match(const std::string& betId,
    const std::string& matchId,
    const Side& side,
    const double price,
    const double size,
    const std::tm& matchDate) :
    betId(betId),
    matchId(matchId),
    side(side),
    price(price),
    size(size),
    matchDate(matchDate) {
}

void Match::fromJson(const Json::Value& json) {
    if (json.isMember("betId")) {
        betId = json["betId"].asString();
    }
    if (json.isMember("matchId")) {
        matchId = json["matchId"].asString();
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
    if (json.isMember("matchDate")) {
        strptime(json["matchDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &matchDate);
    }
}

Json::Value Match::toJson() const {
    Json::Value json(Json::objectValue);
    if (betId != "") {
        json["betId"] = betId;
    }
    if (matchId != "") {
        json["matchId"] = matchId;
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
    if (matchDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &matchDate);
        json["matchDate"] = std::string(buffer);
    }
    return json;
}

bool Match::isValid() const {
    return side.isValid() && price >= 0 && size >= 0;
}

const std::string& Match::getBetId() const {
    return betId;
}
void Match::setBetId(const std::string& betId) {
    this->betId = betId;
}

const std::string& Match::getMatchId() const {
    return matchId;
}
void Match::setMatchId(const std::string& matchId) {
    this->matchId = matchId;
}

const Side& Match::getSide() const {
    return side;
}
void Match::setSide(const Side& side) {
    this->side = side;
}

const double Match::getPrice() const {
    return price;
}
void Match::setPrice(const double price) {
    this->price = price;
}

const double Match::getSize() const {
    return size;
}
void Match::setSize(const double size) {
    this->size = size;
}

const std::tm& Match::getMatchDate() const {
    return matchDate;
}
void Match::setMatchDate(const std::tm& matchDate) {
    this->matchDate = matchDate;
}


}



