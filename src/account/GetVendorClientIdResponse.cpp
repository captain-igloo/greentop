/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetVendorClientIdResponse.h"

namespace greentop {
namespace account {

GetVendorClientIdResponse::GetVendorClientIdResponse() {
}

GetVendorClientIdResponse::GetVendorClientIdResponse(const std::string& response) :
    response(response) {
}

void GetVendorClientIdResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value GetVendorClientIdResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool GetVendorClientIdResponse::isValid() const {
    return response != "";
}

const std::string& GetVendorClientIdResponse::getResponse() const {
    return response;
}
void GetVendorClientIdResponse::setResponse(const std::string& response) {
    this->response = response;
}


}
}
