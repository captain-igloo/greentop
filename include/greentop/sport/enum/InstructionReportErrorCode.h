/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef INSTRUCTIONREPORTERRORCODE_H
#define INSTRUCTIONREPORTERRORCODE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class InstructionReportErrorCode : public Enum<InstructionReportErrorCode> {

    public:

        /** Bet size is invalid for your currency or your regulator */
        static const std::string INVALID_BET_SIZE;
        /** Runner does not exist, includes vacant traps in greyhound racing */
        static const std::string INVALID_RUNNER;
        /** Bet cannot be cancelled or modified as it has already been taken or has lapsed
         Includes attempts to cancel/modify market on close BSP bets and cancelling limit on close BSP bets */
        static const std::string BET_TAKEN_OR_LAPSED;
        /** No result was received from the matcher in a timeout configured for the system */
        static const std::string BET_IN_PROGRESS;
        /** Runner has been removed from the event */
        static const std::string RUNNER_REMOVED;
        /** Attempt to edit a bet on a market that has closed. */
        static const std::string MARKET_NOT_OPEN_FOR_BETTING;
        /** The action has caused the account to exceed the self imposed loss limit */
        static const std::string LOSS_LIMIT_EXCEEDED;
        /** Market now closed to bsp betting. Turned in-play or has been reconciled */
        static const std::string MARKET_NOT_OPEN_FOR_BSP_BETTING;
        /** Attempt to edit down the price of a bsp limit on close lay bet, or edit up the price of a
         limit on close back bet */
        static const std::string INVALID_PRICE_EDIT;
        /** Odds not on price ladder - either edit or placement */
        static const std::string INVALID_ODDS;
        /** Insufficient funds available to cover the bet action. Either the exposure limit or
         available to bet limit would be exceeded */
        static const std::string INSUFFICIENT_FUNDS;
        /** Invalid persistence type for this market, e.g. KEEP for a non bsp market */
        static const std::string INVALID_PERSISTENCE_TYPE;
        /** A problem with the matcher prevented this action completing successfully */
        static const std::string ERROR_IN_MATCHER;
        /** The order contains a back and a lay for the same runner at overlapping prices. This would guarantee
         a self match.
         This also applies to BSP limit on close bets */
        static const std::string INVALID_BACK_LAY_COMBINATION;
        /** The action failed because the parent order failed */
        static const std::string ERROR_IN_ORDER;
        /** Bid type is mandatory */
        static const std::string INVALID_BID_TYPE;
        /** Bet for id supplied has not been found */
        static const std::string INVALID_BET_ID;
        /** Bet cancelled but replacement bet was not placed */
        static const std::string CANCELLED_NOT_PLACED;
        /** Action failed due to the failure of a action on which this action is dependent */
        static const std::string RELATED_ACTION_FAILED;
        /** the action does not result in any state change. eg changing a persistence to it's current
         value */
        static const std::string NO_ACTION_REQUIRED;

        InstructionReportErrorCode();

        InstructionReportErrorCode(const std::string& v);

        bool operator<(const InstructionReportErrorCode& other) const;

        bool operator==(const InstructionReportErrorCode& other) const;

        bool operator!=(const InstructionReportErrorCode& other) const;
};

}

#endif // INSTRUCTIONREPORTERRORCODE_H
