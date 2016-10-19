/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCURRENTORDERSREQUEST_H
#define LISTCURRENTORDERSREQUEST_H

#include <json/json.h>
#include <set>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/common/TimeRange.h"
#include "greentop/sport/enum/OrderBy.h"
#include "greentop/sport/enum/OrderProjection.h"
#include "greentop/sport/enum/SortDir.h"

namespace greentop {

class ListCurrentOrdersRequest : public JsonRequest {
    public:

        ListCurrentOrdersRequest(const std::set<std::string>& betIds = std::set<std::string>(),
            const std::set<std::string>& marketIds = std::set<std::string>(),
            const OrderProjection& orderProjection = OrderProjection(),
            const TimeRange& placedDateRange = TimeRange(),
            const TimeRange& dateRange = TimeRange(),
            const OrderBy& orderBy = OrderBy(),
            const SortDir& sortDir = SortDir(),
            const Optional<int32_t>& fromRecord = Optional<int32_t>(),
            const Optional<int32_t>& recordCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::set<std::string>& getBetIds() const;
        void setBetIds(const std::set<std::string>& betIds);

        const std::set<std::string>& getMarketIds() const;
        void setMarketIds(const std::set<std::string>& marketIds);

        const OrderProjection& getOrderProjection() const;
        void setOrderProjection(const OrderProjection& orderProjection);

        const TimeRange& getPlacedDateRange() const;
        void setPlacedDateRange(const TimeRange& placedDateRange);

        const TimeRange& getDateRange() const;
        void setDateRange(const TimeRange& dateRange);

        const OrderBy& getOrderBy() const;
        void setOrderBy(const OrderBy& orderBy);

        const SortDir& getSortDir() const;
        void setSortDir(const SortDir& sortDir);

        const Optional<int32_t>& getFromRecord() const;
        void setFromRecord(const Optional<int32_t>& fromRecord);

        const Optional<int32_t>& getRecordCount() const;
        void setRecordCount(const Optional<int32_t>& recordCount);


    private:
        std::set<std::string> betIds;
        std::set<std::string> marketIds;
        OrderProjection orderProjection;
        TimeRange placedDateRange;
        TimeRange dateRange;
        OrderBy orderBy;
        SortDir sortDir;
        Optional<int32_t> fromRecord;
        Optional<int32_t> recordCount;
};

}

#endif // LISTCURRENTORDERSREQUEST_H


