/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETRATES_H
#define SPORT_MARKETRATES_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {
/**
 * Market Rates
 */
class MarketRates : public JsonMember {
    public:
        MarketRates();

        MarketRates(const Optional<double>& marketBaseRate,
            const Optional<bool>& discountAllowed);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getMarketBaseRate() const;
        void setMarketBaseRate(const Optional<double>& marketBaseRate);

        const Optional<bool>& getDiscountAllowed() const;
        void setDiscountAllowed(const Optional<bool>& discountAllowed);


    private:
        /**
         * marketBaseRate
         */
        Optional<double> marketBaseRate;
        /**
         * discountAllowed
         */
        Optional<bool> discountAllowed;
};

}
}

#endif // SPORT_MARKETRATES_H
