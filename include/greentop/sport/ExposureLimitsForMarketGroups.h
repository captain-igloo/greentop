/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXPOSURELIMITSFORMARKETGROUPS_H
#define EXPOSURELIMITSFORMARKETGROUPS_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/sport/ExposureLimit.h"
#include "greentop/sport/MarketGroupExposureLimit.h"
#include "greentop/sport/MarketGroupId.h"
#include "greentop/sport/enum/MarketGroupType.h"

namespace greentop {
/**
 * Wrapper type that contains accounts exposure limits for a market group type. If default limit
 * exists for group type, defaultLimit value will be populated. Group limits to return can be
 * controller by marketGroupFilter parameter (see listExposureLimitsForMarketGroups operation).
 */
class ExposureLimitsForMarketGroups : public JsonMember {
    public:
        ExposureLimitsForMarketGroups();

        ExposureLimitsForMarketGroups(const MarketGroupType& marketGroupType,
            const ExposureLimit& defaultLimit = ExposureLimit(),
            const std::vector<MarketGroupExposureLimit>& groupLimits = std::vector<MarketGroupExposureLimit>(),
            const std::vector<MarketGroupId>& blockedMarketGroups = std::vector<MarketGroupId>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroupType& getMarketGroupType() const;
        void setMarketGroupType(const MarketGroupType& marketGroupType);

        const ExposureLimit& getDefaultLimit() const;
        void setDefaultLimit(const ExposureLimit& defaultLimit);

        const std::vector<MarketGroupExposureLimit>& getGroupLimits() const;
        void setGroupLimits(const std::vector<MarketGroupExposureLimit>& groupLimits);

        const std::vector<MarketGroupId>& getBlockedMarketGroups() const;
        void setBlockedMarketGroups(const std::vector<MarketGroupId>& blockedMarketGroups);


    private:
        /**
         * Market Group Type
         */
        MarketGroupType marketGroupType;
        /**
         * Default limit (if exists)
         */
        ExposureLimit defaultLimit;
        /**
         * Group limits for type
         */
        std::vector<MarketGroupExposureLimit> groupLimits;
        /**
         * Blocked groups due to limit breach
         */
        std::vector<MarketGroupId> blockedMarketGroups;
};

}

#endif // EXPOSURELIMITSFORMARKETGROUPS_H
