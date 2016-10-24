/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/enum/OrderType.h"
#include "greentop/sport/enum/PersistenceType.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {

class Order : public JsonMember {
    public:
        Order();

        Order(const std::string& betId,
            const OrderType& orderType,
            const std::string& status,
            const PersistenceType& persistenceType,
            const Side& side,
            const double price,
            const double size,
            const double bspLiability,
            const std::tm& placedDate,
            const Optional<double>& avgPriceMatched = Optional<double>(),
            const Optional<double>& sizeMatched = Optional<double>(),
            const Optional<double>& sizeRemaining = Optional<double>(),
            const Optional<double>& sizeLapsed = Optional<double>(),
            const Optional<double>& sizeCancelled = Optional<double>(),
            const Optional<double>& sizeVoided = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const OrderType& getOrderType() const;
        void setOrderType(const OrderType& orderType);

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);

        const Side& getSide() const;
        void setSide(const Side& side);

        const double getPrice() const;
        void setPrice(const double price);

        const double getSize() const;
        void setSize(const double size);

        const double getBspLiability() const;
        void setBspLiability(const double bspLiability);

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
        std::string status;
        /**
         * What to do with the order at turn-in-play
         */
        PersistenceType persistenceType;
        Side side;
        /**
         * The price of the bet.
         */
        double price;
        /**
         * The size of the bet.
         */
        double size;
        /**
         * Not to be confused with size. This is the liability of a given BSP bet.
         */
        double bspLiability;
        /**
         * The date, to the second, the bet was placed.
         */
        std::tm placedDate;
        /**
         * The average price matched at. Voided match fragments are removed from this average
         * calculation.
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
};

}

#endif // ORDER_H


