/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketProfitAndLossResponse.h"

namespace greentop {

ListMarketProfitAndLossResponse::ListMarketProfitAndLossResponse() {
}

ListMarketProfitAndLossResponse::ListMarketProfitAndLossResponse(const std::vector<MarketProfitAndLoss>& marketProfitAndLosses) :
    marketProfitAndLosses(marketProfitAndLosses) {
}

void ListMarketProfitAndLossResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            MarketProfitAndLoss marketProfitAndLosse;
            marketProfitAndLosse.fromJson(json[i]);
            marketProfitAndLosses.push_back(marketProfitAndLosse);
        }
    }
}

Json::Value ListMarketProfitAndLossResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (marketProfitAndLosses.size() > 0) {
        for (unsigned i = 0; i < marketProfitAndLosses.size(); ++i) {
            json.append(marketProfitAndLosses[i].toJson());
        }
    }
    return json;
}

bool ListMarketProfitAndLossResponse::isValid() const {
    return marketProfitAndLosses.size() > 0;
}

const std::vector<MarketProfitAndLoss>& ListMarketProfitAndLossResponse::getMarketProfitAndLosses() const {
    return marketProfitAndLosses;
}
void ListMarketProfitAndLossResponse::setMarketProfitAndLosses(const std::vector<MarketProfitAndLoss>& marketProfitAndLosses) {
    this->marketProfitAndLosses = marketProfitAndLosses;
}


}



