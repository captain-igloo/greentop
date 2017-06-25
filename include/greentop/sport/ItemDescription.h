/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ITEMDESCRIPTION_H
#define ITEMDESCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"

namespace greentop {
/**
 * This object contains some text which may be useful to render a betting history view. It offers
 * no long-term warranty as to the correctness of the text.
 */
class ItemDescription : public JsonMember {
    public:

        ItemDescription(const std::string& eventTypeDesc = std::string(),
            const std::string& eventDesc = std::string(),
            const std::string& marketDesc = std::string(),
            const std::string& marketType = std::string(),
            const std::tm& marketStartTime = std::tm(),
            const std::string& runnerDesc = std::string(),
            const Optional<int32_t>& numberOfWinners = Optional<int32_t>(),
            const Optional<double>& eachWayDivisor = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getEventTypeDesc() const;
        void setEventTypeDesc(const std::string& eventTypeDesc);

        const std::string& getEventDesc() const;
        void setEventDesc(const std::string& eventDesc);

        const std::string& getMarketDesc() const;
        void setMarketDesc(const std::string& marketDesc);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const std::tm& getMarketStartTime() const;
        void setMarketStartTime(const std::tm& marketStartTime);

        const std::string& getRunnerDesc() const;
        void setRunnerDesc(const std::string& runnerDesc);

        const Optional<int32_t>& getNumberOfWinners() const;
        void setNumberOfWinners(const Optional<int32_t>& numberOfWinners);

        const Optional<double>& getEachWayDivisor() const;
        void setEachWayDivisor(const Optional<double>& eachWayDivisor);


    private:
        /**
         * The event type name, translated into the requested locale. Available at EVENT_TYPE
         * groupBy or lower.
         */
        std::string eventTypeDesc;
        /**
         * The eventName, or openDate + venue, translated into the requested locale. Available at
         * EVENT groupBy or lower.
         */
        std::string eventDesc;
        /**
         * The market name or racing market type ("Win", "To Be Placed (2 places)", "To Be Placed
         * (5 places)" etc) translated into the requested locale. Available at MARKET groupBy or
         * lower.
         */
        std::string marketDesc;
        /**
         * The market type
         */
        std::string marketType;
        /**
         * The start time of the market (in ISO-8601 format, not translated). Available at MARKET
         * groupBy or lower.
         */
        std::tm marketStartTime;
        /**
         * The runner name, maybe including the handicap, translated into the requested locale.
         * Available at BET groupBy.
         */
        std::string runnerDesc;
        /**
         * The numberOfWinners on a market. Available at BET groupBy.
         */
        Optional<int32_t> numberOfWinners;
        /**
         * The odds divisor applicable to EachWay markets
         */
        Optional<double> eachWayDivisor;
};

}

#endif // ITEMDESCRIPTION_H
