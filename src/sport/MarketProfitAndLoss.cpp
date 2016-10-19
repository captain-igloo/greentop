/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketProfitAndLoss.h"

namespace greentop {


MarketProfitAndLoss::MarketProfitAndLoss(const std::string& marketId,
    const Optional<double>& commissionApplied,
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
        }
    }
}

Json::Value MarketProfitAndLoss::toJson() const {
    Json::Value json(Json::objectValue);
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (commissionApplied.isValid()) {
        json["commissionApplied"] = commissionApplied.toJson();
    }
    if (profitAndLosses.size() > 0) {
        for (unsigned i = 0; i < profitAndLosses.size(); ++i) {
            json["profitAndLosses"].append(profitAndLosses[i].toJson());
        }
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

const Optional<double>& MarketProfitAndLoss::getCommissionApplied() const {
    return commissionApplied;
}
void MarketProfitAndLoss::setCommissionApplied(const Optional<double>& commissionApplied) {
    this->commissionApplied = commissionApplied;
}

const std::vector<RunnerProfitAndLoss>& MarketProfitAndLoss::getProfitAndLosses() const {
    return profitAndLosses;
}
void MarketProfitAndLoss::setProfitAndLosses(const std::vector<RunnerProfitAndLoss>& profitAndLosses) {
    this->profitAndLosses = profitAndLosses;
}


}



