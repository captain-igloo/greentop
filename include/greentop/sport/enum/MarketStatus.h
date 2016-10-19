/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETSTATUS_H
#define MARKETSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketStatus : public Enum<MarketStatus> {

    public:

        /** Inactive Market */
        static const std::string INACTIVE;
        /** Open Market */
        static const std::string OPEN;
        /** Suspended Market */
        static const std::string SUSPENDED;
        /** Closed Market */
        static const std::string CLOSED;

        MarketStatus();

        MarketStatus(const std::string& v);

        bool operator<(const MarketStatus& other) const;

        bool operator==(const MarketStatus& other) const;

        bool operator!=(const MarketStatus& other) const;
};

}

#endif // MARKETSTATUS_H
