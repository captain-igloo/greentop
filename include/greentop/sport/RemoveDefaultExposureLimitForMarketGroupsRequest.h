/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REMOVEDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H
#define REMOVEDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/enum/MarketGroupType.h"

namespace greentop {

class RemoveDefaultExposureLimitForMarketGroupsRequest : public JsonRequest {
    public:
        RemoveDefaultExposureLimitForMarketGroupsRequest();

        RemoveDefaultExposureLimitForMarketGroupsRequest(const MarketGroupType& marketGroupType);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroupType& getMarketGroupType() const;
        void setMarketGroupType(const MarketGroupType& marketGroupType);


    private:
        /**
         * Market group type
         */
        MarketGroupType marketGroupType;
};

}

#endif // REMOVEDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H
