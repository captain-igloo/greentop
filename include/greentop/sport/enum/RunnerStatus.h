/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_RUNNERSTATUS_H
#define SPORT_ENUM_RUNNERSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class RunnerStatus : public Enum<RunnerStatus> {

    public:

        /**
         * ACTIVE
         */
        static const std::string ACTIVE;
        /**
         * WINNER
         */
        static const std::string WINNER;
        /**
         * LOSER
         */
        static const std::string LOSER;

        static const std::string REMOVED_VACANT;
        /**
         * REMOVED
         */
        static const std::string REMOVED;
        /**
         * PLACED
         */
        static const std::string PLACED;

        RunnerStatus();

        RunnerStatus(const std::string& v);

        bool operator<(const RunnerStatus& other) const;

        bool operator==(const RunnerStatus& other) const;

        bool operator!=(const RunnerStatus& other) const;
};

}
}

#endif // SPORT_ENUM_RUNNERSTATUS_H
