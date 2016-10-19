/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ExBestOffersOverrides.h"

namespace greentop {


ExBestOffersOverrides::ExBestOffersOverrides(const Optional<int32_t>& bestPricesDepth,
    const RollupModel& rollupModel,
    const Optional<int32_t>& rollupLimit,
    const Optional<double>& rollupLiabilityThreshold,
    const Optional<int32_t>& rollupLiabilityFactor) :
    bestPricesDepth(bestPricesDepth),
    rollupModel(rollupModel),
    rollupLimit(rollupLimit),
    rollupLiabilityThreshold(rollupLiabilityThreshold),
    rollupLiabilityFactor(rollupLiabilityFactor) {
}

void ExBestOffersOverrides::fromJson(const Json::Value& json) {
    if (json.isMember("bestPricesDepth")) {
        bestPricesDepth = json["bestPricesDepth"].asInt();
    }
    if (json.isMember("rollupModel")) {
        rollupModel = json["rollupModel"].asString();
    }
    if (json.isMember("rollupLimit")) {
        rollupLimit = json["rollupLimit"].asInt();
    }
    if (json.isMember("rollupLiabilityThreshold")) {
        rollupLiabilityThreshold = json["rollupLiabilityThreshold"].asDouble();
    }
    if (json.isMember("rollupLiabilityFactor")) {
        rollupLiabilityFactor = json["rollupLiabilityFactor"].asInt();
    }
}

Json::Value ExBestOffersOverrides::toJson() const {
    Json::Value json(Json::objectValue);
    if (bestPricesDepth.isValid()) {
        json["bestPricesDepth"] = bestPricesDepth.toJson();
    }
    if (rollupModel.isValid()) {
        json["rollupModel"] = rollupModel.getValue();
    }
    if (rollupLimit.isValid()) {
        json["rollupLimit"] = rollupLimit.toJson();
    }
    if (rollupLiabilityThreshold.isValid()) {
        json["rollupLiabilityThreshold"] = rollupLiabilityThreshold.toJson();
    }
    if (rollupLiabilityFactor.isValid()) {
        json["rollupLiabilityFactor"] = rollupLiabilityFactor.toJson();
    }
    return json;
}

bool ExBestOffersOverrides::isValid() const {
    return true;
}

const Optional<int32_t>& ExBestOffersOverrides::getBestPricesDepth() const {
    return bestPricesDepth;
}
void ExBestOffersOverrides::setBestPricesDepth(const Optional<int32_t>& bestPricesDepth) {
    this->bestPricesDepth = bestPricesDepth;
}

const RollupModel& ExBestOffersOverrides::getRollupModel() const {
    return rollupModel;
}
void ExBestOffersOverrides::setRollupModel(const RollupModel& rollupModel) {
    this->rollupModel = rollupModel;
}

const Optional<int32_t>& ExBestOffersOverrides::getRollupLimit() const {
    return rollupLimit;
}
void ExBestOffersOverrides::setRollupLimit(const Optional<int32_t>& rollupLimit) {
    this->rollupLimit = rollupLimit;
}

const Optional<double>& ExBestOffersOverrides::getRollupLiabilityThreshold() const {
    return rollupLiabilityThreshold;
}
void ExBestOffersOverrides::setRollupLiabilityThreshold(const Optional<double>& rollupLiabilityThreshold) {
    this->rollupLiabilityThreshold = rollupLiabilityThreshold;
}

const Optional<int32_t>& ExBestOffersOverrides::getRollupLiabilityFactor() const {
    return rollupLiabilityFactor;
}
void ExBestOffersOverrides::setRollupLiabilityFactor(const Optional<int32_t>& rollupLiabilityFactor) {
    this->rollupLiabilityFactor = rollupLiabilityFactor;
}


}



