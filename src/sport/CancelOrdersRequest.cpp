/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/CancelOrdersRequest.h"

namespace greentop {


CancelOrdersRequest::CancelOrdersRequest(const std::string& marketId,
    const std::vector<CancelInstruction>& instructions,
    const std::string& customerRef) :
    marketId(marketId),
    instructions(instructions),
    customerRef(customerRef) {
}

void CancelOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("instructions")) {
        for (unsigned i = 0; i < json["instructions"].size(); ++i) {
            CancelInstruction instruction;
            instruction.fromJson(json["instructions"][i]);
            instructions.push_back(instruction);
        }
    }
    if (json.isMember("customerRef")) {
        customerRef = json["customerRef"].asString();
    }
}

Json::Value CancelOrdersRequest::toJson() const {
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

bool CancelOrdersRequest::isValid() const {
    return true;
}

const std::string& CancelOrdersRequest::getMarketId() const {
    return marketId;
}
void CancelOrdersRequest::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<CancelInstruction>& CancelOrdersRequest::getInstructions() const {
    return instructions;
}
void CancelOrdersRequest::setInstructions(const std::vector<CancelInstruction>& instructions) {
    this->instructions = instructions;
}

const std::string& CancelOrdersRequest::getCustomerRef() const {
    return customerRef;
}
void CancelOrdersRequest::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}


}



