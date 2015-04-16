#include "greentop/account/GetApplicationSubscriptionHistoryResponse.h"

namespace greentop {

GetApplicationSubscriptionHistoryResponse::GetApplicationSubscriptionHistoryResponse(const std::vector<SubscriptionHistory>& subscriptionHistories) :
    subscriptionHistories(subscriptionHistories) {
}

void GetApplicationSubscriptionHistoryResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            SubscriptionHistory subscriptionHistorie;
            subscriptionHistorie.fromJson(json[i]);
            subscriptionHistories.push_back(subscriptionHistorie);
        };
    }
}

Json::Value GetApplicationSubscriptionHistoryResponse::toJson() const {
    Json::Value json;
    if (subscriptionHistories.size() > 0) {
        for (unsigned i = 0; i < subscriptionHistories.size(); ++i) {
            json.append(subscriptionHistories[i].toJson());
        };
    }
    return json;
}

bool GetApplicationSubscriptionHistoryResponse::isValid() const {
    return true;
}

const std::vector<SubscriptionHistory>& GetApplicationSubscriptionHistoryResponse::getSubscriptionHistories() const {
    return subscriptionHistories;
}
void GetApplicationSubscriptionHistoryResponse::setSubscriptionHistories(const std::vector<SubscriptionHistory>& subscriptionHistories) {
    this->subscriptionHistories = subscriptionHistories;
}


}



