/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AccountFundsResponse.h"

namespace greentop {

AccountFundsResponse::AccountFundsResponse(const Optional<double>& availableToBetBalance,
    const Optional<double>& exposure,
    const Optional<double>& retainedCommission,
    const Optional<double>& exposureLimit,
    const Optional<double>& discountRate,
    const uint64_t pointsBalance) :
    availableToBetBalance(availableToBetBalance),
    exposure(exposure),
    retainedCommission(retainedCommission),
    exposureLimit(exposureLimit),
    discountRate(discountRate),
    pointsBalance(pointsBalance) {
}

void AccountFundsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("availableToBetBalance")) {
            availableToBetBalance.fromJson(json["availableToBetBalance"]);
        }
        if (json.isMember("exposure")) {
            exposure.fromJson(json["exposure"]);
        }
        if (json.isMember("retainedCommission")) {
            retainedCommission.fromJson(json["retainedCommission"]);
        }
        if (json.isMember("exposureLimit")) {
            exposureLimit.fromJson(json["exposureLimit"]);
        }
        if (json.isMember("discountRate")) {
            discountRate.fromJson(json["discountRate"]);
        }
        if (json.isMember("pointsBalance")) {
            pointsBalance = json["pointsBalance"].asUInt64();
        }
    }
}

Json::Value AccountFundsResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (availableToBetBalance.isValid()) {
        json["availableToBetBalance"] = availableToBetBalance.toJson();
    }
    if (exposure.isValid()) {
        json["exposure"] = exposure.toJson();
    }
    if (retainedCommission.isValid()) {
        json["retainedCommission"] = retainedCommission.toJson();
    }
    if (exposureLimit.isValid()) {
        json["exposureLimit"] = exposureLimit.toJson();
    }
    if (discountRate.isValid()) {
        json["discountRate"] = discountRate.toJson();
    }
    if (pointsBalance > 0) {
        json["pointsBalance"] = pointsBalance;
    }
    return json;
}

bool AccountFundsResponse::isValid() const {
    return true;
}

const Optional<double>& AccountFundsResponse::getAvailableToBetBalance() const {
    return availableToBetBalance;
}
void AccountFundsResponse::setAvailableToBetBalance(const Optional<double>& availableToBetBalance) {
    this->availableToBetBalance = availableToBetBalance;
}

const Optional<double>& AccountFundsResponse::getExposure() const {
    return exposure;
}
void AccountFundsResponse::setExposure(const Optional<double>& exposure) {
    this->exposure = exposure;
}

const Optional<double>& AccountFundsResponse::getRetainedCommission() const {
    return retainedCommission;
}
void AccountFundsResponse::setRetainedCommission(const Optional<double>& retainedCommission) {
    this->retainedCommission = retainedCommission;
}

const Optional<double>& AccountFundsResponse::getExposureLimit() const {
    return exposureLimit;
}
void AccountFundsResponse::setExposureLimit(const Optional<double>& exposureLimit) {
    this->exposureLimit = exposureLimit;
}

const Optional<double>& AccountFundsResponse::getDiscountRate() const {
    return discountRate;
}
void AccountFundsResponse::setDiscountRate(const Optional<double>& discountRate) {
    this->discountRate = discountRate;
}

const uint64_t AccountFundsResponse::getPointsBalance() const {
    return pointsBalance;
}
void AccountFundsResponse::setPointsBalance(const uint64_t pointsBalance) {
    this->pointsBalance = pointsBalance;
}


}



