/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETACCOUNTSTATEMENTREQUEST_H
#define GETACCOUNTSTATEMENTREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/account/enum/IncludeItem.h"
#include "greentop/account/enum/Wallet.h"
#include "greentop/common/TimeRange.h"

namespace greentop {

class GetAccountStatementRequest : public JsonRequest {
    public:

        GetAccountStatementRequest(const std::string& locale = std::string(),
            const Optional<int32_t>& fromRecord = Optional<int32_t>(),
            const Optional<int32_t>& recordCount = Optional<int32_t>(),
            const TimeRange& itemDateRange = TimeRange(),
            const IncludeItem& includeItem = IncludeItem(),
            const Wallet& wallet = Wallet());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);

        const Optional<int32_t>& getFromRecord() const;
        void setFromRecord(const Optional<int32_t>& fromRecord);

        const Optional<int32_t>& getRecordCount() const;
        void setRecordCount(const Optional<int32_t>& recordCount);

        const TimeRange& getItemDateRange() const;
        void setItemDateRange(const TimeRange& itemDateRange);

        const IncludeItem& getIncludeItem() const;
        void setIncludeItem(const IncludeItem& includeItem);

        const Wallet& getWallet() const;
        void setWallet(const Wallet& wallet);


    private:
        /**
         * The language to be used where applicable. If not specified, the customer account default
         * is returned.
         */
        std::string locale;
        /**
         * Specifies the first record that will be returned. Records start at index zero. If not
         * specified then it will default to 0.
         */
        Optional<int32_t> fromRecord;
        /**
         * Specifies the maximum number of records to be returned. Note that there is a page size
         * limit of 100. If not specified then it will default to the page limit size.
         */
        Optional<int32_t> recordCount;
        /**
         * Return items with an itemDate within this date range. Both from and to date times are
         * inclusive. If from is not specified then the oldest available items will be in range. If
         * to is not specified then the latest items will be in range. nb. This itemDataRange is
         * currently only applied when includeItem is set to ALL or not specified, else items are
         * NOT bound by itemDate.
         */
        TimeRange itemDateRange;
        /**
         * Which items to include, if not specified then defaults to ALL.
         */
        IncludeItem includeItem;
        /**
         * Which wallet to return statementItems for. If unspecified then the UK wallet will be
         * selected
         */
        Wallet wallet;
};

}

#endif // GETACCOUNTSTATEMENTREQUEST_H
