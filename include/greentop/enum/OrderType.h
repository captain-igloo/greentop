/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERTYPE_H
#define ORDERTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderType : public Enum<OrderType> {

    public:

        static const std::string LIMIT;
        static const std::string LIMIT_ON_CLOSE;
        static const std::string MARKET_ON_CLOSE;

        OrderType();

        OrderType(const std::string& v);

        bool operator<(const OrderType& other) const;

        bool operator==(const OrderType& other) const;

		bool operator!=(const OrderType& other) const;
};

}

#endif // ORDERTYPE_H
