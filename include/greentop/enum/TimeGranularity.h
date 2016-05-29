/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TIMEGRANULARITY_H
#define TIMEGRANULARITY_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class TimeGranularity : public Enum<TimeGranularity> {

    public:

        static const std::string DAYS;
        static const std::string HOURS;
        static const std::string MINUTES;

        TimeGranularity();

        TimeGranularity(const std::string& v);

        bool operator<(const TimeGranularity& other) const;

        bool operator==(const TimeGranularity& other) const;

		bool operator!=(const TimeGranularity& other) const;
};

}

#endif // TIMEGRANULARITY_H
