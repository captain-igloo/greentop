/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
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
        std::string locale;
        Optional<int32_t> fromRecord;
        Optional<int32_t> recordCount;
        TimeRange itemDateRange;
        IncludeItem includeItem;
        Wallet wallet;
};

}

#endif // GETACCOUNTSTATEMENTREQUEST_H


