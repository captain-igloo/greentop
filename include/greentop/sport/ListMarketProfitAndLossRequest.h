/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTMARKETPROFITANDLOSSREQUEST_H
#define LISTMARKETPROFITANDLOSSREQUEST_H

#include <json/json.h>
#include <set>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"

namespace greentop {

class ListMarketProfitAndLossRequest : public JsonRequest {
    public:
        ListMarketProfitAndLossRequest();

        ListMarketProfitAndLossRequest(const std::set<std::string>& marketIds,
            const Optional<bool>& includeSettledBets = Optional<bool>(),
            const Optional<bool>& includeBspBets = Optional<bool>(),
            const Optional<bool>& netOfCommission = Optional<bool>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::set<std::string>& getMarketIds() const;
        void setMarketIds(const std::set<std::string>& marketIds);

        const Optional<bool>& getIncludeSettledBets() const;
        void setIncludeSettledBets(const Optional<bool>& includeSettledBets);

        const Optional<bool>& getIncludeBspBets() const;
        void setIncludeBspBets(const Optional<bool>& includeBspBets);

        const Optional<bool>& getNetOfCommission() const;
        void setNetOfCommission(const Optional<bool>& netOfCommission);


    private:
        /**
         * List of markets to calculate profit and loss
         */
        std::set<std::string> marketIds;
        /**
         * Option to include settled bets (partially settled markets only). Defaults to false if
         * not specified.
         */
        Optional<bool> includeSettledBets;
        /**
         * Option to include BSP bets. Defaults to false if not specified.
         */
        Optional<bool> includeBspBets;
        /**
         * Option to return profit and loss net of users current commission rate for this market
         * including any special tariffs. Defaults to false if not specified.
         */
        Optional<bool> netOfCommission;
};

}

#endif // LISTMARKETPROFITANDLOSSREQUEST_H


