/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETLINERANGEINFO_H
#define SPORT_MARKETLINERANGEINFO_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {
/**
 * Market Line and Range Info
 */
class MarketLineRangeInfo : public JsonMember {
    public:
        MarketLineRangeInfo();

        MarketLineRangeInfo(const Optional<double>& maxUnitValue,
            const Optional<double>& minUnitValue,
            const Optional<double>& interval,
            const std::string& marketUnit);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getMaxUnitValue() const;
        void setMaxUnitValue(const Optional<double>& maxUnitValue);

        const Optional<double>& getMinUnitValue() const;
        void setMinUnitValue(const Optional<double>& minUnitValue);

        const Optional<double>& getInterval() const;
        void setInterval(const Optional<double>& interval);

        const std::string& getMarketUnit() const;
        void setMarketUnit(const std::string& marketUnit);


    private:
        /**
         * Maximum value for the outcome, in market units for this market (eg 100 runs)
         */
        Optional<double> maxUnitValue;
        /**
         * Minimum value for the outcome, in market units for this market (eg 0 runs)
         */
        Optional<double> minUnitValue;
        /**
         * . For Handicap and Line markets, the lines available on this market will be between the
         * range of minUnitValue and maxUnitValue, in increments of the interval value. e.g. If
         * marketUnit is runs, minUnitValue=10, maxUnitValue=20 and interval=0.5, then valid lines
         * include 10, 10.5, 11, 11.5 up to 20 runs.
         */
        Optional<double> interval;
        /**
         * The type of unit the lines are incremented in by the interval (e.g: runs, goals or
         * seconds)
         */
        std::string marketUnit;
};

}
}

#endif // SPORT_MARKETLINERANGEINFO_H
