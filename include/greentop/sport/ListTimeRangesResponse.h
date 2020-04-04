/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTTIMERANGESRESPONSE_H
#define SPORT_LISTTIMERANGESRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/TimeRangeResult.h"

namespace greentop {
namespace sport {

class ListTimeRangesResponse : public JsonResponse {
    public:
        ListTimeRangesResponse();

        ListTimeRangesResponse(const std::vector<TimeRangeResult>& timeRangeResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<TimeRangeResult>& getTimeRangeResults() const;
        void setTimeRangeResults(const std::vector<TimeRangeResult>& timeRangeResults);


    private:

        std::vector<TimeRangeResult> timeRangeResults;
};

}
}

#endif // SPORT_LISTTIMERANGESRESPONSE_H
