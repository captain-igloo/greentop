/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REMOVEEXPOSURELIMITFORMARKETGROUPREQUEST_H
#define REMOVEEXPOSURELIMITFORMARKETGROUPREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/MarketGroup.h"

namespace greentop {

class RemoveExposureLimitForMarketGroupRequest : public JsonRequest {
    public:
        RemoveExposureLimitForMarketGroupRequest();

        RemoveExposureLimitForMarketGroupRequest(const MarketGroup& marketGroup);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroup& getMarketGroup() const;
        void setMarketGroup(const MarketGroup& marketGroup);


    private:
        /**
         * Market group
         */
        MarketGroup marketGroup;
};

}

#endif // REMOVEEXPOSURELIMITFORMARKETGROUPREQUEST_H
