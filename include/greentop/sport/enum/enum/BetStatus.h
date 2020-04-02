/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_BETSTATUS_H
#define SPORT_ENUM_BETSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class BetStatus : public Enum<BetStatus> {

    public:

        /**
         * A matched bet that was settled normally
         */
        static const std::string SETTLED;
        /**
         * A matched bet that was subsequently voided by Betfair, before, during or after
         * settlement
         */
        static const std::string VOIDED;
        /**
         * Unmatched bet that was cancelled by Betfair (for example at turn in play).
         */
        static const std::string LAPSED;
        /**
         * Unmatched bet that was cancelled by an explicit customer action.
         */
        static const std::string CANCELLED;

        BetStatus();

        BetStatus(const std::string& v);

        bool operator<(const BetStatus& other) const;

        bool operator==(const BetStatus& other) const;

        bool operator!=(const BetStatus& other) const;
};

}
}
}

#endif // SPORT_ENUM_BETSTATUS_H
