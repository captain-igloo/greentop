/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_TIMERANGERESULT_H
#define SPORT_TIMERANGERESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/common/TimeRange.h"

namespace greentop {
namespace sport {
/**
 * TimeRange Result
 */
class TimeRangeResult : public JsonMember {
    public:

        TimeRangeResult(const common::TimeRange& timeRange = common::TimeRange(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const common::TimeRange& getTimeRange() const;
        void setTimeRange(const common::TimeRange& timeRange);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        /**
         * TimeRange
         */
        common::TimeRange timeRange;
        /**
         * Count of markets associated with this TimeRange
         */
        Optional<int32_t> marketCount;
};

}
}

#endif // SPORT_TIMERANGERESULT_H
