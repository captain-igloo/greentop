/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/TokenRequest.h"

namespace greentop {
namespace account {

TokenRequest::TokenRequest() {
}

TokenRequest::TokenRequest(const std::string& clientId,
    const GrantType& grantType,
    const std::string& code,
    const std::string& clientSecret,
    const std::string& refreshToken) :
    clientId(clientId),
    grantType(grantType),
    code(code),
    clientSecret(clientSecret),
    refreshToken(refreshToken) {
}

void TokenRequest::fromJson(const Json::Value& json) {
    if (json.isMember("client_id")) {
        clientId = json["client_id"].asString();
    }
    if (json.isMember("grant_type")) {
        grantType = json["grant_type"].asString();
    }
    if (json.isMember("code")) {
        code = json["code"].asString();
    }
    if (json.isMember("client_secret")) {
        clientSecret = json["client_secret"].asString();
    }
    if (json.isMember("refresh_token")) {
        refreshToken = json["refresh_token"].asString();
    }
}

Json::Value TokenRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (clientId != "") {
        json["client_id"] = clientId;
    }
    if (grantType.isValid()) {
        json["grant_type"] = grantType.getValue();
    }
    if (code != "") {
        json["code"] = code;
    }
    if (clientSecret != "") {
        json["client_secret"] = clientSecret;
    }
    if (refreshToken != "") {
        json["refresh_token"] = refreshToken;
    }
    return json;
}

bool TokenRequest::isValid() const {
    return clientId != "" && grantType.isValid() && clientSecret != "";
}

const std::string& TokenRequest::getClientId() const {
    return clientId;
}
void TokenRequest::setClientId(const std::string& clientId) {
    this->clientId = clientId;
}

const GrantType& TokenRequest::getGrantType() const {
    return grantType;
}
void TokenRequest::setGrantType(const GrantType& grantType) {
    this->grantType = grantType;
}

const std::string& TokenRequest::getCode() const {
    return code;
}
void TokenRequest::setCode(const std::string& code) {
    this->code = code;
}

const std::string& TokenRequest::getClientSecret() const {
    return clientSecret;
}
void TokenRequest::setClientSecret(const std::string& clientSecret) {
    this->clientSecret = clientSecret;
}

const std::string& TokenRequest::getRefreshToken() const {
    return refreshToken;
}
void TokenRequest::setRefreshToken(const std::string& refreshToken) {
    this->refreshToken = refreshToken;
}


}
}
