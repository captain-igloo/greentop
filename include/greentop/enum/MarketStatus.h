#ifndef MARKETSTATUS_H
#define MARKETSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class MarketStatus : public Enum<MarketStatus> {

    public:

        static const std::string INACTIVE;
        static const std::string OPEN;
        static const std::string SUSPENDED;
        static const std::string CLOSED;

        MarketStatus();

        MarketStatus(const std::string& v);

        bool operator<(const MarketStatus& other) const;

        bool operator==(const MarketStatus& other) const;
};

}

#endif // MARKETSTATUS_H
