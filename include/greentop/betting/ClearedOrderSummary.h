/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CLEAREDORDERSUMMARY_H
#define CLEAREDORDERSUMMARY_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonMember.h"
#include "greentop/betting/ItemDescription.h"
#include "greentop/enum/OrderType.h"
#include "greentop/enum/PersistenceType.h"
#include "greentop/enum/Side.h"

namespace greentop {

class ClearedOrderSummary : public JsonMember {
    public:

        ClearedOrderSummary(const std::string& eventTypeId = std::string(),
            const std::string& eventId = std::string(),
            const std::string& marketId = std::string(),
            const uint64_t selectionId = 0,
            const double handicap = -1,
            const std::string& betId = std::string(),
            const std::tm& placedDate = std::tm(),
            const PersistenceType& persistenceType = PersistenceType(),
            const OrderType& orderType = OrderType(),
            const Side& side = Side(),
            const ItemDescription& itemDescription = ItemDescription(),
            const double priceRequested = -1,
            const std::tm& settledDate = std::tm(),
            const uint64_t betCount = 0,
            const double commission = -1,
            const double priceMatched = -1,
            const BoolJsonMember& priceReduced = BoolJsonMember(),
            const double sizeSettled = -1,
            const double profit = -1,
            const double sizeCancelled = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getEventTypeId() const;
        void setEventTypeId(const std::string& eventTypeId);

        const std::string& getEventId() const;
        void setEventId(const std::string& eventId);

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const Side& getSide() const;
        void setSide(const Side& side);

        const ItemDescription& getItemDescription() const;
        void setItemDescription(const ItemDescription& itemDescription);

        const double getPriceRequested() const;
        void setPriceRequested(const double priceRequested);

        const std::tm& getSettledDate() const;
        void setSettledDate(const std::tm& settledDate);

        const uint64_t getBetCount() const;
        void setBetCount(const uint64_t betCount);

        const double getCommission() const;
        void setCommission(const double commission);

        const double getPriceMatched() const;
        void setPriceMatched(const double priceMatched);

        const BoolJsonMember& getPriceReduced() const;
        void setPriceReduced(const BoolJsonMember& priceReduced);

        const double getSizeSettled() const;
        void setSizeSettled(const double sizeSettled);

        const double getProfit() const;
        void setProfit(const double profit);

        const double getSizeCancelled() const;
        void setSizeCancelled(const double sizeCancelled);


    private:
        std::string eventTypeId;
        std::string eventId;
        std::string marketId;
        uint64_t selectionId;
        double handicap;
        std::string betId;
        std::tm placedDate;
        PersistenceType persistenceType;
        OrderType orderType;
        Side side;
        ItemDescription itemDescription;
        double priceRequested;
        std::tm settledDate;
        uint64_t betCount;
        double commission;
        double priceMatched;
        BoolJsonMember priceReduced;
        double sizeSettled;
        double profit;
        double sizeCancelled;
};

}

#endif // CLEAREDORDERSUMMARY_H


