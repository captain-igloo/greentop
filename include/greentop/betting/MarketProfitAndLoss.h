#ifndef MARKETPROFITANDLOSS_H
#define MARKETPROFITANDLOSS_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/betting/RunnerProfitAndLoss.h"

namespace greentop {

class MarketProfitAndLoss : public JsonMember {
    public:

        MarketProfitAndLoss(const std::string& marketId = std::string(),
            const double commissionApplied = -1,
            const std::vector<RunnerProfitAndLoss>& profitAndLosses = std::vector<RunnerProfitAndLoss>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const double getCommissionApplied() const;
        void setCommissionApplied(const double commissionApplied);

        const std::vector<RunnerProfitAndLoss>& getProfitAndLosses() const;
        void setProfitAndLosses(const std::vector<RunnerProfitAndLoss>& profitAndLosses);


    private:
        std::string marketId;
        double commissionApplied;
        std::vector<RunnerProfitAndLoss> profitAndLosses;
};

}

#endif // MARKETPROFITANDLOSS_H


