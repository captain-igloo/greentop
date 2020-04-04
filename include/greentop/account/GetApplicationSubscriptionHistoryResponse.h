/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETAPPLICATIONSUBSCRIPTIONHISTORYRESPONSE_H
#define ACCOUNT_GETAPPLICATIONSUBSCRIPTIONHISTORYRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/SubscriptionHistory.h"

namespace greentop {
namespace account {

class GetApplicationSubscriptionHistoryResponse : public JsonResponse {
    public:
        GetApplicationSubscriptionHistoryResponse();

        GetApplicationSubscriptionHistoryResponse(const std::vector<SubscriptionHistory>& subscriptionHistorys);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<SubscriptionHistory>& getSubscriptionHistorys() const;
        void setSubscriptionHistorys(const std::vector<SubscriptionHistory>& subscriptionHistorys);


    private:

        std::vector<SubscriptionHistory> subscriptionHistorys;
};

}
}

#endif // ACCOUNT_GETAPPLICATIONSUBSCRIPTIONHISTORYRESPONSE_H
