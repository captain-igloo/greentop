#ifndef LISTMARKETPROFITANDLOSSRESPONSE_H
#define LISTMARKETPROFITANDLOSSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/MarketProfitAndLoss.h"

namespace greentop {

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

#endif // LISTMARKETPROFITANDLOSSRESPONSE_H


