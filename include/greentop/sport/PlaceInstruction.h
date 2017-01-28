/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEINSTRUCTION_H
#define PLACEINSTRUCTION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/LimitOnCloseOrder.h"
#include "greentop/sport/LimitOrder.h"
#include "greentop/sport/MarketOnCloseOrder.h"
#include "greentop/sport/enum/OrderType.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {

/**
 * Instruction to place a new order
 */
class PlaceInstruction : public JsonMember {
    public:
        PlaceInstruction();

        PlaceInstruction(const OrderType& orderType,
            const int64_t selectionId,
            const Optional<double>& handicap = Optional<double>(),
            const Side& side = Side(),
            const LimitOrder& limitOrder = LimitOrder(),
            const LimitOnCloseOrder& limitOnCloseOrder = LimitOnCloseOrder(),
            const MarketOnCloseOrder& marketOnCloseOrder = MarketOnCloseOrder(),
            const std::string& customerOrderRef = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const int64_t getSelectionId() const;
        void setSelectionId(const int64_t selectionId);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);

        const Side& getSide() const;
        void setSide(const Side& side);

        const LimitOrder& getLimitOrder() const;
        void setLimitOrder(const LimitOrder& limitOrder);

        const LimitOnCloseOrder& getLimitOnCloseOrder() const;
        void setLimitOnCloseOrder(const LimitOnCloseOrder& limitOnCloseOrder);

        const MarketOnCloseOrder& getMarketOnCloseOrder() const;
        void setMarketOnCloseOrder(const MarketOnCloseOrder& marketOnCloseOrder);

        const std::string& getCustomerOrderRef() const;
        void setCustomerOrderRef(const std::string& customerOrderRef);


    private:
        OrderType orderType;
        /**
         * The selection_id.
         */
        int64_t selectionId;
        /**
         * The handicap applied to the selection, if on an asian-style market.
         */
        Optional<double> handicap;
        /**
         * Back or Lay
         */
        Side side;
        LimitOrder limitOrder;
        LimitOnCloseOrder limitOnCloseOrder;
        MarketOnCloseOrder marketOnCloseOrder;
        /**
         * An optional reference the customer can set to identify instructions and it will be
         * returned on order change messages via the stream API. No validation will be done on
         * uniqueness and the string is limited to 32 characters. If an empty string is provided it
         * will be treated as null.
         */
        std::string customerOrderRef;
};

}

#endif // PLACEINSTRUCTION_H


