/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETGROUPTYPE_H
#define MARKETGROUPTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketGroupType : public Enum<MarketGroupType> {

    public:

        /**
         * An exchange event that has markets under it. EventId should be used as groupId parameter
         * of MarketGroup type.
         */
        static const std::string EVENT;

        MarketGroupType();

        MarketGroupType(const std::string& v);

        bool operator<(const MarketGroupType& other) const;

        bool operator==(const MarketGroupType& other) const;

        bool operator!=(const MarketGroupType& other) const;
};

}

#endif // MARKETGROUPTYPE_H
