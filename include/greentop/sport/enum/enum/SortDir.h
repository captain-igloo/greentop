/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_SORTDIR_H
#define SPORT_ENUM_SORTDIR_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class SortDir : public Enum<SortDir> {

    public:

        /**
         * Order from earliest value to latest e.g. lowest betId is first in the results.
         */
        static const std::string EARLIEST_TO_LATEST;
        /**
         * Order from the latest value to the earliest e.g. highest betId is first in the results.
         */
        static const std::string LATEST_TO_EARLIEST;

        SortDir();

        SortDir(const std::string& v);

        bool operator<(const SortDir& other) const;

        bool operator==(const SortDir& other) const;

        bool operator!=(const SortDir& other) const;
};

}
}
}

#endif // SPORT_ENUM_SORTDIR_H
