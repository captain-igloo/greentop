/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/RemoveExposureLimitForMarketGroupResponse.h"

namespace greentop {
namespace sport {

RemoveExposureLimitForMarketGroupResponse::RemoveExposureLimitForMarketGroupResponse() {
}

RemoveExposureLimitForMarketGroupResponse::RemoveExposureLimitForMarketGroupResponse(const std::string& response) :
    response(response) {
}

void RemoveExposureLimitForMarketGroupResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value RemoveExposureLimitForMarketGroupResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool RemoveExposureLimitForMarketGroupResponse::isValid() const {
    return response != "";
}

const std::string& RemoveExposureLimitForMarketGroupResponse::getResponse() const {
    return response;
}
void RemoveExposureLimitForMarketGroupResponse::setResponse(const std::string& response) {
    this->response = response;
}


}
}
