/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SIDE_H
#define SIDE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class Side : public Enum<Side> {

    public:

        static const std::string BACK;
        static const std::string LAY;

        Side();

        Side(const std::string& v);

        bool operator<(const Side& other) const;

        bool operator==(const Side& other) const;

		bool operator!=(const Side& other) const;
};

}

#endif // SIDE_H
