/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketTypesResponse.h"

namespace greentop {

ListMarketTypesResponse::ListMarketTypesResponse() {
}

ListMarketTypesResponse::ListMarketTypesResponse(const std::vector<MarketTypeResult>& marketTypeResults) :
    marketTypeResults(marketTypeResults) {
}

void ListMarketTypesResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            MarketTypeResult marketTypeResult;
            marketTypeResult.fromJson(json[i]);
            marketTypeResults.push_back(marketTypeResult);
        }
    }
}

Json::Value ListMarketTypesResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (marketTypeResults.size() > 0) {
        for (unsigned i = 0; i < marketTypeResults.size(); ++i) {
            json.append(marketTypeResults[i].toJson());
        }
    }
    return json;
}

bool ListMarketTypesResponse::isValid() const {
    return marketTypeResults.size() > 0;
}

const std::vector<MarketTypeResult>& ListMarketTypesResponse::getMarketTypeResults() const {
    return marketTypeResults;
}
void ListMarketTypesResponse::setMarketTypeResults(const std::vector<MarketTypeResult>& marketTypeResults) {
    this->marketTypeResults = marketTypeResults;
}


}



