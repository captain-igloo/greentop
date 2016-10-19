/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETPROFITANDLOSS_H
#define MARKETPROFITANDLOSS_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/RunnerProfitAndLoss.h"

namespace greentop {

class MarketProfitAndLoss : public JsonMember {
    public:

        MarketProfitAndLoss(const std::string& marketId = std::string(),
            const Optional<double>& commissionApplied = Optional<double>(),
            const std::vector<RunnerProfitAndLoss>& profitAndLosses = std::vector<RunnerProfitAndLoss>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const Optional<double>& getCommissionApplied() const;
        void setCommissionApplied(const Optional<double>& commissionApplied);

        const std::vector<RunnerProfitAndLoss>& getProfitAndLosses() const;
        void setProfitAndLosses(const std::vector<RunnerProfitAndLoss>& profitAndLosses);


    private:
        std::string marketId;
        Optional<double> commissionApplied;
        std::vector<RunnerProfitAndLoss> profitAndLosses;
};

}

#endif // MARKETPROFITANDLOSS_H


