/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/StartingPrices.h"

namespace greentop {


StartingPrices::StartingPrices(const Optional<double>& nearPrice,
    const Optional<double>& farPrice,
    const std::vector<PriceSize>& backStakeTaken,
    const std::vector<PriceSize>& layLiabilityTaken,
    const Optional<double>& actualSP) :
    nearPrice(nearPrice),
    farPrice(farPrice),
    backStakeTaken(backStakeTaken),
    layLiabilityTaken(layLiabilityTaken),
    actualSP(actualSP) {
}

void StartingPrices::fromJson(const Json::Value& json) {
    if (json.isMember("nearPrice")) {
        nearPrice = json["nearPrice"].asDouble();
    }
    if (json.isMember("farPrice")) {
        farPrice = json["farPrice"].asDouble();
    }
    if (json.isMember("backStakeTaken")) {
        for (unsigned i = 0; i < json["backStakeTaken"].size(); ++i) {
            PriceSize priceSize;
            priceSize.fromJson(json["backStakeTaken"][i]);
            backStakeTaken.push_back(priceSize);
        }
    }
    if (json.isMember("layLiabilityTaken")) {
        for (unsigned i = 0; i < json["layLiabilityTaken"].size(); ++i) {
            PriceSize priceSize;
            priceSize.fromJson(json["layLiabilityTaken"][i]);
            layLiabilityTaken.push_back(priceSize);
        }
    }
    if (json.isMember("actualSP")) {
        actualSP = json["actualSP"].asDouble();
    }
}

Json::Value StartingPrices::toJson() const {
    Json::Value json(Json::objectValue);
    if (nearPrice.isValid()) {
        json["nearPrice"] = nearPrice.toJson();
    }
    if (farPrice.isValid()) {
        json["farPrice"] = farPrice.toJson();
    }
    if (backStakeTaken.size() > 0) {
        for (unsigned i = 0; i < backStakeTaken.size(); ++i) {
            json["backStakeTaken"].append(backStakeTaken[i].toJson());
        }
    }
    if (layLiabilityTaken.size() > 0) {
        for (unsigned i = 0; i < layLiabilityTaken.size(); ++i) {
            json["layLiabilityTaken"].append(layLiabilityTaken[i].toJson());
        }
    }
    if (actualSP.isValid()) {
        json["actualSP"] = actualSP.toJson();
    }
    return json;
}

bool StartingPrices::isValid() const {
    return true;
}

const Optional<double>& StartingPrices::getNearPrice() const {
    return nearPrice;
}
void StartingPrices::setNearPrice(const Optional<double>& nearPrice) {
    this->nearPrice = nearPrice;
}

const Optional<double>& StartingPrices::getFarPrice() const {
    return farPrice;
}
void StartingPrices::setFarPrice(const Optional<double>& farPrice) {
    this->farPrice = farPrice;
}

const std::vector<PriceSize>& StartingPrices::getBackStakeTaken() const {
    return backStakeTaken;
}
void StartingPrices::setBackStakeTaken(const std::vector<PriceSize>& backStakeTaken) {
    this->backStakeTaken = backStakeTaken;
}

const std::vector<PriceSize>& StartingPrices::getLayLiabilityTaken() const {
    return layLiabilityTaken;
}
void StartingPrices::setLayLiabilityTaken(const std::vector<PriceSize>& layLiabilityTaken) {
    this->layLiabilityTaken = layLiabilityTaken;
}

const Optional<double>& StartingPrices::getActualSP() const {
    return actualSP;
}
void StartingPrices::setActualSP(const Optional<double>& actualSP) {
    this->actualSP = actualSP;
}


}



