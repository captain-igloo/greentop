/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_MARKETSTATUS_H
#define SPORT_ENUM_MARKETSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class MarketStatus : public Enum<MarketStatus> {

    public:

        /**
         * Inactive Market
         */
        static const std::string INACTIVE;
        /**
         * Open Market
         */
        static const std::string OPEN;
        /**
         * Suspended Market
         */
        static const std::string SUSPENDED;
        /**
         * Closed Market
         */
        static const std::string CLOSED;

        MarketStatus();

        MarketStatus(const std::string& v);

        bool operator<(const MarketStatus& other) const;

        bool operator==(const MarketStatus& other) const;

        bool operator!=(const MarketStatus& other) const;
};

}
}
}

#endif // SPORT_ENUM_MARKETSTATUS_H
