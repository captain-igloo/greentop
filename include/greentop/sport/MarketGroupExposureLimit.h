/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETGROUPEXPOSURELIMIT_H
#define MARKETGROUPEXPOSURELIMIT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/ExposureLimit.h"
#include "greentop/sport/MarketGroupId.h"

namespace greentop {
/**
 * Container type for a group exposure limit
 */
class MarketGroupExposureLimit : public JsonMember {
    public:
        MarketGroupExposureLimit();

        MarketGroupExposureLimit(const MarketGroupId& groupId,
            const ExposureLimit& limit);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroupId& getGroupId() const;
        void setGroupId(const MarketGroupId& groupId);

        const ExposureLimit& getLimit() const;
        void setLimit(const ExposureLimit& limit);


    private:
        /**
         * Market group ID
         */
        MarketGroupId groupId;
        /**
         * Exposure limit
         */
        ExposureLimit limit;
};

}

#endif // MARKETGROUPEXPOSURELIMIT_H
