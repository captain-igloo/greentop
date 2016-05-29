/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ITEMCLASS_H
#define ITEMCLASS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class ItemClass : public Enum<ItemClass> {

    public:

        static const std::string UNKNOWN;

        ItemClass();

        ItemClass(const std::string& v);

        bool operator<(const ItemClass& other) const;

        bool operator==(const ItemClass& other) const;

		bool operator!=(const ItemClass& other) const;
};

}

#endif // ITEMCLASS_H
