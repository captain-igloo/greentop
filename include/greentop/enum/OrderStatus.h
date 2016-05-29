/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERSTATUS_H
#define ORDERSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderStatus : public Enum<OrderStatus> {

    public:

        static const std::string EXECUTION_COMPLETE;
        static const std::string EXECUTABLE;

        OrderStatus();

        OrderStatus(const std::string& v);

        bool operator<(const OrderStatus& other) const;

        bool operator==(const OrderStatus& other) const;

		bool operator!=(const OrderStatus& other) const;
};

}

#endif // ORDERSTATUS_H
