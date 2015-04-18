/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GROUPBY_H
#define GROUPBY_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class GroupBy : public Enum<GroupBy> {

    public:

        static const std::string EVENT_TYPE;
        static const std::string EVENT;
        static const std::string MARKET;
        static const std::string SIDE;
        static const std::string BET;

        GroupBy();

        GroupBy(const std::string& v);

        bool operator<(const GroupBy& other) const;

        bool operator==(const GroupBy& other) const;
};

}

#endif // GROUPBY_H
