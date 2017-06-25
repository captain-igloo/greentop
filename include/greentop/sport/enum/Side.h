/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SIDE_H
#define SIDE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class Side : public Enum<Side> {

    public:

        /**
         * To back a team, horse or outcome is to bet on the selection to win. For Line markets a
         * Back bet refers to a SELL line. A SELL line will win if the outcome is LESS THAN the
         * taken line (price).
         */
        static const std::string BACK;
        /**
         * To lay a team, horse, or outcome is to bet on the selection to lose. For line markets a
         * Lay bet refers to a BUY line. A BUY line will win if the outcome is MORE THAN the taken
         * line (price).
         */
        static const std::string LAY;

        Side();

        Side(const std::string& v);

        bool operator<(const Side& other) const;

        bool operator==(const Side& other) const;

        bool operator!=(const Side& other) const;
};

}

#endif // SIDE_H
