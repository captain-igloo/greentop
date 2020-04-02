/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_ORDERTYPE_H
#define SPORT_ENUM_ORDERTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class OrderType : public Enum<OrderType> {

    public:

        /**
         * A normal exchange limit order for immediate execution
         */
        static const std::string LIMIT;
        /**
         * Limit order for the auction (SP)
         */
        static const std::string LIMIT_ON_CLOSE;
        /**
         * Market order for the auction (SP)
         */
        static const std::string MARKET_ON_CLOSE;

        OrderType();

        OrderType(const std::string& v);

        bool operator<(const OrderType& other) const;

        bool operator==(const OrderType& other) const;

        bool operator!=(const OrderType& other) const;
};

}
}
}

#endif // SPORT_ENUM_ORDERTYPE_H
