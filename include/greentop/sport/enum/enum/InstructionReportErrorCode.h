/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_INSTRUCTIONREPORTERRORCODE_H
#define SPORT_ENUM_INSTRUCTIONREPORTERRORCODE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class InstructionReportErrorCode : public Enum<InstructionReportErrorCode> {

    public:

        /**
         * Bet size is invalid for your currency or your regulator
         */
        static const std::string INVALID_BET_SIZE;
        /**
         * Runner does not exist, includes vacant traps in greyhound racing
         */
        static const std::string INVALID_RUNNER;
        /**
         * Bet cannot be cancelled or modified as it has already been taken or has lapsed Includes
         * attempts to cancel/modify market on close BSP bets and cancelling limit on close BSP
         * bets
         */
        static const std::string BET_TAKEN_OR_LAPSED;
        /**
         * No result was received from the matcher in a timeout configured for the system
         */
        static const std::string BET_IN_PROGRESS;
        /**
         * Runner has been removed from the event
         */
        static const std::string RUNNER_REMOVED;
        /**
         * Attempt to edit a bet on a market that has closed.
         */
        static const std::string MARKET_NOT_OPEN_FOR_BETTING;
        /**
         * The action has caused the account to exceed the self imposed loss limit
         */
        static const std::string LOSS_LIMIT_EXCEEDED;
        /**
         * Market now closed to bsp betting. Turned in-play or has been reconciled
         */
        static const std::string MARKET_NOT_OPEN_FOR_BSP_BETTING;
        /**
         * Attempt to edit down the price of a bsp limit on close lay bet, or edit up the price of
         * a limit on close back bet
         */
        static const std::string INVALID_PRICE_EDIT;
        /**
         * Odds not on price ladder - either edit or placement
         */
        static const std::string INVALID_ODDS;
        /**
         * Insufficient funds available to cover the bet action. Either the exposure limit or
         * available to bet limit would be exceeded
         */
        static const std::string INSUFFICIENT_FUNDS;
        /**
         * Invalid persistence type for this market, e.g. KEEP for a non bsp market
         */
        static const std::string INVALID_PERSISTENCE_TYPE;
        /**
         * A problem with the matcher prevented this action completing successfully
         */
        static const std::string ERROR_IN_MATCHER;
        /**
         * The order contains a back and a lay for the same runner at overlapping prices. This
         * would guarantee a self match. This also applies to BSP limit on close bets
         */
        static const std::string INVALID_BACK_LAY_COMBINATION;
        /**
         * The action failed because the parent order failed
         */
        static const std::string ERROR_IN_ORDER;
        /**
         * Bid type is mandatory
         */
        static const std::string INVALID_BID_TYPE;
        /**
         * Bet for id supplied has not been found
         */
        static const std::string INVALID_BET_ID;
        /**
         * Bet cancelled but replacement bet was not placed
         */
        static const std::string CANCELLED_NOT_PLACED;
        /**
         * Action failed due to the failure of a action on which this action is dependent
         */
        static const std::string RELATED_ACTION_FAILED;
        /**
         * the action does not result in any state change. eg changing a persistence to it's
         * current value
         */
        static const std::string NO_ACTION_REQUIRED;
        /**
         * The minFillSize must be greater than zero and less than or equal to the order's size.
         * The minFillSize cannot be less than the minimum bet size for your currency
         */
        static const std::string INVALID_MIN_FILL_SIZE;
        /**
         * The supplied customer order reference is too long.
         */
        static const std::string INVALID_CUSTOMER_ORDER_REF;
        /**
         * You may only specify a time in force on either the place request OR on individual limit
         * order instructions (not both), since the implied behaviors are incompatible.
         */
        static const std::string TIME_IN_FORCE_CONFLICT;
        /**
         * You have specified a persistence type for a FILL_OR_KILL order, which is nonsensical
         * because no umatched portion can remain after the order has been placed.
         */
        static const std::string UNEXPECTED_PERSISTENCE_TYPE;
        /**
         * You have specified a time in force of FILL_OR_KILL, but have included a non-LIMIT order
         * type.
         */
        static const std::string INVALID_ORDER_TYPE;
        /**
         * You have specified a minFillSize on a limit order, where the limit order's time in force
         * is not FILL_OR_KILL. Using minFillSize is not supported where the time in force of the
         * request (as opposed to an order) is FILL_OR_KILL.
         */
        static const std::string UNEXPECTED_MIN_FILL_SIZE;
        /**
         * The supplied customer strategy reference is too long.
         */
        static const std::string INVALID_CUSTOMER_STRATEGY_REF;
        /**
         * Your bet is lapsed. There is better odds than requested available in the market, but
         * your preferences don't allow the system to match your bet against better odds. Change
         * your betting preferences to accept better odds if you don't want to receive this error.
         */
        static const std::string BET_LAPSED_PRICE_IMPROVEMENT_TOO_LARGE;

        InstructionReportErrorCode();

        InstructionReportErrorCode(const std::string& v);

        bool operator<(const InstructionReportErrorCode& other) const;

        bool operator==(const InstructionReportErrorCode& other) const;

        bool operator!=(const InstructionReportErrorCode& other) const;
};

}
}
}

#endif // SPORT_ENUM_INSTRUCTIONREPORTERRORCODE_H
