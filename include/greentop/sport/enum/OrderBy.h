/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ORDERBY_H
#define ORDERBY_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class OrderBy : public Enum<OrderBy> {

    public:

        /**
         * @Deprecated Use BY_PLACE_TIME instead. Order by placed time, then bet id.
         */
        static const std::string BY_BET;
        /**
         * Order by market id, then placed time, then bet id.
         */
        static const std::string BY_MARKET;
        /**
         * Order by placed time, then bet id. This is an alias of to be deprecated BY_BET.
         */
        static const std::string BY_PLACE_TIME;
        /**
         * Order by time of last matched fragment (if any), then placed time, then bet id. Filters
         * out orders which have no matched date
         */
        static const std::string BY_MATCH_TIME;
        /**
         * Order by time of last voided fragment (if any), then by last match time, then placed
         * time, then bet id. Filters out orders which have not been voided.
         */
        static const std::string BY_VOID_TIME;
        /**
         * Order by time of last settled fragment (if any), then by last match time, then placed
         * time, then bet id. Filters out orders which have not been settled.
         */
        static const std::string BY_SETTLED_TIME;

        OrderBy();

        OrderBy(const std::string& v);

        bool operator<(const OrderBy& other) const;

        bool operator==(const OrderBy& other) const;

        bool operator!=(const OrderBy& other) const;
};

}

#endif // ORDERBY_H
