/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PRICEDATA_H
#define PRICEDATA_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class PriceData : public Enum<PriceData> {

    public:

        static const std::string SP_AVAILABLE;
        static const std::string SP_TRADED;
        static const std::string EX_BEST_OFFERS;
        static const std::string EX_ALL_OFFERS;
        static const std::string EX_TRADED;

        PriceData();

        PriceData(const std::string& v);

        bool operator<(const PriceData& other) const;

        bool operator==(const PriceData& other) const;

		bool operator!=(const PriceData& other) const;
};

}

#endif // PRICEDATA_H
