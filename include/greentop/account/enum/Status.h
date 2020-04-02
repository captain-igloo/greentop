/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_STATUS_H
#define ACCOUNT_ENUM_STATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class Status : public Enum<Status> {

    public:

        /**
         * Sucess status
         */
        static const std::string SUCCESS;

        Status();

        Status(const std::string& v);

        bool operator<(const Status& other) const;

        bool operator==(const Status& other) const;

        bool operator!=(const Status& other) const;
};

}
}

#endif // ACCOUNT_ENUM_STATUS_H
