/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCLEAREDORDERSREQUEST_H
#define LISTCLEAREDORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/betting/RunnerId.h"
#include "greentop/betting/TimeRange.h"
#include "greentop/enum/BetStatus.h"
#include "greentop/enum/GroupBy.h"
#include "greentop/enum/Side.h"

namespace greentop {

class ListClearedOrdersRequest : public JsonRequest {
    public:
        ListClearedOrdersRequest();

        ListClearedOrdersRequest(const BetStatus& betStatus,
            const std::vector<std::string>& eventTypeIds = std::vector<std::string>(),
            const std::vector<std::string>& eventIds = std::vector<std::string>(),
            const std::vector<std::string>& marketIds = std::vector<std::string>(),
            const std::vector<RunnerId>& runnerIds = std::vector<RunnerId>(),
            const std::vector<std::string>& betIds = std::vector<std::string>(),
            const Side& side = Side(),
            const TimeRange& settledDateRange = TimeRange(),
            const GroupBy& groupBy = GroupBy(),
            const Optional<bool>& includeItemDescription = Optional<bool>(),
            const std::string& locale = std::string(),
            const uint64_t fromRecord = 0,
            const uint64_t recordCount = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const BetStatus& getBetStatus() const;
        void setBetStatus(const BetStatus& betStatus);

        const std::vector<std::string>& getEventTypeIds() const;
        void setEventTypeIds(const std::vector<std::string>& eventTypeIds);

        const std::vector<std::string>& getEventIds() const;
        void setEventIds(const std::vector<std::string>& eventIds);

        const std::vector<std::string>& getMarketIds() const;
        void setMarketIds(const std::vector<std::string>& marketIds);

        const std::vector<RunnerId>& getRunnerIds() const;
        void setRunnerIds(const std::vector<RunnerId>& runnerIds);

        const std::vector<std::string>& getBetIds() const;
        void setBetIds(const std::vector<std::string>& betIds);

        const Side& getSide() const;
        void setSide(const Side& side);

        const TimeRange& getSettledDateRange() const;
        void setSettledDateRange(const TimeRange& settledDateRange);

        const GroupBy& getGroupBy() const;
        void setGroupBy(const GroupBy& groupBy);

        const Optional<bool>& getIncludeItemDescription() const;
        void setIncludeItemDescription(const Optional<bool>& includeItemDescription);

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);

        const uint64_t getFromRecord() const;
        void setFromRecord(const uint64_t fromRecord);

        const uint64_t getRecordCount() const;
        void setRecordCount(const uint64_t recordCount);


    private:
        BetStatus betStatus;
        std::vector<std::string> eventTypeIds;
        std::vector<std::string> eventIds;
        std::vector<std::string> marketIds;
        std::vector<RunnerId> runnerIds;
        std::vector<std::string> betIds;
        Side side;
        TimeRange settledDateRange;
        GroupBy groupBy;
        Optional<bool> includeItemDescription;
        std::string locale;
        uint64_t fromRecord;
        uint64_t recordCount;
};

}

#endif // LISTCLEAREDORDERSREQUEST_H


