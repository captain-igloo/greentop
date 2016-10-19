/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETBETTINGTYPE_H
#define MARKETBETTINGTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketBettingType : public Enum<MarketBettingType> {

    public:

        /** Odds Market */
        static const std::string ODDS;
        /** Line Market */
        static const std::string LINE;
        /** Range Market */
        static const std::string RANGE;
        /** Asian Handicap Market */
        static const std::string ASIAN_HANDICAP_DOUBLE_LINE;
        /** Asian Single Line Market */
        static const std::string ASIAN_HANDICAP_SINGLE_LINE;
        /** Sportsbook Odds Market. This type is deprecated and will be removed
         in future releases, when Sportsbook markets will be represented as ODDS market
         but with a different product type. */
        static const std::string FIXED_ODDS;

        MarketBettingType();

        MarketBettingType(const std::string& v);

        bool operator<(const MarketBettingType& other) const;

        bool operator==(const MarketBettingType& other) const;

        bool operator!=(const MarketBettingType& other) const;
};

}

#endif // MARKETBETTINGTYPE_H
