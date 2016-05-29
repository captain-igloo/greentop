/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACTIONPERFORMED_H
#define ACTIONPERFORMED_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class ActionPerformed : public Enum<ActionPerformed> {

    public:

        static const std::string NONE;
        static const std::string CANCELLATION_REQUEST_SUBMITTED;
        static const std::string ALL_BETS_CANCELLED;
        static const std::string SOME_BETS_NOT_CANCELLED;
        static const std::string CANCELLATION_REQUEST_ERROR;
        static const std::string CANCELLATION_STATUS_UNKNOWN;

        ActionPerformed();

        ActionPerformed(const std::string& v);

        bool operator<(const ActionPerformed& other) const;

        bool operator==(const ActionPerformed& other) const;

		bool operator!=(const ActionPerformed& other) const;
};

}

#endif // ACTIONPERFORMED_H
