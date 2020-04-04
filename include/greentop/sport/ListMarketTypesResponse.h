/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTMARKETTYPESRESPONSE_H
#define SPORT_LISTMARKETTYPESRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/MarketTypeResult.h"

namespace greentop {
namespace sport {

class ListMarketTypesResponse : public JsonResponse {
    public:
        ListMarketTypesResponse();

        ListMarketTypesResponse(const std::vector<MarketTypeResult>& marketTypeResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<MarketTypeResult>& getMarketTypeResults() const;
        void setMarketTypeResults(const std::vector<MarketTypeResult>& marketTypeResults);


    private:

        std::vector<MarketTypeResult> marketTypeResults;
};

}
}

#endif // SPORT_LISTMARKETTYPESRESPONSE_H
