/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_TIMEINFORCE_H
#define SPORT_ENUM_TIMEINFORCE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class TimeInForce : public Enum<TimeInForce> {

    public:

        /**
         * Execute the transaction immediately and completely (filled to size or between
         * minFillSize and size) or not at all (cancelled). For LINE markets Volume Weighted
         * Average Price (VWAP) functionality is disabled.
         */
        static const std::string FILL_OR_KILL;

        TimeInForce();

        TimeInForce(const std::string& v);

        bool operator<(const TimeInForce& other) const;

        bool operator==(const TimeInForce& other) const;

        bool operator!=(const TimeInForce& other) const;
};

}
}
}

#endif // SPORT_ENUM_TIMEINFORCE_H
