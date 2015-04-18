/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETACCOUNTSTATEMENTREQUEST_H
#define GETACCOUNTSTATEMENTREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/betting/TimeRange.h"
#include "greentop/enum/IncludeItem.h"
#include "greentop/enum/Wallet.h"

namespace greentop {

class GetAccountStatementRequest : public JsonRequest {
    public:

        GetAccountStatementRequest(const std::string& locale = std::string(),
            const int fromRecord = -1,
            const int recordCount = -1,
            const TimeRange& itemDateRange = TimeRange(),
            const IncludeItem& includeItem = IncludeItem(),
            const Wallet& wallet = Wallet());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);

        const int getFromRecord() const;
        void setFromRecord(const int fromRecord);

        const int getRecordCount() const;
        void setRecordCount(const int recordCount);

        const TimeRange& getItemDateRange() const;
        void setItemDateRange(const TimeRange& itemDateRange);

        const IncludeItem& getIncludeItem() const;
        void setIncludeItem(const IncludeItem& includeItem);

        const Wallet& getWallet() const;
        void setWallet(const Wallet& wallet);


    private:
        std::string locale;
        int fromRecord;
        int recordCount;
        TimeRange itemDateRange;
        IncludeItem includeItem;
        Wallet wallet;
};

}

#endif // GETACCOUNTSTATEMENTREQUEST_H


