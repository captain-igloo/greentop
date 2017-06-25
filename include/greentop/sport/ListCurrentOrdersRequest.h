/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
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
            const std::set<std::string>& customerOrderRefs = std::set<std::string>(),
            const std::set<std::string>& customerStrategyRefs = std::set<std::string>(),
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

        const std::set<std::string>& getCustomerOrderRefs() const;
        void setCustomerOrderRefs(const std::set<std::string>& customerOrderRefs);

        const std::set<std::string>& getCustomerStrategyRefs() const;
        void setCustomerStrategyRefs(const std::set<std::string>& customerStrategyRefs);

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
        /**
         * Optionally restricts the results to the specified bet IDs.
         */
        std::set<std::string> betIds;
        /**
         * Optionally restricts the results to the specified market IDs.
         */
        std::set<std::string> marketIds;
        /**
         * Optionally restricts the results to the specified order status.
         */
        OrderProjection orderProjection;
        /**
         * Optionally restricts the results to the specified customer order references.
         */
        std::set<std::string> customerOrderRefs;
        /**
         * Optionally restricts the results to the specified customer strategy references.
         */
        std::set<std::string> customerStrategyRefs;
        /**
         * @Deprecated use dateRange instead. Optionally restricts the results to be from/to the
         * specified placed date. This date is inclusive, i.e. if an order was placed on exactly
         * this date (to the millisecond) then it will be included in the results. If the from is
         * later than the to, no results will be returned.
         */
        TimeRange placedDateRange;
        /**
         * Replacement for placedDateRange to allow filtering by other date fields rather than just
         * placedDate. Optionally restricts the results to be from/to the specified date, these
         * dates are contextual to the orders being returned and therefore the dates used to filter
         * on will change to placed, matched, voided or settled dates depending on the orderBy.
         * This date is inclusive, i.e. if an order was placed on exactly this date (to the
         * millisecond) then it will be included in the results. If the from is later than the to,
         * no results will be returned.
         */
        TimeRange dateRange;
        /**
         * Specifies how the results will be ordered. If no value is passed in, it defaults to
         * BY_BET. Also acts as a filter such that only orders with a valid value in the field
         * being ordered by will be returned (i.e. BY_VOID_TIME returns only voided orders,
         * BY_SETTLED_TIME returns only settled orders and BY_MATCH_TIME returns only orders with a
         * matched date (voided, settled, matched orders)).
         */
        OrderBy orderBy;
        /**
         * Specifies the direction the results will be sorted in. If no value is passed in, it
         * defaults to EARLIEST_TO_LATEST.
         */
        SortDir sortDir;
        /**
         * Specifies the first record that will be returned. Records start at index zero, not at
         * index one.
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

#endif // LISTCURRENTORDERSREQUEST_H
