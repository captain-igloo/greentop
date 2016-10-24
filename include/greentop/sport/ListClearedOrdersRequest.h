/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCLEAREDORDERSREQUEST_H
#define LISTCLEAREDORDERSREQUEST_H

#include <json/json.h>
#include <set>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/common/TimeRange.h"
#include "greentop/sport/RunnerId.h"
#include "greentop/sport/enum/BetStatus.h"
#include "greentop/sport/enum/GroupBy.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {

class ListClearedOrdersRequest : public JsonRequest {
    public:
        ListClearedOrdersRequest();

        ListClearedOrdersRequest(const BetStatus& betStatus,
            const std::set<std::string>& eventTypeIds = std::set<std::string>(),
            const std::set<std::string>& eventIds = std::set<std::string>(),
            const std::set<std::string>& marketIds = std::set<std::string>(),
            const std::vector<RunnerId>& runnerIds = std::vector<RunnerId>(),
            const std::set<std::string>& betIds = std::set<std::string>(),
            const Side& side = Side(),
            const TimeRange& settledDateRange = TimeRange(),
            const GroupBy& groupBy = GroupBy(),
            const Optional<bool>& includeItemDescription = Optional<bool>(),
            const std::string& locale = std::string(),
            const Optional<int32_t>& fromRecord = Optional<int32_t>(),
            const Optional<int32_t>& recordCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const BetStatus& getBetStatus() const;
        void setBetStatus(const BetStatus& betStatus);

        const std::set<std::string>& getEventTypeIds() const;
        void setEventTypeIds(const std::set<std::string>& eventTypeIds);

        const std::set<std::string>& getEventIds() const;
        void setEventIds(const std::set<std::string>& eventIds);

        const std::set<std::string>& getMarketIds() const;
        void setMarketIds(const std::set<std::string>& marketIds);

        const std::vector<RunnerId>& getRunnerIds() const;
        void setRunnerIds(const std::vector<RunnerId>& runnerIds);

        const std::set<std::string>& getBetIds() const;
        void setBetIds(const std::set<std::string>& betIds);

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

        const Optional<int32_t>& getFromRecord() const;
        void setFromRecord(const Optional<int32_t>& fromRecord);

        const Optional<int32_t>& getRecordCount() const;
        void setRecordCount(const Optional<int32_t>& recordCount);


    private:
        /**
         * Restricts the results to the specified status.
         */
        BetStatus betStatus;
        /**
         * Optionally restricts the results to the specified Event Type IDs.
         */
        std::set<std::string> eventTypeIds;
        /**
         * Optionally restricts the results to the specified Event IDs.
         */
        std::set<std::string> eventIds;
        /**
         * Optionally restricts the results to the specified market IDs.
         */
        std::set<std::string> marketIds;
        /**
         * Optionally restricts the results to the specified Runners.
         */
        std::vector<RunnerId> runnerIds;
        /**
         * Optionally restricts the results to the specified bet IDs.
         */
        std::set<std::string> betIds;
        /**
         * Optionally restricts the results to the specified side.
         */
        Side side;
        /**
         * Optionally restricts the results to be from/to the specified settled date. This date is
         * inclusive, i.e. if an order was placed on exactly this date (to the millisecond) then it
         * will be included in the results. If the from is later than the to, no results will be
         * returned.
         */
        TimeRange settledDateRange;
        /**
         * How to aggregate the lines, if not supplied then the lowest level is returned, i.e. bet
         * by bet This is only applicable to SETTLED BetStatus.
         */
        GroupBy groupBy;
        /**
         * If true then an ItemDescription object is included in the response.
         */
        Optional<bool> includeItemDescription;
        /**
         * The language used for the itemDescription. If not specified, the customer account
         * default is returned.
         */
        std::string locale;
        /**
         * Specifies the first record that will be returned. Records start at index zero.
         */
        Optional<int32_t> fromRecord;
        /**
         * Specifies how many records will be returned, from the index position 'fromRecord'. Note
         * that there is a page size limit of 1000. A value of zero indicates that you would like
         * all records (including and from 'fromRecord') up to the limit.
         */
        Optional<int32_t> recordCount;
};

}

#endif // LISTCLEAREDORDERSREQUEST_H


