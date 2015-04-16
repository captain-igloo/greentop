#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
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
            const double avgPriceMatched = -1,
            const double sizeMatched = -1,
            const double sizeRemaining = -1,
            const double sizeLapsed = -1,
            const double sizeCancelled = -1,
            const double sizeVoided = -1);

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

        const double getAvgPriceMatched() const;
        void setAvgPriceMatched(const double avgPriceMatched);

        const double getSizeMatched() const;
        void setSizeMatched(const double sizeMatched);

        const double getSizeRemaining() const;
        void setSizeRemaining(const double sizeRemaining);

        const double getSizeLapsed() const;
        void setSizeLapsed(const double sizeLapsed);

        const double getSizeCancelled() const;
        void setSizeCancelled(const double sizeCancelled);

        const double getSizeVoided() const;
        void setSizeVoided(const double sizeVoided);


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
        double avgPriceMatched;
        double sizeMatched;
        double sizeRemaining;
        double sizeLapsed;
        double sizeCancelled;
        double sizeVoided;
};

}

#endif // ORDER_H


