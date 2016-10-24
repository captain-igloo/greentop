/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTTIMERANGESREQUEST_H
#define LISTTIMERANGESREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/sport/MarketFilter.h"
#include "greentop/sport/enum/TimeGranularity.h"

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
        /**
         * The filter to select desired markets. All markets that match the criteria in the filter
         * are selected.
         */
        MarketFilter filter;
        /**
         * The granularity of time periods that correspond to markets selected by the market
         * filter.
         */
        TimeGranularity granularity;
};

}

#endif // LISTTIMERANGESREQUEST_H


