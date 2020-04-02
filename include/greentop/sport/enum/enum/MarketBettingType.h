/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_MARKETBETTINGTYPE_H
#define SPORT_ENUM_MARKETBETTINGTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class MarketBettingType : public Enum<MarketBettingType> {

    public:

        /**
         * Odds Market
         */
        static const std::string ODDS;
        /**
         * Line markets operate at even-money odds of 2.0. However, price for these markets refers
         * to the line positions available as defined by the markets min-max range and interval
         * steps. Customers either Buy a line (LAY bet, winning if outcome is greater than the
         * taken line (price)) or Sell a line (BACK bet, winning if outcome is less than the taken
         * line (price)). If settled outcome equals the taken line, stake is returned.
         */
        static const std::string LINE;
        /**
         * Range Market
         */
        static const std::string RANGE;
        /**
         * Asian Handicap Market
         */
        static const std::string ASIAN_HANDICAP_DOUBLE_LINE;
        /**
         * Asian Single Line Market
         */
        static const std::string ASIAN_HANDICAP_SINGLE_LINE;
        /**
         * Sportsbook Odds Market. This type is deprecated and will be removed in future releases,
         * when Sportsbook markets will be represented as ODDS market but with a different product
         * type.
         */
        static const std::string FIXED_ODDS;

        MarketBettingType();

        MarketBettingType(const std::string& v);

        bool operator<(const MarketBettingType& other) const;

        bool operator==(const MarketBettingType& other) const;

        bool operator!=(const MarketBettingType& other) const;
};

}
}
}

#endif // SPORT_ENUM_MARKETBETTINGTYPE_H
