#include "greentop/betting/ListMarketProfitAndLossRequest.h"

namespace greentop {
ListMarketProfitAndLossRequest::ListMarketProfitAndLossRequest() {
}

ListMarketProfitAndLossRequest::ListMarketProfitAndLossRequest(const std::set<std::string>& marketIds,
    const BoolJsonMember& includeSettledBets,
    const BoolJsonMember& includeBspBets,
    const BoolJsonMember& netOfCommission) :
    marketIds(marketIds),
    includeSettledBets(includeSettledBets),
    includeBspBets(includeBspBets),
    netOfCommission(netOfCommission) {
}

void ListMarketProfitAndLossRequest::fromJson(const Json::Value& json) {
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        };
    }
    if (json.isMember("includeSettledBets")) {
        includeSettledBets.fromJson(json["includeSettledBets"]);
    }
    if (json.isMember("includeBspBets")) {
        includeBspBets.fromJson(json["includeBspBets"]);
    }
    if (json.isMember("netOfCommission")) {
        netOfCommission.fromJson(json["netOfCommission"]);
    }
}

Json::Value ListMarketProfitAndLossRequest::toJson() const {
    Json::Value json;
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        };
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

const BoolJsonMember& ListMarketProfitAndLossRequest::getIncludeSettledBets() const {
    return includeSettledBets;
}
void ListMarketProfitAndLossRequest::setIncludeSettledBets(const BoolJsonMember& includeSettledBets) {
    this->includeSettledBets = includeSettledBets;
}

const BoolJsonMember& ListMarketProfitAndLossRequest::getIncludeBspBets() const {
    return includeBspBets;
}
void ListMarketProfitAndLossRequest::setIncludeBspBets(const BoolJsonMember& includeBspBets) {
    this->includeBspBets = includeBspBets;
}

const BoolJsonMember& ListMarketProfitAndLossRequest::getNetOfCommission() const {
    return netOfCommission;
}
void ListMarketProfitAndLossRequest::setNetOfCommission(const BoolJsonMember& netOfCommission) {
    this->netOfCommission = netOfCommission;
}


}



