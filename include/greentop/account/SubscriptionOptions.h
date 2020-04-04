/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_SUBSCRIPTIONOPTIONS_H
#define ACCOUNT_SUBSCRIPTIONOPTIONS_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace account {
/**
 * Wrapper object containing details of how a subscription should be created
 */
class SubscriptionOptions : public JsonMember {
    public:

        SubscriptionOptions(const Optional<int32_t>& subscriptionLength = Optional<int32_t>(),
            const std::string& subscriptionToken = std::string(),
            const std::string& clientReference = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int32_t>& getSubscriptionLength() const;
        void setSubscriptionLength(const Optional<int32_t>& subscriptionLength);

        const std::string& getSubscriptionToken() const;
        void setSubscriptionToken(const std::string& subscriptionToken);

        const std::string& getClientReference() const;
        void setClientReference(const std::string& clientReference);


    private:
        /**
         * How many days should a created subscription last for. Open ended subscription created if
         * value not provided. Relevant only if createdSubscription is true.
         */
        Optional<int32_t> subscriptionLength;
        /**
         * An existing subscription token that the caller wishes to be activated instead of
         * creating a new one. Ignored is createSubscription is true.
         */
        std::string subscriptionToken;
        /**
         * Any client reference for this subscription token request.
         */
        std::string clientReference;
};

}
}

#endif // ACCOUNT_SUBSCRIPTIONOPTIONS_H
