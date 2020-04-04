/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_MARKETSORT_H
#define SPORT_ENUM_MARKETSORT_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class MarketSort : public Enum<MarketSort> {

    public:

        /**
         * Minimum traded volume
         */
        static const std::string MINIMUM_TRADED;
        /**
         * Maximum traded volume
         */
        static const std::string MAXIMUM_TRADED;
        /**
         * Minimum available to match
         */
        static const std::string MINIMUM_AVAILABLE;
        /**
         * Maximum available to match
         */
        static const std::string MAXIMUM_AVAILABLE;
        /**
         * The closest markets based on their expected start time
         */
        static const std::string FIRST_TO_START;
        /**
         * The most distant markets based on their expected start time
         */
        static const std::string LAST_TO_START;

        MarketSort();

        MarketSort(const std::string& v);

        bool operator<(const MarketSort& other) const;

        bool operator==(const MarketSort& other) const;

        bool operator!=(const MarketSort& other) const;
};

}
}

#endif // SPORT_ENUM_MARKETSORT_H
