/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/enum/OrderStatus.h"
#include "greentop/enum/OrderType.h"
#include "greentop/enum/PersistenceType.h"
#include "greentop/enum/Side.h"

namespace greentop {

class Order : public JsonMember {
    public:
        Order();

        Order(const std::string& betId,
            const OrderType& orderType,
            const OrderStatus& status,
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

        const OrderStatus& getStatus() const;
        void setStatus(const OrderStatus& status);

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
        OrderType orderType;
        OrderStatus status;
        PersistenceType persistenceType;
        Side side;
        double price;
        double size;
        double bspLiability;
        std::tm placedDate;
        Optional<double> avgPriceMatched;
        Optional<double> sizeMatched;
        Optional<double> sizeRemaining;
        Optional<double> sizeLapsed;
        Optional<double> sizeCancelled;
        Optional<double> sizeVoided;
};

}

#endif // ORDER_H


