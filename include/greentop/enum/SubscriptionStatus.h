#ifndef SUBSCRIPTIONSTATUS_H
#define SUBSCRIPTIONSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class SubscriptionStatus : public Enum<SubscriptionStatus> {

    public:

        static const std::string ALL;
        static const std::string ACTIVATED;
        static const std::string UNACTIVATED;
        static const std::string CANCELLED;
        static const std::string EXPIRED;

        SubscriptionStatus();

        SubscriptionStatus(const std::string& v);

        bool operator<(const SubscriptionStatus& other) const;

        bool operator==(const SubscriptionStatus& other) const;
};

}

#endif // SUBSCRIPTIONSTATUS_H
