/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETPROJECTION_H
#define MARKETPROJECTION_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketProjection : public Enum<MarketProjection> {

    public:

        static const std::string COMPETITION;
        static const std::string EVENT;
        static const std::string EVENT_TYPE;
        static const std::string MARKET_START_TIME;
        static const std::string MARKET_DESCRIPTION;
        static const std::string RUNNER_DESCRIPTION;
        static const std::string RUNNER_METADATA;

        MarketProjection();

        MarketProjection(const std::string& v);

        bool operator<(const MarketProjection& other) const;

        bool operator==(const MarketProjection& other) const;

		bool operator!=(const MarketProjection& other) const;
};

}

#endif // MARKETPROJECTION_H
