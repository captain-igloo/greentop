/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERTYPE_H
#define ORDERTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderType : public Enum<OrderType> {

    public:

        /** A normal exchange limit order for immediate execution */
        static const std::string LIMIT;
        /** Limit order for the auction (SP) */
        static const std::string LIMIT_ON_CLOSE;
        /** Market order for the auction (SP) */
        static const std::string MARKET_ON_CLOSE;

        OrderType();

        OrderType(const std::string& v);

        bool operator<(const OrderType& other) const;

        bool operator==(const OrderType& other) const;

        bool operator!=(const OrderType& other) const;
};

}

#endif // ORDERTYPE_H
