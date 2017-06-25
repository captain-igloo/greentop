/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LIMITORDER_H
#define LIMITORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/enum/BetTargetType.h"
#include "greentop/sport/enum/PersistenceType.h"
#include "greentop/sport/enum/TimeInForce.h"

namespace greentop {
/**
 * Place a new LIMIT order (simple exchange bet for immediate execution)
 */
class LimitOrder : public JsonMember {
    public:

        LimitOrder(const Optional<double>& size = Optional<double>(),
            const Optional<double>& price = Optional<double>(),
            const PersistenceType& persistenceType = PersistenceType(),
            const TimeInForce& timeInForce = TimeInForce(),
            const Optional<double>& minFillSize = Optional<double>(),
            const BetTargetType& betTargetType = BetTargetType(),
            const Optional<double>& betTargetSize = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getSize() const;
        void setSize(const Optional<double>& size);

        const Optional<double>& getPrice() const;
        void setPrice(const Optional<double>& price);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);

        const TimeInForce& getTimeInForce() const;
        void setTimeInForce(const TimeInForce& timeInForce);

        const Optional<double>& getMinFillSize() const;
        void setMinFillSize(const Optional<double>& minFillSize);

        const BetTargetType& getBetTargetType() const;
        void setBetTargetType(const BetTargetType& betTargetType);

        const Optional<double>& getBetTargetSize() const;
        void setBetTargetSize(const Optional<double>& betTargetSize);


    private:
        /**
         * The size of the bet. It is illegal to specify size if BetTargetType is specified.
         */
        Optional<double> size;
        /**
         * The limit price. For LINE markets, the price at which the bet is settled and struck will
         * always be 2.0 (Evens). On these bets, the Price field is used to indicate the line value
         * which is being bought or sold.
         */
        Optional<double> price;
        /**
         * What to do with the order at turn-in-play If no PersistenceType and TimeInForce value is
         * specified, a PersistenceType of LAPSE will be used.
         */
        PersistenceType persistenceType;
        /**
         * The type of TimeInForce value to use. This value takes precedence over any
         * PersistenceType value chosen. If this attribute is populated along with the
         * PersistenceType field, then the PersistenceType will be ignored. TimeInForce bets are
         * valid for LINE markets however Volume Weighted Average Price (VWAP) functionality is
         * disabled.
         */
        TimeInForce timeInForce;
        /**
         * An optional field used if the TimeInForce attribute is populated. If specified without
         * TimeInForce then this field is ignored. If no minFillSize is specified, the order is
         * killed unless the entire size can be matched. If minFillSize is specified, the order is
         * killed unless at least the minFillSize can be matched. The minFillSize cannot be greater
         * than the order's size. If specified for a BetTargetType and FILL_OR_KILL order, then
         * this value will be ignored
         */
        Optional<double> minFillSize;
        /**
         * An optional field to allow betting to a targeted PAYOUT or BACKERS_PROFIT. It is illegal
         * to specify both a Size and BetTargetType For line markets, BetTargetType bets are
         * invalid. Matching provides best execution at the requested price or better up to the
         * payout or profit. If the bet is not matched completely and immediately, the remaining
         * portion enters the unmatched pool of bets on the exchange
         */
        BetTargetType betTargetType;
        /**
         * An optional field which must be specified if BetTargetType is specified for this order
         * The requested outcome size of either the payout or profit. This is named from the
         * backer's perspective. For Lay bets the profit represents the bet's liability
         */
        Optional<double> betTargetSize;
};

}

#endif // LIMITORDER_H
