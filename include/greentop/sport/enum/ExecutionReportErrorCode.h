/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_EXECUTIONREPORTERRORCODE_H
#define SPORT_ENUM_EXECUTIONREPORTERRORCODE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class ExecutionReportErrorCode : public Enum<ExecutionReportErrorCode> {

    public:

        /**
         * The matcher's not healthy
         */
        static const std::string ERROR_IN_MATCHER;
        /**
         * The order itself has been accepted, but at least one (possibly all) actions have
         * generated errors
         */
        static const std::string PROCESSED_WITH_ERRORS;
        /**
         * There is an error with an action that has caused the entire order to be rejected
         */
        static const std::string BET_ACTION_ERROR;
        /**
         * Order rejected due to the account's status (suspended, inactive, dup cards)
         */
        static const std::string INVALID_ACCOUNT_STATE;
        /**
         * Order rejected due to the account's wallet's status
         */
        static const std::string INVALID_WALLET_STATUS;
        /**
         * Account has exceeded its exposure limit or available to bet limit
         */
        static const std::string INSUFFICIENT_FUNDS;
        /**
         * The account has exceed the self imposed loss limit
         */
        static const std::string LOSS_LIMIT_EXCEEDED;
        /**
         * Market is suspended
         */
        static const std::string MARKET_SUSPENDED;
        /**
         * Market is not open for betting, either inactive, suspended or closed
         */
        static const std::string MARKET_NOT_OPEN_FOR_BETTING;
        /**
         * duplicate customer referece data submitted
         */
        static const std::string DUPLICATE_TRANSACTION;
        /**
         * Order cannot be accepted by the matcher due to the combination of actions. For example,
         * bets being edited are not on the same market, or order includes both edits and placement
         */
        static const std::string INVALID_ORDER;
        /**
         * Market doesn't exist
         */
        static const std::string INVALID_MARKET_ID;
        /**
         * Business rules do not allow order to be placed
         */
        static const std::string PERMISSION_DENIED;
        /**
         * duplicate bet ids found
         */
        static const std::string DUPLICATE_BETIDS;
        /**
         * Order hasn't been passed to matcher as system detected there will be no state change
         */
        static const std::string NO_ACTION_REQUIRED;
        /**
         * The requested service is unavailable
         */
        static const std::string SERVICE_UNAVAILABLE;
        /**
         * The regulator rejected the order
         */
        static const std::string REJECTED_BY_REGULATOR;
        /**
         * A specific error code that relates to Spanish Exchange markets only which indicates that
         * the bet placed contravenes the Spanish regulatory rules relating to loss chasing.
         */
        static const std::string NO_CHASING;
        /**
         * The underlying regulator service is not available.
         */
        static const std::string REGULATOR_IS_NOT_AVAILABLE;
        /**
         * The amount of orders exceeded the maximum amount allowed to be executed
         */
        static const std::string TOO_MANY_INSTRUCTIONS;
        /**
         * The supplied market version is invalid. Max length allowed for market version is 12.
         */
        static const std::string INVALID_MARKET_VERSION;
        /**
         * Had the instructions been carried out, the account's self imposed event exposure limit
         * would have been exceeded.
         */
        static const std::string EVENT_EXPOSURE_LIMIT_EXCEEDED;
        /**
         * Had the instructions been carried out, the account's self imposed matched event exposure
         * limit would have been exceeded.
         */
        static const std::string EVENT_MATCHED_EXPOSURE_LIMIT_EXCEEDED;
        /**
         * Betting on this event is blocked due to exposure limit breach. unblockMarketGroup
         * operation should be invoked to enable betting.
         */
        static const std::string EVENT_BLOCKED;

        ExecutionReportErrorCode();

        ExecutionReportErrorCode(const std::string& v);

        bool operator<(const ExecutionReportErrorCode& other) const;

        bool operator==(const ExecutionReportErrorCode& other) const;

        bool operator!=(const ExecutionReportErrorCode& other) const;
};

}
}

#endif // SPORT_ENUM_EXECUTIONREPORTERRORCODE_H
