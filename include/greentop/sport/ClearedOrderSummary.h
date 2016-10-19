/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CLEAREDORDERSUMMARY_H
#define CLEAREDORDERSUMMARY_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/ItemDescription.h"
#include "greentop/sport/enum/OrderType.h"
#include "greentop/sport/enum/PersistenceType.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {

class ClearedOrderSummary : public JsonMember {
    public:

        ClearedOrderSummary(const std::string& eventTypeId = std::string(),
            const std::string& eventId = std::string(),
            const std::string& marketId = std::string(),
            const Optional<int64_t>& selectionId = Optional<int64_t>(),
            const Optional<double>& handicap = Optional<double>(),
            const std::string& betId = std::string(),
            const std::tm& placedDate = std::tm(),
            const PersistenceType& persistenceType = PersistenceType(),
            const OrderType& orderType = OrderType(),
            const Side& side = Side(),
            const ItemDescription& itemDescription = ItemDescription(),
            const std::string& betOutcome = std::string(),
            const Optional<double>& priceRequested = Optional<double>(),
            const std::tm& settledDate = std::tm(),
            const std::tm& lastMatchedDate = std::tm(),
            const Optional<int32_t>& betCount = Optional<int32_t>(),
            const Optional<double>& commission = Optional<double>(),
            const Optional<double>& priceMatched = Optional<double>(),
            const Optional<bool>& priceReduced = Optional<bool>(),
            const Optional<double>& sizeSettled = Optional<double>(),
            const Optional<double>& profit = Optional<double>(),
            const Optional<double>& sizeCancelled = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getEventTypeId() const;
        void setEventTypeId(const std::string& eventTypeId);

        const std::string& getEventId() const;
        void setEventId(const std::string& eventId);

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const Optional<int64_t>& getSelectionId() const;
        void setSelectionId(const Optional<int64_t>& selectionId);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);

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

        const std::string& getBetOutcome() const;
        void setBetOutcome(const std::string& betOutcome);

        const Optional<double>& getPriceRequested() const;
        void setPriceRequested(const Optional<double>& priceRequested);

        const std::tm& getSettledDate() const;
        void setSettledDate(const std::tm& settledDate);

        const std::tm& getLastMatchedDate() const;
        void setLastMatchedDate(const std::tm& lastMatchedDate);

        const Optional<int32_t>& getBetCount() const;
        void setBetCount(const Optional<int32_t>& betCount);

        const Optional<double>& getCommission() const;
        void setCommission(const Optional<double>& commission);

        const Optional<double>& getPriceMatched() const;
        void setPriceMatched(const Optional<double>& priceMatched);

        const Optional<bool>& getPriceReduced() const;
        void setPriceReduced(const Optional<bool>& priceReduced);

        const Optional<double>& getSizeSettled() const;
        void setSizeSettled(const Optional<double>& sizeSettled);

        const Optional<double>& getProfit() const;
        void setProfit(const Optional<double>& profit);

        const Optional<double>& getSizeCancelled() const;
        void setSizeCancelled(const Optional<double>& sizeCancelled);


    private:
        std::string eventTypeId;
        std::string eventId;
        std::string marketId;
        Optional<int64_t> selectionId;
        Optional<double> handicap;
        std::string betId;
        std::tm placedDate;
        PersistenceType persistenceType;
        OrderType orderType;
        Side side;
        ItemDescription itemDescription;
        std::string betOutcome;
        Optional<double> priceRequested;
        std::tm settledDate;
        std::tm lastMatchedDate;
        Optional<int32_t> betCount;
        Optional<double> commission;
        Optional<double> priceMatched;
        Optional<bool> priceReduced;
        Optional<double> sizeSettled;
        Optional<double> profit;
        Optional<double> sizeCancelled;
};

}

#endif // CLEAREDORDERSUMMARY_H


