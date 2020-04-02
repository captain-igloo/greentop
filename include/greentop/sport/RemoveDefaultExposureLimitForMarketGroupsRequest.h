/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_REMOVEDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H
#define SPORT_REMOVEDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/enum/MarketGroupType.h"

namespace greentop {
namespace sport {

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
}

#endif // SPORT_REMOVEDEFAULTEXPOSURELIMITFORMARKETGROUPSREQUEST_H
