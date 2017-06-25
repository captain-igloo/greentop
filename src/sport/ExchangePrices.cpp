/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ExchangePrices.h"

namespace greentop {


ExchangePrices::ExchangePrices(const std::vector<PriceSize>& availableToBack,
    const std::vector<PriceSize>& availableToLay,
    const std::vector<PriceSize>& tradedVolume) :
    availableToBack(availableToBack),
    availableToLay(availableToLay),
    tradedVolume(tradedVolume) {
}

void ExchangePrices::fromJson(const Json::Value& json) {
    if (json.isMember("availableToBack")) {
        for (unsigned i = 0; i < json["availableToBack"].size(); ++i) {
            PriceSize priceSize;
            priceSize.fromJson(json["availableToBack"][i]);
            availableToBack.push_back(priceSize);
        }
    }
    if (json.isMember("availableToLay")) {
        for (unsigned i = 0; i < json["availableToLay"].size(); ++i) {
            PriceSize priceSize;
            priceSize.fromJson(json["availableToLay"][i]);
            availableToLay.push_back(priceSize);
        }
    }
    if (json.isMember("tradedVolume")) {
        for (unsigned i = 0; i < json["tradedVolume"].size(); ++i) {
            PriceSize priceSize;
            priceSize.fromJson(json["tradedVolume"][i]);
            tradedVolume.push_back(priceSize);
        }
    }
}

Json::Value ExchangePrices::toJson() const {
    Json::Value json(Json::objectValue);
    if (availableToBack.size() > 0) {
        for (unsigned i = 0; i < availableToBack.size(); ++i) {
            json["availableToBack"].append(availableToBack[i].toJson());
        }
    }
    if (availableToLay.size() > 0) {
        for (unsigned i = 0; i < availableToLay.size(); ++i) {
            json["availableToLay"].append(availableToLay[i].toJson());
        }
    }
    if (tradedVolume.size() > 0) {
        for (unsigned i = 0; i < tradedVolume.size(); ++i) {
            json["tradedVolume"].append(tradedVolume[i].toJson());
        }
    }
    return json;
}

bool ExchangePrices::isValid() const {
    return true;
}

const std::vector<PriceSize>& ExchangePrices::getAvailableToBack() const {
    return availableToBack;
}
void ExchangePrices::setAvailableToBack(const std::vector<PriceSize>& availableToBack) {
    this->availableToBack = availableToBack;
}

const std::vector<PriceSize>& ExchangePrices::getAvailableToLay() const {
    return availableToLay;
}
void ExchangePrices::setAvailableToLay(const std::vector<PriceSize>& availableToLay) {
    this->availableToLay = availableToLay;
}

const std::vector<PriceSize>& ExchangePrices::getTradedVolume() const {
    return tradedVolume;
}
void ExchangePrices::setTradedVolume(const std::vector<PriceSize>& tradedVolume) {
    this->tradedVolume = tradedVolume;
}


}



