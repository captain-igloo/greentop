/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GROUPBY_H
#define GROUPBY_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class GroupBy : public Enum<GroupBy> {

    public:

        /** A roll up of settled P&L, commission paid and number of bet orders, on a specified
         event type */
        static const std::string EVENT_TYPE;
        /** A roll up of settled P&L, commission paid and number of bet orders, on a specified
         event */
        static const std::string EVENT;
        /** A roll up of settled P&L, commission paid and number of bet orders, on a specified
         market */
        static const std::string MARKET;
        /** A roll up of settled P&L and the number of bet orders, on a specified runner within a
         specified market */
        static const std::string RUNNER;
        /** An averaged roll up of settled P&L, and number of bets, on the specified side of a
         specified selection within a specified market, that are either settled or voided */
        static const std::string SIDE;
        /** The P&L, commission paid, side and regulatory information etc, about each individual
         bet order */
        static const std::string BET;
        /** A roll up of settled P&L and the number of bet orders, on a specified strategy across
         the Betfair Exchange */
        static const std::string STRATEGY;

        GroupBy();

        GroupBy(const std::string& v);

        bool operator<(const GroupBy& other) const;

        bool operator==(const GroupBy& other) const;

        bool operator!=(const GroupBy& other) const;
};

}

#endif // GROUPBY_H
