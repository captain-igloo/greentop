/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TIMEINFORCE_H
#define TIMEINFORCE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class TimeInForce : public Enum<TimeInForce> {

    public:

        /** Execute the transaction immediately and completely (filled to size or between minFillSize and size) or not at all (cancelled) */
        static const std::string FILL_OR_KILL;

        TimeInForce();

        TimeInForce(const std::string& v);

        bool operator<(const TimeInForce& other) const;

        bool operator==(const TimeInForce& other) const;

        bool operator!=(const TimeInForce& other) const;
};

}

#endif // TIMEINFORCE_H
