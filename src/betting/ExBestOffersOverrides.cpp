/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ExBestOffersOverrides.h"

namespace greentop {

ExBestOffersOverrides::ExBestOffersOverrides(const int bestPricesDepth,
    const RollupModel& rollupModel,
    const int rollupLimit,
    const Optional<double>& rollupLiabilityThreshold,
    const int rollupLiabiityFactor) :
    bestPricesDepth(bestPricesDepth),
    rollupModel(rollupModel),
    rollupLimit(rollupLimit),
    rollupLiabilityThreshold(rollupLiabilityThreshold),
    rollupLiabiityFactor(rollupLiabiityFactor) {
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
        rollupLiabilityThreshold.fromJson(json["rollupLiabilityThreshold"]);
    }
    if (json.isMember("rollupLiabiityFactor")) {
        rollupLiabiityFactor = json["rollupLiabiityFactor"].asInt();
    }
}

Json::Value ExBestOffersOverrides::toJson() const {
    Json::Value json(Json::objectValue);
    if (bestPricesDepth >= 0) {
        json["bestPricesDepth"] = bestPricesDepth;
    }
    if (rollupModel.isValid()) {
        json["rollupModel"] = rollupModel.getValue();
    }
    if (rollupLimit >= 0) {
        json["rollupLimit"] = rollupLimit;
    }
    if (rollupLiabilityThreshold.isValid()) {
        json["rollupLiabilityThreshold"] = rollupLiabilityThreshold.toJson();
    }
    if (rollupLiabiityFactor >= 0) {
        json["rollupLiabiityFactor"] = rollupLiabiityFactor;
    }
    return json;
}

bool ExBestOffersOverrides::isValid() const {
    return true;
}

const int ExBestOffersOverrides::getBestPricesDepth() const {
    return bestPricesDepth;
}
void ExBestOffersOverrides::setBestPricesDepth(const int bestPricesDepth) {
    this->bestPricesDepth = bestPricesDepth;
}

const RollupModel& ExBestOffersOverrides::getRollupModel() const {
    return rollupModel;
}
void ExBestOffersOverrides::setRollupModel(const RollupModel& rollupModel) {
    this->rollupModel = rollupModel;
}

const int ExBestOffersOverrides::getRollupLimit() const {
    return rollupLimit;
}
void ExBestOffersOverrides::setRollupLimit(const int rollupLimit) {
    this->rollupLimit = rollupLimit;
}

const Optional<double>& ExBestOffersOverrides::getRollupLiabilityThreshold() const {
    return rollupLiabilityThreshold;
}
void ExBestOffersOverrides::setRollupLiabilityThreshold(const Optional<double>& rollupLiabilityThreshold) {
    this->rollupLiabilityThreshold = rollupLiabilityThreshold;
}

const int ExBestOffersOverrides::getRollupLiabiityFactor() const {
    return rollupLiabiityFactor;
}
void ExBestOffersOverrides::setRollupLiabiityFactor(const int rollupLiabiityFactor) {
    this->rollupLiabiityFactor = rollupLiabiityFactor;
}


}



