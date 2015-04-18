/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTMARKETPROFITANDLOSSREQUEST_H
#define LISTMARKETPROFITANDLOSSREQUEST_H

#include <json/json.h>
#include <set>
#include <string>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonRequest.h"

namespace greentop {

class ListMarketProfitAndLossRequest : public JsonRequest {
    public:
        ListMarketProfitAndLossRequest();

        ListMarketProfitAndLossRequest(const std::set<std::string>& marketIds,
            const BoolJsonMember& includeSettledBets = BoolJsonMember(),
            const BoolJsonMember& includeBspBets = BoolJsonMember(),
            const BoolJsonMember& netOfCommission = BoolJsonMember());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::set<std::string>& getMarketIds() const;
        void setMarketIds(const std::set<std::string>& marketIds);

        const BoolJsonMember& getIncludeSettledBets() const;
        void setIncludeSettledBets(const BoolJsonMember& includeSettledBets);

        const BoolJsonMember& getIncludeBspBets() const;
        void setIncludeBspBets(const BoolJsonMember& includeBspBets);

        const BoolJsonMember& getNetOfCommission() const;
        void setNetOfCommission(const BoolJsonMember& netOfCommission);


    private:
        std::set<std::string> marketIds;
        BoolJsonMember includeSettledBets;
        BoolJsonMember includeBspBets;
        BoolJsonMember netOfCommission;
};

}

#endif // LISTMARKETPROFITANDLOSSREQUEST_H


