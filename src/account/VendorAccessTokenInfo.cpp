/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/VendorAccessTokenInfo.h"

namespace greentop {
namespace account {

VendorAccessTokenInfo::VendorAccessTokenInfo() {
}

VendorAccessTokenInfo::VendorAccessTokenInfo(const std::string& accessToken,
    const TokenType& tokenType,
    const Optional<int64_t>& expiresIn,
    const std::string& refreshToken,
    const ApplicationSubscription& applicationSubscription) :
    accessToken(accessToken),
    tokenType(tokenType),
    expiresIn(expiresIn),
    refreshToken(refreshToken),
    applicationSubscription(applicationSubscription) {
}

void VendorAccessTokenInfo::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("access_token")) {
            accessToken = json["access_token"].asString();
        }
        if (json.isMember("token_type")) {
            tokenType = json["token_type"].asString();
        }
        if (json.isMember("expires_in")) {
            expiresIn = json["expires_in"].asInt64();
        }
        if (json.isMember("refresh_token")) {
            refreshToken = json["refresh_token"].asString();
        }
        if (json.isMember("application_subscription")) {
            applicationSubscription.fromJson(json["application_subscription"]);
        }
    }
}

Json::Value VendorAccessTokenInfo::toJson() const {
    Json::Value json(Json::objectValue);
    if (accessToken != "") {
        json["access_token"] = accessToken;
    }
    if (tokenType.isValid()) {
        json["token_type"] = tokenType.getValue();
    }
    if (expiresIn.isValid()) {
        json["expires_in"] = expiresIn.toJson();
    }
    if (refreshToken != "") {
        json["refresh_token"] = refreshToken;
    }
    if (applicationSubscription.isValid()) {
        json["application_subscription"] = applicationSubscription.toJson();
    }
    return json;
}

bool VendorAccessTokenInfo::isValid() const {
    return accessToken != "" && tokenType.isValid() && expiresIn.isValid() && refreshToken != "" && applicationSubscription.isValid();
}

const std::string& VendorAccessTokenInfo::getAccessToken() const {
    return accessToken;
}
void VendorAccessTokenInfo::setAccessToken(const std::string& accessToken) {
    this->accessToken = accessToken;
}

const TokenType& VendorAccessTokenInfo::getTokenType() const {
    return tokenType;
}
void VendorAccessTokenInfo::setTokenType(const TokenType& tokenType) {
    this->tokenType = tokenType;
}

const Optional<int64_t>& VendorAccessTokenInfo::getExpiresIn() const {
    return expiresIn;
}
void VendorAccessTokenInfo::setExpiresIn(const Optional<int64_t>& expiresIn) {
    this->expiresIn = expiresIn;
}

const std::string& VendorAccessTokenInfo::getRefreshToken() const {
    return refreshToken;
}
void VendorAccessTokenInfo::setRefreshToken(const std::string& refreshToken) {
    this->refreshToken = refreshToken;
}

const ApplicationSubscription& VendorAccessTokenInfo::getApplicationSubscription() const {
    return applicationSubscription;
}
void VendorAccessTokenInfo::setApplicationSubscription(const ApplicationSubscription& applicationSubscription) {
    this->applicationSubscription = applicationSubscription;
}


}
}
