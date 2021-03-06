/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_UPDATEAPPLICATIONSUBSCRIPTIONREQUEST_H
#define ACCOUNT_UPDATEAPPLICATIONSUBSCRIPTIONREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"

namespace greentop {
namespace account {

class UpdateApplicationSubscriptionRequest : public JsonRequest {
    public:
        UpdateApplicationSubscriptionRequest();

        UpdateApplicationSubscriptionRequest(const std::string& vendorClientId,
            const Optional<int32_t>& subscriptionLength);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorClientId() const;
        void setVendorClientId(const std::string& vendorClientId);

        const Optional<int32_t>& getSubscriptionLength() const;
        void setSubscriptionLength(const Optional<int32_t>& subscriptionLength);


    private:
        /**
         * The vendor client id for which to update the subscription for
         */
        std::string vendorClientId;
        /**
         * How many days the subscription should last. Expiry time will be rounded up to midnight
         * on the date of expiry.
         */
        Optional<int32_t> subscriptionLength;
};

}
}

#endif // ACCOUNT_UPDATEAPPLICATIONSUBSCRIPTIONREQUEST_H
