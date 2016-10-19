/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETLINERANGEINFO_H
#define MARKETLINERANGEINFO_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class MarketLineRangeInfo : public JsonMember {
    public:
        MarketLineRangeInfo();

        MarketLineRangeInfo(const double maxUnitValue,
            const double minUnitValue,
            const double interval,
            const std::string& marketUnit);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getMaxUnitValue() const;
        void setMaxUnitValue(const double maxUnitValue);

        const double getMinUnitValue() const;
        void setMinUnitValue(const double minUnitValue);

        const double getInterval() const;
        void setInterval(const double interval);

        const std::string& getMarketUnit() const;
        void setMarketUnit(const std::string& marketUnit);


    private:
        double maxUnitValue;
        double minUnitValue;
        double interval;
        std::string marketUnit;
};

}

#endif // MARKETLINERANGEINFO_H


