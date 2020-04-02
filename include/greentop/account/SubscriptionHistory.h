/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_SUBSCRIPTIONHISTORY_H
#define ACCOUNT_SUBSCRIPTIONHISTORY_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {
namespace account {
/**
 * Application subscription history details
 */
class SubscriptionHistory : public JsonMember {
    public:
        SubscriptionHistory();

        SubscriptionHistory(const std::string& subscriptionToken,
            const std::tm& expiryDateTime = std::tm(),
            const std::tm& expiredDateTime = std::tm(),
            const std::tm& createdDateTime = std::tm(),
            const std::tm& activationDateTime = std::tm(),
            const std::tm& cancellationDateTime = std::tm(),
            const std::string& subscriptionStatus = std::string(),
            const std::string& clientReference = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getSubscriptionToken() const;
        void setSubscriptionToken(const std::string& subscriptionToken);

        const std::tm& getExpiryDateTime() const;
        void setExpiryDateTime(const std::tm& expiryDateTime);

        const std::tm& getExpiredDateTime() const;
        void setExpiredDateTime(const std::tm& expiredDateTime);

        const std::tm& getCreatedDateTime() const;
        void setCreatedDateTime(const std::tm& createdDateTime);

        const std::tm& getActivationDateTime() const;
        void setActivationDateTime(const std::tm& activationDateTime);

        const std::tm& getCancellationDateTime() const;
        void setCancellationDateTime(const std::tm& cancellationDateTime);

        const std::string& getSubscriptionStatus() const;
        void setSubscriptionStatus(const std::string& subscriptionStatus);

        const std::string& getClientReference() const;
        void setClientReference(const std::string& clientReference);


    private:
        /**
         * Application key identifier
         */
        std::string subscriptionToken;
        /**
         * Subscription Expiry date
         */
        std::tm expiryDateTime;
        /**
         * Subscription Expired date
         */
        std::tm expiredDateTime;
        /**
         * Subscription Create date
         */
        std::tm createdDateTime;
        /**
         * Subscription Activation date
         */
        std::tm activationDateTime;
        /**
         * Subscription Cancelled date
         */
        std::tm cancellationDateTime;
        /**
         * Subscription status
         */
        std::string subscriptionStatus;
        /**
         * Client reference
         */
        std::string clientReference;
};

}
}

#endif // ACCOUNT_SUBSCRIPTIONHISTORY_H
