/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETLINERANGEINFO_H
#define MARKETLINERANGEINFO_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Market Line and Range Info
 */
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
        /**
         * maxPrice
         */
        Optional<double> maxUnitValue;
        /**
         * minPrice
         */
        Optional<double> minUnitValue;
        /**
         * interval
         */
        Optional<double> interval;
        /**
         * unit
         */
        std::string marketUnit;
};

}

#endif // MARKETLINERANGEINFO_H


