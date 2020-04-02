/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETONCLOSEORDER_H
#define SPORT_MARKETONCLOSEORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {
/**
 * Place a new MARKET_ON_CLOSE bet
 */
class MarketOnCloseOrder : public JsonMember {
    public:
        MarketOnCloseOrder();

        MarketOnCloseOrder(const Optional<double>& liability);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getLiability() const;
        void setLiability(const Optional<double>& liability);


    private:
        /**
         * The size of the bet.
         */
        Optional<double> liability;
};

}
}

#endif // SPORT_MARKETONCLOSEORDER_H
