/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTEXPOSURELIMITSFORMARKETGROUPSRESPONSE_H
#define LISTEXPOSURELIMITSFORMARKETGROUPSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/ExposureLimitsForMarketGroups.h"

namespace greentop {

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

#endif // LISTEXPOSURELIMITSFORMARKETGROUPSRESPONSE_H
