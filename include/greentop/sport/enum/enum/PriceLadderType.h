/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_PRICELADDERTYPE_H
#define SPORT_ENUM_PRICELADDERTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class PriceLadderType : public Enum<PriceLadderType> {

    public:

        /**
         * Price ladder increments traditionally used for Odds Markets.
         */
        static const std::string CLASSIC;
        /**
         * Price ladder with the finest available increment, traditionally used for Asian Handicap
         * markets.
         */
        static const std::string FINEST;
        /**
         * Price ladder used for LINE markets. Refer to MarketLineRangeInfo for more details.
         */
        static const std::string LINE_RANGE;

        PriceLadderType();

        PriceLadderType(const std::string& v);

        bool operator<(const PriceLadderType& other) const;

        bool operator==(const PriceLadderType& other) const;

        bool operator!=(const PriceLadderType& other) const;
};

}
}
}

#endif // SPORT_ENUM_PRICELADDERTYPE_H
