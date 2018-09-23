/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UnblockMarketGroupResponse.h"

namespace greentop {

UnblockMarketGroupResponse::UnblockMarketGroupResponse() {
}

UnblockMarketGroupResponse::UnblockMarketGroupResponse(const std::string& response) :
    response(response) {
}

void UnblockMarketGroupResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        response = json.asString();
    }
}

Json::Value UnblockMarketGroupResponse::toJson() const {
    Json::Value json(Json::stringValue);
    if (response != "") {
        json = response;
    }
    return json;
}

bool UnblockMarketGroupResponse::isValid() const {
    return response != "";
}

const std::string& UnblockMarketGroupResponse::getResponse() const {
    return response;
}
void UnblockMarketGroupResponse::setResponse(const std::string& response) {
    this->response = response;
}


}



