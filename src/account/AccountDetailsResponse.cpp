/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AccountDetailsResponse.h"

namespace greentop {

AccountDetailsResponse::AccountDetailsResponse(const std::string& currencyCode,
    const std::string& firstName,
    const std::string& lastName,
    const std::string& localeCode,
    const std::string& region,
    const std::string& timezone,
    const double discountRate,
    const uint64_t pointsBalance) :
    currencyCode(currencyCode),
    firstName(firstName),
    lastName(lastName),
    localeCode(localeCode),
    region(region),
    timezone(timezone),
    discountRate(discountRate),
    pointsBalance(pointsBalance) {
}

void AccountDetailsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("currencyCode")) {
            currencyCode = json["currencyCode"].asString();
        }
        if (json.isMember("firstName")) {
            firstName = json["firstName"].asString();
        }
        if (json.isMember("lastName")) {
            lastName = json["lastName"].asString();
        }
        if (json.isMember("localeCode")) {
            localeCode = json["localeCode"].asString();
        }
        if (json.isMember("region")) {
            region = json["region"].asString();
        }
        if (json.isMember("timezone")) {
            timezone = json["timezone"].asString();
        }
        if (json.isMember("discountRate")) {
            discountRate = json["discountRate"].asDouble();
        }
        if (json.isMember("pointsBalance")) {
            pointsBalance = json["pointsBalance"].asUInt64();
        }
    }
}

Json::Value AccountDetailsResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (currencyCode != "") {
        json["currencyCode"] = currencyCode;
    }
    if (firstName != "") {
        json["firstName"] = firstName;
    }
    if (lastName != "") {
        json["lastName"] = lastName;
    }
    if (localeCode != "") {
        json["localeCode"] = localeCode;
    }
    if (region != "") {
        json["region"] = region;
    }
    if (timezone != "") {
        json["timezone"] = timezone;
    }
    if (discountRate >= 0) {
        json["discountRate"] = discountRate;
    }
    if (pointsBalance > 0) {
        json["pointsBalance"] = pointsBalance;
    }
    return json;
}

bool AccountDetailsResponse::isValid() const {
    return true;
}

const std::string& AccountDetailsResponse::getCurrencyCode() const {
    return currencyCode;
}
void AccountDetailsResponse::setCurrencyCode(const std::string& currencyCode) {
    this->currencyCode = currencyCode;
}

const std::string& AccountDetailsResponse::getFirstName() const {
    return firstName;
}
void AccountDetailsResponse::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

const std::string& AccountDetailsResponse::getLastName() const {
    return lastName;
}
void AccountDetailsResponse::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

const std::string& AccountDetailsResponse::getLocaleCode() const {
    return localeCode;
}
void AccountDetailsResponse::setLocaleCode(const std::string& localeCode) {
    this->localeCode = localeCode;
}

const std::string& AccountDetailsResponse::getRegion() const {
    return region;
}
void AccountDetailsResponse::setRegion(const std::string& region) {
    this->region = region;
}

const std::string& AccountDetailsResponse::getTimezone() const {
    return timezone;
}
void AccountDetailsResponse::setTimezone(const std::string& timezone) {
    this->timezone = timezone;
}

const double AccountDetailsResponse::getDiscountRate() const {
    return discountRate;
}
void AccountDetailsResponse::setDiscountRate(const double discountRate) {
    this->discountRate = discountRate;
}

const uint64_t AccountDetailsResponse::getPointsBalance() const {
    return pointsBalance;
}
void AccountDetailsResponse::setPointsBalance(const uint64_t pointsBalance) {
    this->pointsBalance = pointsBalance;
}


}



