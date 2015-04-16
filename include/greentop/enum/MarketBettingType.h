#ifndef MARKETBETTINGTYPE_H
#define MARKETBETTINGTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketBettingType : public Enum<MarketBettingType> {

    public:

        static const std::string ODDS;
        static const std::string LINE;
        static const std::string RANGE;
        static const std::string ASIAN_HANDICAP_DOUBLE_LINE;
        static const std::string ASIAN_HANDICAP_SINGLE_LINE;
        static const std::string FIXED_ODDS;

        MarketBettingType();

        MarketBettingType(const std::string& v);

        bool operator<(const MarketBettingType& other) const;

        bool operator==(const MarketBettingType& other) const;
};

}

#endif // MARKETBETTINGTYPE_H
