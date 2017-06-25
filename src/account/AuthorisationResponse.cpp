/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/AuthorisationResponse.h"

namespace greentop {

AuthorisationResponse::AuthorisationResponse() {
}

AuthorisationResponse::AuthorisationResponse(const std::string& authorisationCode,
    const std::string& redirectUrl) :
    authorisationCode(authorisationCode),
    redirectUrl(redirectUrl) {
}

void AuthorisationResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("authorisationCode")) {
            authorisationCode = json["authorisationCode"].asString();
        }
        if (json.isMember("redirectUrl")) {
            redirectUrl = json["redirectUrl"].asString();
        }
    }
}

Json::Value AuthorisationResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (authorisationCode != "") {
        json["authorisationCode"] = authorisationCode;
    }
    if (redirectUrl != "") {
        json["redirectUrl"] = redirectUrl;
    }
    return json;
}

bool AuthorisationResponse::isValid() const {
    return authorisationCode != "" && redirectUrl != "";
}

const std::string& AuthorisationResponse::getAuthorisationCode() const {
    return authorisationCode;
}
void AuthorisationResponse::setAuthorisationCode(const std::string& authorisationCode) {
    this->authorisationCode = authorisationCode;
}

const std::string& AuthorisationResponse::getRedirectUrl() const {
    return redirectUrl;
}
void AuthorisationResponse::setRedirectUrl(const std::string& redirectUrl) {
    this->redirectUrl = redirectUrl;
}


}



