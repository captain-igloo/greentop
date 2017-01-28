/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/VendorAccessTokenInfo.h"

namespace greentop {

VendorAccessTokenInfo::VendorAccessTokenInfo() : expires_in(-1) {
}

VendorAccessTokenInfo::VendorAccessTokenInfo(const std::string& access_token,
    const TokenType& token_type,
    const int64_t expires_in,
    const std::string& refresh_token,
    const ApplicationSubscription& application_subscription) :
    access_token(access_token),
    token_type(token_type),
    expires_in(expires_in),
    refresh_token(refresh_token),
    application_subscription(application_subscription) {
}

void VendorAccessTokenInfo::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("access_token")) {
            access_token = json["access_token"].asString();
;
        }
        if (json.isMember("token_type")) {
            token_type = json["token_type"].asString();
;
        }
        if (json.isMember("expires_in")) {
            expires_in = json["expires_in"].asInt64();
;
        }
        if (json.isMember("refresh_token")) {
            refresh_token = json["refresh_token"].asString();
;
        }
        if (json.isMember("application_subscription")) {
            application_subscription.fromJson(json["application_subscription"]);
;
        }
    }
}

Json::Value VendorAccessTokenInfo::toJson() const {
    Json::Value json(Json::objectValue);
    if (access_token != "") {
        json["access_token"] = access_token;
    }
    if (token_type.isValid()) {
        json["token_type"] = token_type.getValue();
    }
    json["expires_in"] = expires_in;
    if (refresh_token != "") {
        json["refresh_token"] = refresh_token;
    }
    if (application_subscription.isValid()) {
        json["application_subscription"] = application_subscription.toJson();
    }
    return json;
}

bool VendorAccessTokenInfo::isValid() const {
    return access_token != "" && token_type.isValid() && refresh_token != "" && application_subscription.isValid();
}

const std::string& VendorAccessTokenInfo::getAccess_token() const {
    return access_token;
}
void VendorAccessTokenInfo::setAccess_token(const std::string& access_token) {
    this->access_token = access_token;
}

const TokenType& VendorAccessTokenInfo::getToken_type() const {
    return token_type;
}
void VendorAccessTokenInfo::setToken_type(const TokenType& token_type) {
    this->token_type = token_type;
}

const int64_t VendorAccessTokenInfo::getExpires_in() const {
    return expires_in;
}
void VendorAccessTokenInfo::setExpires_in(const int64_t expires_in) {
    this->expires_in = expires_in;
}

const std::string& VendorAccessTokenInfo::getRefresh_token() const {
    return refresh_token;
}
void VendorAccessTokenInfo::setRefresh_token(const std::string& refresh_token) {
    this->refresh_token = refresh_token;
}

const ApplicationSubscription& VendorAccessTokenInfo::getApplication_subscription() const {
    return application_subscription;
}
void VendorAccessTokenInfo::setApplication_subscription(const ApplicationSubscription& application_subscription) {
    this->application_subscription = application_subscription;
}


}



