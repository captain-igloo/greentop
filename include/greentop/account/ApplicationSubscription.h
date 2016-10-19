/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef APPLICATIONSUBSCRIPTION_H
#define APPLICATIONSUBSCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {

class ApplicationSubscription : public JsonMember {
    public:
        ApplicationSubscription();

        ApplicationSubscription(const std::string& subscriptionToken,
            const std::tm& expiryDateTime = std::tm(),
            const std::tm& expiredDateTime = std::tm(),
            const std::tm& createdDateTime = std::tm(),
            const std::tm& activationDateTime = std::tm(),
            const std::tm& cancellationDateTime = std::tm(),
            const std::string& subscriptionStatus = std::string(),
            const std::string& clientReference = std::string(),
            const std::string& vendorClientId = std::string());

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

        const std::string& getVendorClientId() const;
        void setVendorClientId(const std::string& vendorClientId);


    private:
        std::string subscriptionToken;
        std::tm expiryDateTime;
        std::tm expiredDateTime;
        std::tm createdDateTime;
        std::tm activationDateTime;
        std::tm cancellationDateTime;
        std::string subscriptionStatus;
        std::string clientReference;
        std::string vendorClientId;
};

}

#endif // APPLICATIONSUBSCRIPTION_H


