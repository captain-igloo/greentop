/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_SETEXPOSURELIMITFORMARKETGROUPREQUEST_H
#define SPORT_SETEXPOSURELIMITFORMARKETGROUPREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/ExposureLimit.h"
#include "greentop/sport/MarketGroup.h"

namespace greentop {
namespace sport {

class SetExposureLimitForMarketGroupRequest : public JsonRequest {
    public:
        SetExposureLimitForMarketGroupRequest();

        SetExposureLimitForMarketGroupRequest(const MarketGroup& marketGroup,
            const ExposureLimit& limit);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroup& getMarketGroup() const;
        void setMarketGroup(const MarketGroup& marketGroup);

        const ExposureLimit& getLimit() const;
        void setLimit(const ExposureLimit& limit);


    private:
        /**
         * Market group
         */
        MarketGroup marketGroup;
        /**
         * Exposure limit
         */
        ExposureLimit limit;
};

}
}

#endif // SPORT_SETEXPOSURELIMITFORMARKETGROUPREQUEST_H
