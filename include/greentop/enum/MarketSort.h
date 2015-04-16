#ifndef MARKETSORT_H
#define MARKETSORT_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketSort : public Enum<MarketSort> {

    public:

        static const std::string MINIMUM_TRADED;
        static const std::string MAXIMUM_TRADED;
        static const std::string MINIMUM_AVAILABLE;
        static const std::string MAXIMUM_AVAILABLE;
        static const std::string FIRST_TO_START;
        static const std::string LAST_TO_START;

        MarketSort();

        MarketSort(const std::string& v);

        bool operator<(const MarketSort& other) const;

        bool operator==(const MarketSort& other) const;
};

}

#endif // MARKETSORT_H
