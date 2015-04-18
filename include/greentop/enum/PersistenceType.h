/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PERSISTENCETYPE_H
#define PERSISTENCETYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class PersistenceType : public Enum<PersistenceType> {

    public:

        static const std::string LAPSE;
        static const std::string PERSIST;
        static const std::string MARKET_ON_CLOSE;

        PersistenceType();

        PersistenceType(const std::string& v);

        bool operator<(const PersistenceType& other) const;

        bool operator==(const PersistenceType& other) const;
};

}

#endif // PERSISTENCETYPE_H
