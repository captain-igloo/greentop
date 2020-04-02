/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTMARKETPROFITANDLOSSRESPONSE_H
#define SPORT_LISTMARKETPROFITANDLOSSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/MarketProfitAndLoss.h"

namespace greentop {
namespace sport {

class ListMarketProfitAndLossResponse : public JsonResponse {
    public:
        ListMarketProfitAndLossResponse();

        ListMarketProfitAndLossResponse(const std::vector<MarketProfitAndLoss>& marketProfitAndLosses);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<MarketProfitAndLoss>& getMarketProfitAndLosses() const;
        void setMarketProfitAndLosses(const std::vector<MarketProfitAndLoss>& marketProfitAndLosses);


    private:

        std::vector<MarketProfitAndLoss> marketProfitAndLosses;
};

}
}

#endif // SPORT_LISTMARKETPROFITANDLOSSRESPONSE_H
