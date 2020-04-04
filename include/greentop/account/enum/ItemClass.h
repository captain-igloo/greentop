/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_ITEMCLASS_H
#define ACCOUNT_ENUM_ITEMCLASS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class ItemClass : public Enum<ItemClass> {

    public:

        /**
         * Statement item not mapped to a specific class. All values will be concatenated into a
         * single key/value pair. The key will be 'unknownStatementItem' and the value will be a
         * comma separated string.
         */
        static const std::string UNKNOWN;

        ItemClass();

        ItemClass(const std::string& v);

        bool operator<(const ItemClass& other) const;

        bool operator==(const ItemClass& other) const;

        bool operator!=(const ItemClass& other) const;
};

}
}

#endif // ACCOUNT_ENUM_ITEMCLASS_H
