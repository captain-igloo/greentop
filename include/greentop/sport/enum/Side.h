/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SIDE_H
#define SIDE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class Side : public Enum<Side> {

    public:

        /** To back a team, horse or outcome is to bet on the selection to win. */
        static const std::string BACK;
        /** To lay a team, horse, or outcome is to bet on the selection to lose. */
        static const std::string LAY;

        Side();

        Side(const std::string& v);

        bool operator<(const Side& other) const;

        bool operator==(const Side& other) const;

        bool operator!=(const Side& other) const;
};

}

#endif // SIDE_H
