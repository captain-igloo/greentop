#ifndef LISTTIMERANGESREQUEST_H
#define LISTTIMERANGESREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/betting/MarketFilter.h"
#include "greentop/enum/TimeGranularity.h"

namespace greentop {

class ListTimeRangesRequest : public JsonRequest {
    public:
        ListTimeRangesRequest();

        ListTimeRangesRequest(const MarketFilter& filter,
            const TimeGranularity& granularity);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketFilter& getFilter() const;
        void setFilter(const MarketFilter& filter);

        const TimeGranularity& getGranularity() const;
        void setGranularity(const TimeGranularity& granularity);


    private:
        MarketFilter filter;
        TimeGranularity granularity;
};

}

#endif // LISTTIMERANGESREQUEST_H


