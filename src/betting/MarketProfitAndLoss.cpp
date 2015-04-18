/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/MarketProfitAndLoss.h"

namespace greentop {

MarketProfitAndLoss::MarketProfitAndLoss(const std::string& marketId,
    const double commissionApplied,
    const std::vector<RunnerProfitAndLoss>& profitAndLosses) :
    marketId(marketId),
    commissionApplied(commissionApplied),
    profitAndLosses(profitAndLosses) {
}

void MarketProfitAndLoss::fromJson(const Json::Value& json) {
    if (json.isMember("marketId")) {
        marketId = json["marketId"].asString();
    }
    if (json.isMember("commissionApplied")) {
        commissionApplied = json["commissionApplied"].asDouble();
    }
    if (json.isMember("profitAndLosses")) {
        for (unsigned i = 0; i < json["profitAndLosses"].size(); ++i) {
                RunnerProfitAndLoss profitAndLosse;
                profitAndLosse.fromJson(json["profitAndLosses"][i]);
                profitAndLosses.push_back(profitAndLosse);
            };
    }
}

Json::Value MarketProfitAndLoss::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (commissionApplied >= 0) {
        json["commissionApplied"] = commissionApplied;
    }
    if (profitAndLosses.size() > 0) {
        for (unsigned i = 0; i < profitAndLosses.size(); ++i) {
            json["profitAndLosses"].append(profitAndLosses[i].toJson());
        };
    }
    return json;
}

bool MarketProfitAndLoss::isValid() const {
    return true;
}

const std::string& MarketProfitAndLoss::getMarketId() const {
    return marketId;
}
void MarketProfitAndLoss::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const double MarketProfitAndLoss::getCommissionApplied() const {
    return commissionApplied;
}
void MarketProfitAndLoss::setCommissionApplied(const double commissionApplied) {
    this->commissionApplied = commissionApplied;
}

const std::vector<RunnerProfitAndLoss>& MarketProfitAndLoss::getProfitAndLosses() const {
    return profitAndLosses;
}
void MarketProfitAndLoss::setProfitAndLosses(const std::vector<RunnerProfitAndLoss>& profitAndLosses) {
    this->profitAndLosses = profitAndLosses;
}


}



