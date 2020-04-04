/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_INSTRUCTIONREPORTSTATUS_H
#define SPORT_ENUM_INSTRUCTIONREPORTSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class InstructionReportStatus : public Enum<InstructionReportStatus> {

    public:


        static const std::string SUCCESS;

        static const std::string FAILURE;

        static const std::string TIMEOUT;

        InstructionReportStatus();

        InstructionReportStatus(const std::string& v);

        bool operator<(const InstructionReportStatus& other) const;

        bool operator==(const InstructionReportStatus& other) const;

        bool operator!=(const InstructionReportStatus& other) const;
};

}
}

#endif // SPORT_ENUM_INSTRUCTIONREPORTSTATUS_H
