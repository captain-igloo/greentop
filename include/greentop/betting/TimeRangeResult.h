#ifndef TIMERANGERESULT_H
#define TIMERANGERESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/betting/TimeRange.h"

namespace greentop {

class TimeRangeResult : public JsonMember {
    public:

        TimeRangeResult(const TimeRange& timeRange = TimeRange(),
            const uint64_t marketCount = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const TimeRange& getTimeRange() const;
        void setTimeRange(const TimeRange& timeRange);

        const uint64_t getMarketCount() const;
        void setMarketCount(const uint64_t marketCount);


    private:
        TimeRange timeRange;
        uint64_t marketCount;
};

}

#endif // TIMERANGERESULT_H


