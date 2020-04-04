/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTEXPOSURELIMITSFORMARKETGROUPSRESPONSE_H
#define SPORT_LISTEXPOSURELIMITSFORMARKETGROUPSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/ExposureLimitsForMarketGroups.h"

namespace greentop {
namespace sport {

class ListExposureLimitsForMarketGroupsResponse : public JsonResponse {
    public:
        ListExposureLimitsForMarketGroupsResponse();

        ListExposureLimitsForMarketGroupsResponse(const std::vector<ExposureLimitsForMarketGroups>& exposureLimitsForMarketGroupses);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<ExposureLimitsForMarketGroups>& getExposureLimitsForMarketGroupses() const;
        void setExposureLimitsForMarketGroupses(const std::vector<ExposureLimitsForMarketGroups>& exposureLimitsForMarketGroupses);


    private:

        std::vector<ExposureLimitsForMarketGroups> exposureLimitsForMarketGroupses;
};

}
}

#endif // SPORT_LISTEXPOSURELIMITSFORMARKETGROUPSRESPONSE_H
