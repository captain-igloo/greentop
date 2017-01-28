/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SUBSCRIPTIONOPTIONS_H
#define SUBSCRIPTIONOPTIONS_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Wrapper object containing details of how a subscription should be created
 */
class SubscriptionOptions : public JsonMember {
    public:

        SubscriptionOptions(const Optional<int32_t>& subscription_length = Optional<int32_t>(),
            const std::string& subscription_token = std::string(),
            const std::string& client_reference = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int32_t>& getSubscription_length() const;
        void setSubscription_length(const Optional<int32_t>& subscription_length);

        const std::string& getSubscription_token() const;
        void setSubscription_token(const std::string& subscription_token);

        const std::string& getClient_reference() const;
        void setClient_reference(const std::string& client_reference);


    private:
        /**
         * How many days should a created subscription last for. Open ended subscription created if
         * value not provided. Relevant only if createdSubscription is true.
         */
        Optional<int32_t> subscription_length;
        /**
         * An existing subscription token that the caller wishes to be activated instead of
         * creating a new one. Ignored is createSubscription is true.
         */
        std::string subscription_token;
        /**
         * Any client reference for this subscription token request.
         */
        std::string client_reference;
};

}

#endif // SUBSCRIPTIONOPTIONS_H


