/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PERSISTENCETYPE_H
#define PERSISTENCETYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class PersistenceType : public Enum<PersistenceType> {

    public:

        /** Lapse the order at turn-in-play */
        static const std::string LAPSE;
        /** Persist the order to in-play */
        static const std::string PERSIST;
        /** Put the order into the auction (SP) at turn-in-play */
        static const std::string MARKET_ON_CLOSE;

        PersistenceType();

        PersistenceType(const std::string& v);

        bool operator<(const PersistenceType& other) const;

        bool operator==(const PersistenceType& other) const;

        bool operator!=(const PersistenceType& other) const;
};

}

#endif // PERSISTENCETYPE_H
