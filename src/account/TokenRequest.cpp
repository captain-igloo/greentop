/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/TokenRequest.h"

namespace greentop {
namespace account {

TokenRequest::TokenRequest() {
}

TokenRequest::TokenRequest(const std::string& client_id,
    const GrantType& grant_type,
    const std::string& code,
    const std::string& client_secret,
    const std::string& refresh_token) :
    client_id(client_id),
    grant_type(grant_type),
    code(code),
    client_secret(client_secret),
    refresh_token(refresh_token) {
}

void TokenRequest::fromJson(const Json::Value& json) {
    if (json.isMember("client_id")) {
        client_id = json["client_id"].asString();
    }
    if (json.isMember("grant_type")) {
        grant_type = json["grant_type"].asString();
    }
    if (json.isMember("code")) {
        code = json["code"].asString();
    }
    if (json.isMember("client_secret")) {
        client_secret = json["client_secret"].asString();
    }
    if (json.isMember("refresh_token")) {
        refresh_token = json["refresh_token"].asString();
    }
}

Json::Value TokenRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (client_id != "") {
        json["client_id"] = client_id;
    }
    if (grant_type.isValid()) {
        json["grant_type"] = grant_type.getValue();
    }
    if (code != "") {
        json["code"] = code;
    }
    if (client_secret != "") {
        json["client_secret"] = client_secret;
    }
    if (refresh_token != "") {
        json["refresh_token"] = refresh_token;
    }
    return json;
}

bool TokenRequest::isValid() const {
    return client_id != "" && grant_type.isValid() && client_secret != "";
}

const std::string& TokenRequest::getClient_id() const {
    return client_id;
}
void TokenRequest::setClient_id(const std::string& client_id) {
    this->client_id = client_id;
}

const GrantType& TokenRequest::getGrant_type() const {
    return grant_type;
}
void TokenRequest::setGrant_type(const GrantType& grant_type) {
    this->grant_type = grant_type;
}

const std::string& TokenRequest::getCode() const {
    return code;
}
void TokenRequest::setCode(const std::string& code) {
    this->code = code;
}

const std::string& TokenRequest::getClient_secret() const {
    return client_secret;
}
void TokenRequest::setClient_secret(const std::string& client_secret) {
    this->client_secret = client_secret;
}

const std::string& TokenRequest::getRefresh_token() const {
    return refresh_token;
}
void TokenRequest::setRefresh_token(const std::string& refresh_token) {
    this->refresh_token = refresh_token;
}


}
}
