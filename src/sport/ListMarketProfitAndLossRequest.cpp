/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketProfitAndLossRequest.h"

namespace greentop {
namespace sport {

ListMarketProfitAndLossRequest::ListMarketProfitAndLossRequest() {
}

ListMarketProfitAndLossRequest::ListMarketProfitAndLossRequest(const std::set<std::string>& marketIds,
    const Optional<bool>& includeSettledBets,
    const Optional<bool>& includeBspBets,
    const Optional<bool>& netOfCommission) :
    marketIds(marketIds),
    includeSettledBets(includeSettledBets),
    includeBspBets(includeBspBets),
    netOfCommission(netOfCommission) {
}

void ListMarketProfitAndLossRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        }
    }
    if (json.isMember("includeSettledBets")) {
        includeSettledBets = json["includeSettledBets"].asBool();
    }
    if (json.isMember("includeBspBets")) {
        includeBspBets = json["includeBspBets"].asBool();
    }
    if (json.isMember("netOfCommission")) {
        netOfCommission = json["netOfCommission"].asBool();
    }
}

Json::Value ListMarketProfitAndLossRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        }
    }
    if (includeSettledBets.isValid()) {
        json["includeSettledBets"] = includeSettledBets.toJson();
    }
    if (includeBspBets.isValid()) {
        json["includeBspBets"] = includeBspBets.toJson();
    }
    if (netOfCommission.isValid()) {
        json["netOfCommission"] = netOfCommission.toJson();
    }
    return json;
}

bool ListMarketProfitAndLossRequest::isValid() const {
    return marketIds.size() > 0;
}

const std::set<std::string>& ListMarketProfitAndLossRequest::getMarketIds() const {
    return marketIds;
}
void ListMarketProfitAndLossRequest::setMarketIds(const std::set<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const Optional<bool>& ListMarketProfitAndLossRequest::getIncludeSettledBets() const {
    return includeSettledBets;
}
void ListMarketProfitAndLossRequest::setIncludeSettledBets(const Optional<bool>& includeSettledBets) {
    this->includeSettledBets = includeSettledBets;
}

const Optional<bool>& ListMarketProfitAndLossRequest::getIncludeBspBets() const {
    return includeBspBets;
}
void ListMarketProfitAndLossRequest::setIncludeBspBets(const Optional<bool>& includeBspBets) {
    this->includeBspBets = includeBspBets;
}

const Optional<bool>& ListMarketProfitAndLossRequest::getNetOfCommission() const {
    return netOfCommission;
}
void ListMarketProfitAndLossRequest::setNetOfCommission(const Optional<bool>& netOfCommission) {
    this->netOfCommission = netOfCommission;
}


}
}
