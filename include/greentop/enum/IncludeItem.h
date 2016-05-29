/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef INCLUDEITEM_H
#define INCLUDEITEM_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class IncludeItem : public Enum<IncludeItem> {

    public:

        static const std::string ALL;
        static const std::string DEPOSITS_WITHDRAWALS;
        static const std::string EXCHANGE;
        static const std::string POKER_ROOM;

        IncludeItem();

        IncludeItem(const std::string& v);

        bool operator<(const IncludeItem& other) const;

        bool operator==(const IncludeItem& other) const;

		bool operator!=(const IncludeItem& other) const;
};

}

#endif // INCLUDEITEM_H
