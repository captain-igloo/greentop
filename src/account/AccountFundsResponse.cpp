/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AccountFundsResponse.h"

namespace greentop {

AccountFundsResponse::AccountFundsResponse(const double availableToBetBalance,
    const double exposure,
    const double retainedCommission,
    const double exposureLimit,
    const double discountRate,
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
            availableToBetBalance = json["availableToBetBalance"].asDouble();
        }
        if (json.isMember("exposure")) {
            exposure = json["exposure"].asDouble();
        }
        if (json.isMember("retainedCommission")) {
            retainedCommission = json["retainedCommission"].asDouble();
        }
        if (json.isMember("exposureLimit")) {
            exposureLimit = json["exposureLimit"].asDouble();
        }
        if (json.isMember("discountRate")) {
            discountRate = json["discountRate"].asDouble();
        }
        if (json.isMember("pointsBalance")) {
            pointsBalance = json["pointsBalance"].asUInt();
        }
    }
}

Json::Value AccountFundsResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (availableToBetBalance >= 0) {
        json["availableToBetBalance"] = availableToBetBalance;
    }
    if (exposure >= 0) {
        json["exposure"] = exposure;
    }
    if (retainedCommission >= 0) {
        json["retainedCommission"] = retainedCommission;
    }
    if (exposureLimit >= 0) {
        json["exposureLimit"] = exposureLimit;
    }
    if (discountRate >= 0) {
        json["discountRate"] = discountRate;
    }
    if (pointsBalance > 0) {
        json["pointsBalance"] = pointsBalance;
    }
    return json;
}

bool AccountFundsResponse::isValid() const {
    return true;
}

const double AccountFundsResponse::getAvailableToBetBalance() const {
    return availableToBetBalance;
}
void AccountFundsResponse::setAvailableToBetBalance(const double availableToBetBalance) {
    this->availableToBetBalance = availableToBetBalance;
}

const double AccountFundsResponse::getExposure() const {
    return exposure;
}
void AccountFundsResponse::setExposure(const double exposure) {
    this->exposure = exposure;
}

const double AccountFundsResponse::getRetainedCommission() const {
    return retainedCommission;
}
void AccountFundsResponse::setRetainedCommission(const double retainedCommission) {
    this->retainedCommission = retainedCommission;
}

const double AccountFundsResponse::getExposureLimit() const {
    return exposureLimit;
}
void AccountFundsResponse::setExposureLimit(const double exposureLimit) {
    this->exposureLimit = exposureLimit;
}

const double AccountFundsResponse::getDiscountRate() const {
    return discountRate;
}
void AccountFundsResponse::setDiscountRate(const double discountRate) {
    this->discountRate = discountRate;
}

const uint64_t AccountFundsResponse::getPointsBalance() const {
    return pointsBalance;
}
void AccountFundsResponse::setPointsBalance(const uint64_t pointsBalance) {
    this->pointsBalance = pointsBalance;
}


}



