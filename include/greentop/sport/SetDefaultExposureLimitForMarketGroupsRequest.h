/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_SETDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H
#define SPORT_SETDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/ExposureLimit.h"
#include "greentop/sport/enum/MarketGroupType.h"

namespace greentop {
namespace sport {

class SetDefaultExposureLimitForMarketGroupsRequest : public JsonRequest {
    public:
        SetDefaultExposureLimitForMarketGroupsRequest();

        SetDefaultExposureLimitForMarketGroupsRequest(const MarketGroupType& marketGroupType,
            const ExposureLimit& limit);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroupType& getMarketGroupType() const;
        void setMarketGroupType(const MarketGroupType& marketGroupType);

        const ExposureLimit& getLimit() const;
        void setLimit(const ExposureLimit& limit);


    private:
        /**
         * Market group type
         */
        MarketGroupType marketGroupType;
        /**
         * Default exposure limit and action
         */
        ExposureLimit limit;
};

}
}

#endif // SPORT_SETDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H
