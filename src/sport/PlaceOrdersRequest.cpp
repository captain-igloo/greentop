/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/PlaceOrdersRequest.h"

namespace greentop {

PlaceOrdersRequest::PlaceOrdersRequest() {
}

PlaceOrdersRequest::PlaceOrdersRequest(const std::string& marketId,
    const std::vector<PlaceInstruction>& instructions,
    const std::string& customerRef,
    const MarketVersion& marketVersion,
    const std::string& customerStrategyRef,
    const Optional<bool>& async) :
    marketId(marketId),
    instructions(instructions),
    customerRef(customerRef),
    marketVersion(marketVersion),
    customerStrategyRef(customerStrategyRef),
    async(async) {
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
    if (json.isMember("marketVersion")) {
        marketVersion.fromJson(json["marketVersion"]);
    }
    if (json.isMember("customerStrategyRef")) {
        customerStrategyRef = json["customerStrategyRef"].asString();
    }
    if (json.isMember("async")) {
        async = json["async"].asBool();
    }
}

Json::Value PlaceOrdersRequest::toJson() const {
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
    if (marketVersion.isValid()) {
        json["marketVersion"] = marketVersion.toJson();
    }
    if (customerStrategyRef != "") {
        json["customerStrategyRef"] = customerStrategyRef;
    }
    if (async.isValid()) {
        json["async"] = async.toJson();
    }
    return json;
}

bool PlaceOrdersRequest::isValid() const {
    return marketId != "" && instructions.size() > 0;
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

const MarketVersion& PlaceOrdersRequest::getMarketVersion() const {
    return marketVersion;
}
void PlaceOrdersRequest::setMarketVersion(const MarketVersion& marketVersion) {
    this->marketVersion = marketVersion;
}

const std::string& PlaceOrdersRequest::getCustomerStrategyRef() const {
    return customerStrategyRef;
}
void PlaceOrdersRequest::setCustomerStrategyRef(const std::string& customerStrategyRef) {
    this->customerStrategyRef = customerStrategyRef;
}

const Optional<bool>& PlaceOrdersRequest::getAsync() const {
    return async;
}
void PlaceOrdersRequest::setAsync(const Optional<bool>& async) {
    this->async = async;
}


}



