/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_PERSISTENCETYPE_H
#define SPORT_ENUM_PERSISTENCETYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class PersistenceType : public Enum<PersistenceType> {

    public:

        /**
         * Lapse the order at turn-in-play
         */
        static const std::string LAPSE;
        /**
         * Persist the order to in-play
         */
        static const std::string PERSIST;
        /**
         * Put the order into the auction (SP) at turn-in-play
         */
        static const std::string MARKET_ON_CLOSE;

        PersistenceType();

        PersistenceType(const std::string& v);

        bool operator<(const PersistenceType& other) const;

        bool operator==(const PersistenceType& other) const;

        bool operator!=(const PersistenceType& other) const;
};

}
}
}

#endif // SPORT_ENUM_PERSISTENCETYPE_H
