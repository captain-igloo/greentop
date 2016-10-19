/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PlaceOrdersRequest.h"

namespace greentop {

PlaceOrdersRequest::PlaceOrdersRequest() {
}

PlaceOrdersRequest::PlaceOrdersRequest(const std::string& marketId,
    const std::vector<PlaceInstruction>& instructions,
    const std::string& customerRef) :
    marketId(marketId),
    instructions(instructions),
    customerRef(customerRef) {
}

void PlaceOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("instructions")) {
        for (unsigned i = 0; i < json["instructions"].size(); ++i) {
            PlaceInstruction instruction;
            instruction.fromJson(json["instructions"][i]);
            instructions.push_back(instruction);
        }
    }
    if (json.isMember("customerRef")) {
        customerRef = json["customerRef"].asString();
    }
}

Json::Value PlaceOrdersRequest::toJson() const {
    Json::Value json(Json::objectValue);
    json["marketId"] = marketId;
    if (instructions.size() > 0) {
        for (unsigned i = 0; i < instructions.size(); ++i) {
            json["instructions"].append(instructions[i].toJson());
        }
    }
    if (customerRef != "") {
        json["customerRef"] = customerRef;
    }
    return json;
}

bool PlaceOrdersRequest::isValid() const {
    return instructions.size() > 0;
}

const std::string& PlaceOrdersRequest::getMarketId() const {
    return marketId;
}
void PlaceOrdersRequest::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<PlaceInstruction>& PlaceOrdersRequest::getInstructions() const {
    return instructions;
}
void PlaceOrdersRequest::setInstructions(const std::vector<PlaceInstruction>& instructions) {
    this->instructions = instructions;
}

const std::string& PlaceOrdersRequest::getCustomerRef() const {
    return customerRef;
}
void PlaceOrdersRequest::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}


}



