/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TIMERANGERESULT_H
#define TIMERANGERESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/common/TimeRange.h"

namespace greentop {
/**
 * TimeRange Result
 */
class TimeRangeResult : public JsonMember {
    public:

        TimeRangeResult(const TimeRange& timeRange = TimeRange(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const TimeRange& getTimeRange() const;
        void setTimeRange(const TimeRange& timeRange);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        /**
         * TimeRange
         */
        TimeRange timeRange;
        /**
         * Count of markets associated with this TimeRange
         */
        Optional<int32_t> marketCount;
};

}

#endif // TIMERANGERESULT_H
