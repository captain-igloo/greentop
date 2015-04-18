/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCURRENTORDERSREQUEST_H
#define LISTCURRENTORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/betting/TimeRange.h"
#include "greentop/enum/OrderBy.h"
#include "greentop/enum/OrderProjection.h"
#include "greentop/enum/SortDir.h"

namespace greentop {

class ListCurrentOrdersRequest : public JsonRequest {
    public:

        ListCurrentOrdersRequest(const std::vector<std::string>& betIds = std::vector<std::string>(),
            const std::vector<std::string>& marketIds = std::vector<std::string>(),
            const OrderProjection& orderProjection = OrderProjection(),
            const TimeRange& dateRange = TimeRange(),
            const OrderBy& orderBy = OrderBy(),
            const SortDir& sortDir = SortDir(),
            const int fromRecord = -1,
            const int recordCount = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<std::string>& getBetIds() const;
        void setBetIds(const std::vector<std::string>& betIds);

        const std::vector<std::string>& getMarketIds() const;
        void setMarketIds(const std::vector<std::string>& marketIds);

        const OrderProjection& getOrderProjection() const;
        void setOrderProjection(const OrderProjection& orderProjection);

        const TimeRange& getDateRange() const;
        void setDateRange(const TimeRange& dateRange);

        const OrderBy& getOrderBy() const;
        void setOrderBy(const OrderBy& orderBy);

        const SortDir& getSortDir() const;
        void setSortDir(const SortDir& sortDir);

        const int getFromRecord() const;
        void setFromRecord(const int fromRecord);

        const int getRecordCount() const;
        void setRecordCount(const int recordCount);


    private:
        std::vector<std::string> betIds;
        std::vector<std::string> marketIds;
        OrderProjection orderProjection;
        TimeRange dateRange;
        OrderBy orderBy;
        SortDir sortDir;
        int fromRecord;
        int recordCount;
};

}

#endif // LISTCURRENTORDERSREQUEST_H


