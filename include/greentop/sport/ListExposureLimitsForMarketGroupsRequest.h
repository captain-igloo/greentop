/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTEXPOSURELIMITSFORMARKETGROUPSREQUEST_H
#define LISTEXPOSURELIMITSFORMARKETGROUPSREQUEST_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/sport/MarketGroup.h"
#include "greentop/sport/enum/MarketGroupType.h"

namespace greentop {

class ListExposureLimitsForMarketGroupsRequest : public JsonRequest {
    public:

        ListExposureLimitsForMarketGroupsRequest(const MarketGroupType& marketGroupTypeFilter = MarketGroupType(),
            const std::vector<MarketGroup>& marketGroupFilter = std::vector<MarketGroup>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroupType& getMarketGroupTypeFilter() const;
        void setMarketGroupTypeFilter(const MarketGroupType& marketGroupTypeFilter);

        const std::vector<MarketGroup>& getMarketGroupFilter() const;
        void setMarketGroupFilter(const std::vector<MarketGroup>& marketGroupFilter);


    private:
        /**
         * Optionally filter results by market group type.
         */
        MarketGroupType marketGroupTypeFilter;
        /**
         * Optionally filter result by market groups.
         */
        std::vector<MarketGroup> marketGroupFilter;
};

}

#endif // LISTEXPOSURELIMITSFORMARKETGROUPSREQUEST_H
