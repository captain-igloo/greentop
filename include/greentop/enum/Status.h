/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STATUS_H
#define STATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class Status : public Enum<Status> {

    public:

        static const std::string SUCCESS;

        Status();

        Status(const std::string& v);

        bool operator<(const Status& other) const;

        bool operator==(const Status& other) const;

		bool operator!=(const Status& other) const;
};

}

#endif // STATUS_H
