/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/PriceProjection.h"

namespace greentop {

PriceProjection::PriceProjection(const std::set<PriceData>& priceData,
    const ExBestOffersOverrides& exBestOffersOverrides,
    const Optional<bool>& virtualise,
    const Optional<bool>& rolloverStakes) :
    priceData(priceData),
    exBestOffersOverrides(exBestOffersOverrides),
    virtualise(virtualise),
    rolloverStakes(rolloverStakes) {
}

void PriceProjection::fromJson(const Json::Value& json) {
    if (json.isMember("priceData")) {
        for (unsigned i = 0; i < json["priceData"].size(); ++i) {
            priceData.insert(json["priceData"][i].asString());
        };
    }
    if (json.isMember("exBestOffersOverrides")) {
        exBestOffersOverrides.fromJson(json["exBestOffersOverrides"]);
    }
    if (json.isMember("virtualise")) {
        virtualise.fromJson(json["virtualise"]);
    }
    if (json.isMember("rolloverStakes")) {
        rolloverStakes.fromJson(json["rolloverStakes"]);
    }
}

Json::Value PriceProjection::toJson() const {
    Json::Value json(Json::objectValue);
    if (priceData.size() > 0) {
        for (std::set<PriceData>::const_iterator it = priceData.begin(); it != priceData.end(); ++it) {
            PriceData priceData(*it);
            json["priceData"].append(priceData.getValue());
        };
    }
    if (exBestOffersOverrides.isValid()) {
        json["exBestOffersOverrides"] = exBestOffersOverrides.toJson();
    }
    if (virtualise.isValid()) {
        json["virtualise"] = virtualise.toJson();
    }
    if (rolloverStakes.isValid()) {
        json["rolloverStakes"] = rolloverStakes.toJson();
    }
    return json;
}

bool PriceProjection::isValid() const {
    return true;
}

const std::set<PriceData>& PriceProjection::getPriceData() const {
    return priceData;
}
void PriceProjection::setPriceData(const std::set<PriceData>& priceData) {
    this->priceData = priceData;
}

const ExBestOffersOverrides& PriceProjection::getExBestOffersOverrides() const {
    return exBestOffersOverrides;
}
void PriceProjection::setExBestOffersOverrides(const ExBestOffersOverrides& exBestOffersOverrides) {
    this->exBestOffersOverrides = exBestOffersOverrides;
}

const Optional<bool>& PriceProjection::getVirtualise() const {
    return virtualise;
}
void PriceProjection::setVirtualise(const Optional<bool>& virtualise) {
    this->virtualise = virtualise;
}

const Optional<bool>& PriceProjection::getRolloverStakes() const {
    return rolloverStakes;
}
void PriceProjection::setRolloverStakes(const Optional<bool>& rolloverStakes) {
    this->rolloverStakes = rolloverStakes;
}


}



