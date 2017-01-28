/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERSTATUS_H
#define ORDERSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderStatus : public Enum<OrderStatus> {

    public:

        /** An asynchronous order is yet to be processed. Once the bet has been processed by the exchange
         (including waiting for any in-play delay), the result will be reported and available on the
         Exchange Stream API and API NG.
         Not a valid search criteria on MarketFilter */
        static const std::string PENDING;
        /** An order that does not have any remaining unmatched portion. */
        static const std::string EXECUTION_COMPLETE;
        /** An order that has a remaining unmatched portion. */
        static const std::string EXECUTABLE;
        /** The order is no longer available for execution due to its time in force constraint.
         In the case of FILL_OR_KILL orders, this means the order has been killed because it could not be filled to your specifications.
         Not a valid search criteria on MarketFilter */
        static const std::string EXPIRED;

        OrderStatus();

        OrderStatus(const std::string& v);

        bool operator<(const OrderStatus& other) const;

        bool operator==(const OrderStatus& other) const;

        bool operator!=(const OrderStatus& other) const;
};

}

#endif // ORDERSTATUS_H
