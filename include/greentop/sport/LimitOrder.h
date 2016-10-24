/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LIMITORDER_H
#define LIMITORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/enum/PersistenceType.h"

namespace greentop {

/**
 * Place a new LIMIT order (simple exchange bet for immediate execution)
 */
class LimitOrder : public JsonMember {
    public:
        LimitOrder();

        LimitOrder(const double size,
            const double price,
            const PersistenceType& persistenceType);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getSize() const;
        void setSize(const double size);

        const double getPrice() const;
        void setPrice(const double price);

        const PersistenceType& getPersistenceType() const;
        void setPersistenceType(const PersistenceType& persistenceType);


    private:
        /**
         * The size of the bet.
         */
        double size;
        /**
         * The limit price
         */
        double price;
        /**
         * What to do with the order at turn-in-play
         */
        PersistenceType persistenceType;
};

}

#endif // LIMITORDER_H


