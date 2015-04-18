/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXECUTIONREPORTERRORCODE_H
#define EXECUTIONREPORTERRORCODE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class ExecutionReportErrorCode : public Enum<ExecutionReportErrorCode> {

    public:

        static const std::string ERROR_IN_MATCHER;
        static const std::string PROCESSED_WITH_ERRORS;
        static const std::string BET_ACTION_ERROR;
        static const std::string INVALID_ACCOUNT_STATE;
        static const std::string INVALID_WALLET_STATUS;
        static const std::string INSUFFICIENT_FUNDS;
        static const std::string LOSS_LIMIT_EXCEEDED;
        static const std::string MARKET_SUSPENDED;
        static const std::string MARKET_NOT_OPEN_FOR_BETTING;
        static const std::string DUPLICATE_TRANSACTION;
        static const std::string INVALID_ORDER;
        static const std::string INVALID_MARKET_ID;
        static const std::string PERMISSION_DENIED;
        static const std::string DUPLICATE_BETIDS;
        static const std::string NO_ACTION_REQUIRED;
        static const std::string SERVICE_UNAVAILABLE;
        static const std::string REJECTED_BY_REGULATOR;

        ExecutionReportErrorCode();

        ExecutionReportErrorCode(const std::string& v);

        bool operator<(const ExecutionReportErrorCode& other) const;

        bool operator==(const ExecutionReportErrorCode& other) const;
};

}

#endif // EXECUTIONREPORTERRORCODE_H
