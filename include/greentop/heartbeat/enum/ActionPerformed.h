/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACTIONPERFORMED_H
#define ACTIONPERFORMED_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class ActionPerformed : public Enum<ActionPerformed> {

    public:

        /** No action was performed since last heartbeat, or this is the first heartbeat */
        static const std::string NONE;
        /** A request to cancel all unmatched bets was submitted since last heartbeat */
        static const std::string CANCELLATION_REQUEST_SUBMITTED;
        /** All unmatched bets were cancelled since last heartbeat */
        static const std::string ALL_BETS_CANCELLED;
        /** Not all unmatched bets were cancelled since last heartbeat */
        static const std::string SOME_BETS_NOT_CANCELLED;
        /** There was an error requesting cancellation, no bets have been cancelled */
        static const std::string CANCELLATION_REQUEST_ERROR;
        /** There was no response from requesting cancellation, cancellation status unknown */
        static const std::string CANCELLATION_STATUS_UNKNOWN;

        ActionPerformed();

        ActionPerformed(const std::string& v);

        bool operator<(const ActionPerformed& other) const;

        bool operator==(const ActionPerformed& other) const;

        bool operator!=(const ActionPerformed& other) const;
};

}

#endif // ACTIONPERFORMED_H
