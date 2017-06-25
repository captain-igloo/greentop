/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef INSTRUCTIONREPORTSTATUS_H
#define INSTRUCTIONREPORTSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

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

#endif // INSTRUCTIONREPORTSTATUS_H
