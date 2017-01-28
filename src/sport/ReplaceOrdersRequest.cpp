/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ReplaceOrdersRequest.h"

namespace greentop {

ReplaceOrdersRequest::ReplaceOrdersRequest() {
}

ReplaceOrdersRequest::ReplaceOrdersRequest(const std::string& marketId,
    const std::vector<ReplaceInstruction>& instructions,
    const std::string& customerRef,
    const MarketVersion& marketVersion,
    const Optional<bool>& async) :
    marketId(marketId),
    instructions(instructions),
    customerRef(customerRef),
    marketVersion(marketVersion),
    async(async) {
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
    if (json.isMember("marketVersion")) {
        marketVersion.fromJson(json["marketVersion"]);
    }
    if (json.isMember("async")) {
        async = json["async"].asBool();
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
    if (marketVersion.isValid()) {
        json["marketVersion"] = marketVersion.toJson();
    }
    if (async.isValid()) {
        json["async"] = async.toJson();
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

const MarketVersion& ReplaceOrdersRequest::getMarketVersion() const {
    return marketVersion;
}
void ReplaceOrdersRequest::setMarketVersion(const MarketVersion& marketVersion) {
    this->marketVersion = marketVersion;
}

const Optional<bool>& ReplaceOrdersRequest::getAsync() const {
    return async;
}
void ReplaceOrdersRequest::setAsync(const Optional<bool>& async) {
    this->async = async;
}


}



