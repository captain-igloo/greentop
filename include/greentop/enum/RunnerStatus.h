#ifndef RUNNERSTATUS_H
#define RUNNERSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class RunnerStatus : public Enum<RunnerStatus> {

    public:

        static const std::string ACTIVE;
        static const std::string WINNER;
        static const std::string LOSER;
        static const std::string REMOVED_VACANT;
        static const std::string REMOVED;
        static const std::string HIDDEN;

        RunnerStatus();

        RunnerStatus(const std::string& v);

        bool operator<(const RunnerStatus& other) const;

        bool operator==(const RunnerStatus& other) const;
};

}

#endif // RUNNERSTATUS_H
