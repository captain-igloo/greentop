/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef BETTARGETTYPE_H
#define BETTARGETTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class BetTargetType : public Enum<BetTargetType> {

    public:

        /** The total payout requested on a LimitOrder */
        static const std::string PAYOUT;
        /** The payout requested minus the calculated size at which this LimitOrder is to be placed */
        static const std::string BACKERS_PROFIT;

        BetTargetType();

        BetTargetType(const std::string& v);

        bool operator<(const BetTargetType& other) const;

        bool operator==(const BetTargetType& other) const;

        bool operator!=(const BetTargetType& other) const;
};

}

#endif // BETTARGETTYPE_H
