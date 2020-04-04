/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_SUBSCRIPTIONSTATUS_H
#define ACCOUNT_ENUM_SUBSCRIPTIONSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class SubscriptionStatus : public Enum<SubscriptionStatus> {

    public:

        /**
         * Any subscription status
         */
        static const std::string ALL;
        /**
         * Only activated subscriptions
         */
        static const std::string ACTIVATED;
        /**
         * Only unactivated subscriptions
         */
        static const std::string UNACTIVATED;
        /**
         * Only cancelled subscriptions
         */
        static const std::string CANCELLED;
        /**
         * Only expired subscriptions
         */
        static const std::string EXPIRED;

        SubscriptionStatus();

        SubscriptionStatus(const std::string& v);

        bool operator<(const SubscriptionStatus& other) const;

        bool operator==(const SubscriptionStatus& other) const;

        bool operator!=(const SubscriptionStatus& other) const;
};

}
}

#endif // ACCOUNT_ENUM_SUBSCRIPTIONSTATUS_H
