/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_LIMITBREACHACTIONTYPE_H
#define SPORT_ENUM_LIMITBREACHACTIONTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class LimitBreachActionType : public Enum<LimitBreachActionType> {

    public:

        /**
         * Bet placements for market group will be rejected if they breach limit. For every bet
         * placement exposure values will be compared against limit values.
         */
        static const std::string REJECT_BETS;
        /**
         * Bet placements for market group will be rejected. Once the limit is breached account
         * should use unblockMarketGroup to unlock market group. Note that this type is only
         * applicable to matched exposure limit
         */
        static const std::string STOP_BETTING;
        /**
         * Bet placements for market group will be rejected. Service will initiate a request to
         * cancel unmatched bets under market group. Once the limit is breached account should use
         * unblockMarketGroup to unlock market group. Note that this type is only applicable to
         * matched exposure limit
         */
        static const std::string TEAR_DOWN_MARKET_GROUP;

        LimitBreachActionType();

        LimitBreachActionType(const std::string& v);

        bool operator<(const LimitBreachActionType& other) const;

        bool operator==(const LimitBreachActionType& other) const;

        bool operator!=(const LimitBreachActionType& other) const;
};

}
}
}

#endif // SPORT_ENUM_LIMITBREACHACTIONTYPE_H
