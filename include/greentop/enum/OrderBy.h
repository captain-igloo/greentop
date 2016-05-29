/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERBY_H
#define ORDERBY_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderBy : public Enum<OrderBy> {

    public:

        static const std::string BY_BET;
        static const std::string BY_MARKET;
        static const std::string BY_MATCH_TIME;
        static const std::string BY_PLACE_TIME;
        static const std::string BY_SETTLED_TIME;
        static const std::string BY_VOID_TIME;

        OrderBy();

        OrderBy(const std::string& v);

        bool operator<(const OrderBy& other) const;

        bool operator==(const OrderBy& other) const;

		bool operator!=(const OrderBy& other) const;
};

}

#endif // ORDERBY_H
