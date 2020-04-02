/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_MATCHPROJECTION_H
#define SPORT_ENUM_MATCHPROJECTION_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class MatchProjection : public Enum<MatchProjection> {

    public:


        static const std::string NO_ROLLUP;

        static const std::string ROLLED_UP_BY_PRICE;

        static const std::string ROLLED_UP_BY_AVG_PRICE;

        MatchProjection();

        MatchProjection(const std::string& v);

        bool operator<(const MatchProjection& other) const;

        bool operator==(const MatchProjection& other) const;

        bool operator!=(const MatchProjection& other) const;
};

}
}

#endif // SPORT_ENUM_MATCHPROJECTION_H
