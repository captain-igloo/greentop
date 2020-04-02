/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_BETTARGETTYPE_H
#define SPORT_ENUM_BETTARGETTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class BetTargetType : public Enum<BetTargetType> {

    public:

        /**
         * The total payout requested on a LimitOrder. BetTargetType bets are invalid for LINE
         * markets.
         */
        static const std::string PAYOUT;
        /**
         * The payout requested minus the calculated size at which this LimitOrder is to be placed.
         * BetTargetType bets are invalid for LINE markets.
         */
        static const std::string BACKERS_PROFIT;

        BetTargetType();

        BetTargetType(const std::string& v);

        bool operator<(const BetTargetType& other) const;

        bool operator==(const BetTargetType& other) const;

        bool operator!=(const BetTargetType& other) const;
};

}
}
}

#endif // SPORT_ENUM_BETTARGETTYPE_H
