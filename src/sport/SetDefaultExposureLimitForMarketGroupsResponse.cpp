/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/SetDefaultExposureLimitForMarketGroupsResponse.h"

namespace greentop {

SetDefaultExposureLimitForMarketGroupsResponse::SetDefaultExposureLimitForMarketGroupsResponse() {
}

SetDefaultExposureLimitForMarketGroupsResponse::SetDefaultExposureLimitForMarketGroupsResponse(const std::string& response) :
    response(response) {
}

void SetDefaultExposureLimitForMarketGroupsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value SetDefaultExposureLimitForMarketGroupsResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool SetDefaultExposureLimitForMarketGroupsResponse::isValid() const {
    return response != "";
}

const std::string& SetDefaultExposureLimitForMarketGroupsResponse::getResponse() const {
    return response;
}
void SetDefaultExposureLimitForMarketGroupsResponse::setResponse(const std::string& response) {
    this->response = response;
}


}



