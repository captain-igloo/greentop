/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_EXECUTIONREPORTSTATUS_H
#define SPORT_ENUM_EXECUTIONREPORTSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class ExecutionReportStatus : public Enum<ExecutionReportStatus> {

    public:


        static const std::string SUCCESS;

        static const std::string FAILURE;

        static const std::string PROCESSED_WITH_ERRORS;

        static const std::string TIMEOUT;

        ExecutionReportStatus();

        ExecutionReportStatus(const std::string& v);

        bool operator<(const ExecutionReportStatus& other) const;

        bool operator==(const ExecutionReportStatus& other) const;

        bool operator!=(const ExecutionReportStatus& other) const;
};

}
}

#endif // SPORT_ENUM_EXECUTIONREPORTSTATUS_H
