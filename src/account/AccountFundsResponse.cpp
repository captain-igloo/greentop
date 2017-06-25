/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AccountFundsResponse.h"

namespace greentop {


AccountFundsResponse::AccountFundsResponse(const Optional<double>& availableToBetBalance,
    const Optional<double>& exposure,
    const Optional<double>& retainedCommission,
    const Optional<double>& exposureLimit,
    const Optional<double>& discountRate,
    const Optional<int32_t>& pointsBalance,
    const std::string& wallet) :
    availableToBetBalance(availableToBetBalance),
    exposure(exposure),
    retainedCommission(retainedCommission),
    exposureLimit(exposureLimit),
    discountRate(discountRate),
    pointsBalance(pointsBalance),
    wallet(wallet) {
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
            pointsBalance = json["pointsBalance"].asInt();
        }
        if (json.isMember("wallet")) {
            wallet = json["wallet"].asString();
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
    if (pointsBalance.isValid()) {
        json["pointsBalance"] = pointsBalance.toJson();
    }
    if (wallet != "") {
        json["wallet"] = wallet;
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

const Optional<int32_t>& AccountFundsResponse::getPointsBalance() const {
    return pointsBalance;
}
void AccountFundsResponse::setPointsBalance(const Optional<int32_t>& pointsBalance) {
    this->pointsBalance = pointsBalance;
}

const std::string& AccountFundsResponse::getWallet() const {
    return wallet;
}
void AccountFundsResponse::setWallet(const std::string& wallet) {
    this->wallet = wallet;
}


}



