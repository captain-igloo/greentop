#ifndef GETAPPLICATIONSUBSCRIPTIONHISTORYRESPONSE_H
#define GETAPPLICATIONSUBSCRIPTIONHISTORYRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/SubscriptionHistory.h"

namespace greentop {

class GetApplicationSubscriptionHistoryResponse : public JsonResponse {
    public:

        GetApplicationSubscriptionHistoryResponse(const std::vector<SubscriptionHistory>& subscriptionHistories = std::vector<SubscriptionHistory>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<SubscriptionHistory>& getSubscriptionHistories() const;
        void setSubscriptionHistories(const std::vector<SubscriptionHistory>& subscriptionHistories);


    private:
        std::vector<SubscriptionHistory> subscriptionHistories;
};

}

#endif // GETAPPLICATIONSUBSCRIPTIONHISTORYRESPONSE_H


