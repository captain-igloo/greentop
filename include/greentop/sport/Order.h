/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ORDER_H
#define SPORT_ORDER_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/enum/OrderStatus.h"
#include "greentop/sport/enum/OrderType.h"
#include "greentop/sport/enum/PersistenceType.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {
namespace sport {

class Order : public JsonMember {
    public:
        Order();

        Order(const std::string& betId,
            const OrderType& orderType,
            const OrderStatus& status,
            const PersistenceType& persistenceType,
            const Side& side,
            const Optional<double>& price,
            const Optional<double>& size,
            const Optional<double>& bspLiability,
            const std::tm& placedDate,
            const Optional<double>& avgPriceMatched = Optional<double>(),
            const Optional<double>& sizeMatched = Optional<double>(),
            const Optional<double>& sizeRemaining = Optional<double>(),
            const Optional<double>& sizeLapsed = Optional<double>(),
            const Optional<double>& sizeCancelled = Optional<double>(),
            const Optional<double>& sizeVoided = Optional<double>(),
            const std::string& customerOrderRef = std::string(),
            const std::string& customerStrategyRef = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const OrderStatus& getStatus() const;
        void setStatus(const OrderStatus& status);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);

        const Side& getSide() const;
        void setSide(const Side& side);

        const Optional<double>& getPrice() const;
        void setPrice(const Optional<double>& price);

        const Optional<double>& getSize() const;
        void setSize(const Optional<double>& size);

        const Optional<double>& getBspLiability() const;
        void setBspLiability(const Optional<double>& bspLiability);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const Optional<double>& getAvgPriceMatched() const;
        void setAvgPriceMatched(const Optional<double>& avgPriceMatched);

        const Optional<double>& getSizeMatched() const;
        void setSizeMatched(const Optional<double>& sizeMatched);

        const Optional<double>& getSizeRemaining() const;
        void setSizeRemaining(const Optional<double>& sizeRemaining);

        const Optional<double>& getSizeLapsed() const;
        void setSizeLapsed(const Optional<double>& sizeLapsed);

        const Optional<double>& getSizeCancelled() const;
        void setSizeCancelled(const Optional<double>& sizeCancelled);

        const Optional<double>& getSizeVoided() const;
        void setSizeVoided(const Optional<double>& sizeVoided);

        const std::string& getCustomerOrderRef() const;
        void setCustomerOrderRef(const std::string& customerOrderRef);

        const std::string& getCustomerStrategyRef() const;
        void setCustomerStrategyRef(const std::string& customerStrategyRef);


    private:

        std::string betId;
        /**
         * BSP Order type.
         */
        OrderType orderType;
        /**
         * Either EXECUTABLE (an unmatched amount remains) or EXECUTION_COMPLETE (no unmatched
         * amount remains).
         */
        OrderStatus status;
        /**
         * What to do with the order at turn-in-play
         */
        PersistenceType persistenceType;

        Side side;
        /**
         * The price of the bet.
         */
        Optional<double> price;
        /**
         * The size of the bet.
         */
        Optional<double> size;
        /**
         * Not to be confused with size. This is the liability of a given BSP bet.
         */
        Optional<double> bspLiability;
        /**
         * The date, to the second, the bet was placed.
         */
        std::tm placedDate;
        /**
         * The average price matched at. Voided match fragments are removed from this average
         * calculation. This value is not meaningful for activity on LINE markets and is not
         * guaranteed to be returned or maintained for these markets.
         */
        Optional<double> avgPriceMatched;
        /**
         * The current amount of this bet that was matched.
         */
        Optional<double> sizeMatched;
        /**
         * The current amount of this bet that is unmatched.
         */
        Optional<double> sizeRemaining;
        /**
         * The current amount of this bet that was lapsed.
         */
        Optional<double> sizeLapsed;
        /**
         * The current amount of this bet that was cancelled.
         */
        Optional<double> sizeCancelled;
        /**
         * The current amount of this bet that was voided.
         */
        Optional<double> sizeVoided;
        /**
         * The customer order reference sent for this bet
         */
        std::string customerOrderRef;
        /**
         * The customer strategy reference sent for this bet
         */
        std::string customerStrategyRef;
};

}
}

#endif // SPORT_ORDER_H
