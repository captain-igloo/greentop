/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef BETSTATUS_H
#define BETSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class BetStatus : public Enum<BetStatus> {

    public:

        static const std::string SETTLED;
        static const std::string VOIDED;
        static const std::string LAPSED;
        static const std::string CANCELLED;

        BetStatus();

        BetStatus(const std::string& v);

        bool operator<(const BetStatus& other) const;

        bool operator==(const BetStatus& other) const;

		bool operator!=(const BetStatus& other) const;
};

}

#endif // BETSTATUS_H
