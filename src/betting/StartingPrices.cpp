#include "greentop/betting/StartingPrices.h"

namespace greentop {

StartingPrices::StartingPrices(const double nearPrice,
    const double farPrice,
    const std::vector<PriceSize>& backStakeTaken,
    const std::vector<PriceSize>& layLiabilityTaken,
    const double actualSP) :
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
            };
    }
    if (json.isMember("layLiabilityTaken")) {
        for (unsigned i = 0; i < json["layLiabilityTaken"].size(); ++i) {
                PriceSize priceSize;
                priceSize.fromJson(json["layLiabilityTaken"][i]);
                layLiabilityTaken.push_back(priceSize);
            };
    }
    if (json.isMember("actualSP")) {
        actualSP = json["actualSP"].asDouble();
    }
}

Json::Value StartingPrices::toJson() const {
    Json::Value json;
    if (nearPrice >= 0) {
        json["nearPrice"] = nearPrice;
    }
    if (farPrice >= 0) {
        json["farPrice"] = farPrice;
    }
    if (backStakeTaken.size() > 0) {
        for (unsigned i = 0; i < backStakeTaken.size(); ++i) {
            json["backStakeTaken"].append(backStakeTaken[i].toJson());
        };
    }
    if (layLiabilityTaken.size() > 0) {
        for (unsigned i = 0; i < layLiabilityTaken.size(); ++i) {
            json["layLiabilityTaken"].append(layLiabilityTaken[i].toJson());
        };
    }
    if (actualSP >= 0) {
        json["actualSP"] = actualSP;
    }
    return json;
}

bool StartingPrices::isValid() const {
    return true;
}

const double StartingPrices::getNearPrice() const {
    return nearPrice;
}
void StartingPrices::setNearPrice(const double nearPrice) {
    this->nearPrice = nearPrice;
}

const double StartingPrices::getFarPrice() const {
    return farPrice;
}
void StartingPrices::setFarPrice(const double farPrice) {
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

const double StartingPrices::getActualSP() const {
    return actualSP;
}
void StartingPrices::setActualSP(const double actualSP) {
    this->actualSP = actualSP;
}


}



