/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_PRICEDATA_H
#define SPORT_ENUM_PRICEDATA_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {
namespace enum {

class PriceData : public Enum<PriceData> {

    public:


        static const std::string SP_AVAILABLE;

        static const std::string SP_TRADED;

        static const std::string EX_BEST_OFFERS;
        /**
         * EX_ALL_OFFERS trumps EX_BEST_OFFERS if both settings are present
         */
        static const std::string EX_ALL_OFFERS;

        static const std::string EX_TRADED;

        PriceData();

        PriceData(const std::string& v);

        bool operator<(const PriceData& other) const;

        bool operator==(const PriceData& other) const;

        bool operator!=(const PriceData& other) const;
};

}
}
}

#endif // SPORT_ENUM_PRICEDATA_H
