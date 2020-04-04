/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETPROFITANDLOSS_H
#define SPORT_MARKETPROFITANDLOSS_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/RunnerProfitAndLoss.h"

namespace greentop {
namespace sport {
/**
 * Profit and loss in a market
 */
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
        /**
         * The unique identifier for the market
         */
        std::string marketId;
        /**
         * The commission rate applied to P&L values. Only returned if netOfCommision option is
         * requested
         */
        Optional<double> commissionApplied;
        /**
         * Calculated profit and loss data.
         */
        std::vector<RunnerProfitAndLoss> profitAndLosses;
};

}
}

#endif // SPORT_MARKETPROFITANDLOSS_H
