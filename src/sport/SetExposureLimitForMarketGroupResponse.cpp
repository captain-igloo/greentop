/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/SetExposureLimitForMarketGroupResponse.h"

namespace greentop {
namespace sport {

SetExposureLimitForMarketGroupResponse::SetExposureLimitForMarketGroupResponse() {
}

SetExposureLimitForMarketGroupResponse::SetExposureLimitForMarketGroupResponse(const std::string& response) :
    response(response) {
}

void SetExposureLimitForMarketGroupResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value SetExposureLimitForMarketGroupResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool SetExposureLimitForMarketGroupResponse::isValid() const {
    return response != "";
}

const std::string& SetExposureLimitForMarketGroupResponse::getResponse() const {
    return response;
}
void SetExposureLimitForMarketGroupResponse::setResponse(const std::string& response) {
    this->response = response;
}


}
}
