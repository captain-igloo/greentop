/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEINSTRUCTION_H
#define PLACEINSTRUCTION_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/betting/LimitOnCloseOrder.h"
#include "greentop/betting/LimitOrder.h"
#include "greentop/betting/MarketOnCloseOrder.h"
#include "greentop/enum/OrderType.h"
#include "greentop/enum/Side.h"

namespace greentop {

class PlaceInstruction : public JsonMember {
    public:
        PlaceInstruction();

        PlaceInstruction(const OrderType& orderType,
            const uint64_t selectionId,
            const Optional<double>& handicap = Optional<double>(),
            const Side& side = Side(),
            const LimitOrder& limitOrder = LimitOrder(),
            const LimitOnCloseOrder& limitOnCloseOrder = LimitOnCloseOrder(),
            const MarketOnCloseOrder& marketOnCloseOrder = MarketOnCloseOrder());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

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


    private:
        OrderType orderType;
        uint64_t selectionId;
        Optional<double> handicap;
        Side side;
        LimitOrder limitOrder;
        LimitOnCloseOrder limitOnCloseOrder;
        MarketOnCloseOrder marketOnCloseOrder;
};

}

#endif // PLACEINSTRUCTION_H


