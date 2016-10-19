/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ReplaceOrdersRequest.h"

namespace greentop {

ReplaceOrdersRequest::ReplaceOrdersRequest() {
}

ReplaceOrdersRequest::ReplaceOrdersRequest(const std::string& marketId,
    const std::vector<ReplaceInstruction>& instructions,
    const std::string& customerRef) :
    marketId(marketId),
    instructions(instructions),
    customerRef(customerRef) {
}

void ReplaceOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("instructions")) {
        for (unsigned i = 0; i < json["instructions"].size(); ++i) {
            ReplaceInstruction instruction;
            instruction.fromJson(json["instructions"][i]);
            instructions.push_back(instruction);
        }
    }
    if (json.isMember("customerRef")) {
        customerRef = json["customerRef"].asString();
    }
}

Json::Value ReplaceOrdersRequest::toJson() const {
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

bool ReplaceOrdersRequest::isValid() const {
    return instructions.size() > 0;
}

const std::string& ReplaceOrdersRequest::getMarketId() const {
    return marketId;
}
void ReplaceOrdersRequest::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<ReplaceInstruction>& ReplaceOrdersRequest::getInstructions() const {
    return instructions;
}
void ReplaceOrdersRequest::setInstructions(const std::vector<ReplaceInstruction>& instructions) {
    this->instructions = instructions;
}

const std::string& ReplaceOrdersRequest::getCustomerRef() const {
    return customerRef;
}
void ReplaceOrdersRequest::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}


}



