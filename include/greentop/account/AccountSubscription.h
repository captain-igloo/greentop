/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTSUBSCRIPTION_H
#define ACCOUNTSUBSCRIPTION_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/account/SubscriptionTokenInfo.h"

namespace greentop {
/**
 * Application subscription details
 */
class AccountSubscription : public JsonMember {
    public:
        AccountSubscription();

        AccountSubscription(const std::vector<SubscriptionTokenInfo>& subscriptionTokens,
            const std::string& applicationName = std::string(),
            const std::string& applicationVersionId = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<SubscriptionTokenInfo>& getSubscriptionTokens() const;
        void setSubscriptionTokens(const std::vector<SubscriptionTokenInfo>& subscriptionTokens);

        const std::string& getApplicationName() const;
        void setApplicationName(const std::string& applicationName);

        const std::string& getApplicationVersionId() const;
        void setApplicationVersionId(const std::string& applicationVersionId);


    private:
        /**
         * List of subscription token details
         */
        std::vector<SubscriptionTokenInfo> subscriptionTokens;
        /**
         * Application name
         */
        std::string applicationName;
        /**
         * Application version Id
         */
        std::string applicationVersionId;
};

}

#endif // ACCOUNTSUBSCRIPTION_H
