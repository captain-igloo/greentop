/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SUBSCRIPTIONTOKENINFO_H
#define SUBSCRIPTIONTOKENINFO_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {
/**
 * Subscription token information
 */
class SubscriptionTokenInfo : public JsonMember {
    public:
        SubscriptionTokenInfo();

        SubscriptionTokenInfo(const std::string& subscriptionToken,
            const std::tm& activatedDateTime = std::tm(),
            const std::tm& expiryDateTime = std::tm(),
            const std::tm& expiredDateTime = std::tm(),
            const std::tm& cancellationDateTime = std::tm(),
            const std::string& subscriptionStatus = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getSubscriptionToken() const;
        void setSubscriptionToken(const std::string& subscriptionToken);

        const std::tm& getActivatedDateTime() const;
        void setActivatedDateTime(const std::tm& activatedDateTime);

        const std::tm& getExpiryDateTime() const;
        void setExpiryDateTime(const std::tm& expiryDateTime);

        const std::tm& getExpiredDateTime() const;
        void setExpiredDateTime(const std::tm& expiredDateTime);

        const std::tm& getCancellationDateTime() const;
        void setCancellationDateTime(const std::tm& cancellationDateTime);

        const std::string& getSubscriptionStatus() const;
        void setSubscriptionStatus(const std::string& subscriptionStatus);


    private:
        /**
         * Subscription token
         */
        std::string subscriptionToken;
        /**
         * Subscription Activated date
         */
        std::tm activatedDateTime;
        /**
         * Subscription Expiry date
         */
        std::tm expiryDateTime;
        /**
         * Subscription Expired date
         */
        std::tm expiredDateTime;
        /**
         * Subscription Cancelled date
         */
        std::tm cancellationDateTime;
        /**
         * Subscription status
         */
        std::string subscriptionStatus;
};

}

#endif // SUBSCRIPTIONTOKENINFO_H
