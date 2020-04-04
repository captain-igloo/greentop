/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_CLEAREDORDERSUMMARY_H
#define SPORT_CLEAREDORDERSUMMARY_H

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
namespace sport {
/**
 * Summary of a cleared order.
 */
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
            const Optional<double>& sizeCancelled = Optional<double>(),
            const std::string& customerOrderRef = std::string(),
            const std::string& customerStrategyRef = std::string());

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

        const std::string& getCustomerOrderRef() const;
        void setCustomerOrderRef(const std::string& customerOrderRef);

        const std::string& getCustomerStrategyRef() const;
        void setCustomerStrategyRef(const std::string& customerStrategyRef);


    private:
        /**
         * The id of the event type bet on. Available at EVENT_TYPE groupBy level or lower.
         */
        std::string eventTypeId;
        /**
         * The id of the event bet on. Available at EVENT groupBy level or lower.
         */
        std::string eventId;
        /**
         * The id of the market bet on. Available at MARKET groupBy level or lower.
         */
        std::string marketId;
        /**
         * The id of the selection bet on. Available at RUNNER groupBy level or lower.
         */
        Optional<int64_t> selectionId;
        /**
         * The id of the market bet on. Available at MARKET groupBy level or lower.
         */
        Optional<double> handicap;
        /**
         * The id of the bet. Available at BET groupBy level.
         */
        std::string betId;
        /**
         * The date the bet order was placed by the customer. Only available at BET groupBy level.
         */
        std::tm placedDate;
        /**
         * The turn in play persistence state of the order at bet placement time. This field will
         * be empty or omitted on true SP bets. Only available at BET groupBy level.
         */
        PersistenceType persistenceType;
        /**
         * The type of bet (e.g standard limited-liability Exchange bet (LIMIT), a standard BSP bet
         * (MARKET_ON_CLOSE), or a minimum-accepted-price BSP bet (LIMIT_ON_CLOSE)). If the bet has
         * a OrderType of MARKET_ON_CLOSE and a persistenceType of MARKET_ON_CLOSE then it is a bet
         * which has transitioned from LIMIT to MARKET_ON_CLOSE. Only available at BET groupBy
         * level.
         */
        OrderType orderType;
        /**
         * Whether the bet was a back or lay bet. Available at SIDE groupBy level or lower.
         */
        Side side;
        /**
         * A container for all the anciliary data and localised text valid for this Item
         */
        ItemDescription itemDescription;
        /**
         * The settlement outcome of the bet. Tri-state (WIN/LOSE/PLACE) to account for Each Way
         * bets where the place portion of the bet won but the win portion lost. The profit/loss
         * amount in this case could be positive or negative depending on the price matched at.
         * Only available at BET groupBy level.
         */
        std::string betOutcome;
        /**
         * The average requested price across all settled bet orders under this Item. Available at
         * SIDE groupBy level or lower. For Line markets this is the line position requested.
         */
        Optional<double> priceRequested;
        /**
         * The date and time the bet order was settled by Betfair. Available at SIDE groupBy level
         * or lower.
         */
        std::tm settledDate;
        /**
         * The date and time the last bet order was matched by Betfair. Available on Settled orders
         * only.
         */
        std::tm lastMatchedDate;
        /**
         * The number of actual bets within this grouping (will be 1 for BET groupBy)
         */
        Optional<int32_t> betCount;
        /**
         * The cumulative amount of commission paid by the customer across all bets under this
         * Item, in the account currency. Available at EXCHANGE, EVENT_TYPE, EVENT and MARKET level
         * groupings only.
         */
        Optional<double> commission;
        /**
         * The average matched price across all settled bets or bet fragments under this Item.
         * Available at SIDE groupBy level or lower. This value is not meaningful for activity on
         * LINE markets and is not guaranteed to be returned or maintained for these markets.
         */
        Optional<double> priceMatched;
        /**
         * If true, then the matched price was affected by a reduction factor due to of a runner
         * removal from this Horse Racing market.
         */
        Optional<bool> priceReduced;
        /**
         * The cumulative bet size that was settled as matched or voided under this Item, in the
         * account currency. Available at SIDE groupBy level or lower.
         */
        Optional<double> sizeSettled;
        /**
         * The profit or loss (negative profit) gained on this line, in the account currency
         */
        Optional<double> profit;
        /**
         * The amount of the bet that was available to be matched, before cancellation or lapsing,
         * in the account currency
         */
        Optional<double> sizeCancelled;
        /**
         * The order reference defined by the customer for the bet order
         */
        std::string customerOrderRef;
        /**
         * The strategy reference defined by the customer for the bet order
         */
        std::string customerStrategyRef;
};

}
}

#endif // SPORT_CLEAREDORDERSUMMARY_H
