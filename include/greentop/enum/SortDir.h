#ifndef SORTDIR_H
#define SORTDIR_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class SortDir : public Enum<SortDir> {

    public:

        static const std::string EARLIEST_TO_LATEST;
        static const std::string LATEST_TO_EARLIEST;

        SortDir();

        SortDir(const std::string& v);

        bool operator<(const SortDir& other) const;

        bool operator==(const SortDir& other) const;
};

}

#endif // SORTDIR_H
