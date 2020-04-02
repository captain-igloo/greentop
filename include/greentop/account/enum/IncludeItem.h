/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_INCLUDEITEM_H
#define ACCOUNT_ENUM_INCLUDEITEM_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class IncludeItem : public Enum<IncludeItem> {

    public:


        static const std::string ALL;

        static const std::string EXCHANGE;

        static const std::string POKER_ROOM;

        static const std::string DEPOSITS_WITHDRAWALS;

        IncludeItem();

        IncludeItem(const std::string& v);

        bool operator<(const IncludeItem& other) const;

        bool operator==(const IncludeItem& other) const;

        bool operator!=(const IncludeItem& other) const;
};

}
}

#endif // ACCOUNT_ENUM_INCLUDEITEM_H
