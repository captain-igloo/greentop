/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_MARKETPROJECTION_H
#define SPORT_ENUM_MARKETPROJECTION_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class MarketProjection : public Enum<MarketProjection> {

    public:

        /**
         * If not selected then the competition will not be returned with marketCatalogue
         */
        static const std::string COMPETITION;
        /**
         * If not selected then the event will not be returned with marketCatalogue
         */
        static const std::string EVENT;
        /**
         * If not selected then the eventType will not be returned with marketCatalogue
         */
        static const std::string EVENT_TYPE;
        /**
         * If not selected then the start time will not be returned with marketCatalogue
         */
        static const std::string MARKET_START_TIME;
        /**
         * If not selected then the description will not be returned with marketCatalogue
         */
        static const std::string MARKET_DESCRIPTION;
        /**
         * If not selected then the runners will not be returned with marketCatalogue
         */
        static const std::string RUNNER_DESCRIPTION;
        /**
         * If not selected then the runner metadata will not be returned with marketCatalogue. If
         * selected then RUNNER_DESCRIPTION will also be returned regardless of whether it is
         * included as a market projection.
         */
        static const std::string RUNNER_METADATA;

        MarketProjection();

        MarketProjection(const std::string& v);

        bool operator<(const MarketProjection& other) const;

        bool operator==(const MarketProjection& other) const;

        bool operator!=(const MarketProjection& other) const;
};

}
}

#endif // SPORT_ENUM_MARKETPROJECTION_H
