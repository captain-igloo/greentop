/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UpdateOrdersRequest.h"

namespace greentop {

UpdateOrdersRequest::UpdateOrdersRequest() {
}

UpdateOrdersRequest::UpdateOrdersRequest(const std::string& marketId,
    const std::vector<UpdateInstruction>& instructions,
    const std::string& customerRef) :
    marketId(marketId),
    instructions(instructions),
    customerRef(customerRef) {
}

void UpdateOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("instructions")) {
        for (unsigned i = 0; i < json["instructions"].size(); ++i) {
            UpdateInstruction instruction;
            instruction.fromJson(json["instructions"][i]);
            instructions.push_back(instruction);
        }
    }
    if (json.isMember("customerRef")) {
        customerRef = json["customerRef"].asString();
    }
}

Json::Value UpdateOrdersRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
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

bool UpdateOrdersRequest::isValid() const {
    return marketId != "" && instructions.size() > 0;
}

const std::string& UpdateOrdersRequest::getMarketId() const {
    return marketId;
}
void UpdateOrdersRequest::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<UpdateInstruction>& UpdateOrdersRequest::getInstructions() const {
    return instructions;
}
void UpdateOrdersRequest::setInstructions(const std::vector<UpdateInstruction>& instructions) {
    this->instructions = instructions;
}

const std::string& UpdateOrdersRequest::getCustomerRef() const {
    return customerRef;
}
void UpdateOrdersRequest::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}


}



