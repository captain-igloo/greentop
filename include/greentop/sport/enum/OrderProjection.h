/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERPROJECTION_H
#define ORDERPROJECTION_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderProjection : public Enum<OrderProjection> {

    public:


        static const std::string ALL;

        static const std::string EXECUTABLE;

        static const std::string EXECUTION_COMPLETE;

        OrderProjection();

        OrderProjection(const std::string& v);

        bool operator<(const OrderProjection& other) const;

        bool operator==(const OrderProjection& other) const;

        bool operator!=(const OrderProjection& other) const;
};

}

#endif // ORDERPROJECTION_H
