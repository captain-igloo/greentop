/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RemoveDefaultExposureLimitForMarketGroupsResponse.h"

namespace greentop {
namespace sport {

RemoveDefaultExposureLimitForMarketGroupsResponse::RemoveDefaultExposureLimitForMarketGroupsResponse() {
}

RemoveDefaultExposureLimitForMarketGroupsResponse::RemoveDefaultExposureLimitForMarketGroupsResponse(const std::string& response) :
    response(response) {
}

void RemoveDefaultExposureLimitForMarketGroupsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value RemoveDefaultExposureLimitForMarketGroupsResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool RemoveDefaultExposureLimitForMarketGroupsResponse::isValid() const {
    return response != "";
}

const std::string& RemoveDefaultExposureLimitForMarketGroupsResponse::getResponse() const {
    return response;
}
void RemoveDefaultExposureLimitForMarketGroupsResponse::setResponse(const std::string& response) {
    this->response = response;
}


}
}
