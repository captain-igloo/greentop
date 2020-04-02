/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetApplicationSubscriptionHistoryResponse.h"

namespace greentop {
namespace account {

GetApplicationSubscriptionHistoryResponse::GetApplicationSubscriptionHistoryResponse() {
}

GetApplicationSubscriptionHistoryResponse::GetApplicationSubscriptionHistoryResponse(const std::vector<SubscriptionHistory>& subscriptionHistorys) :
    subscriptionHistorys(subscriptionHistorys) {
}

void GetApplicationSubscriptionHistoryResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            SubscriptionHistory subscriptionHistory;
            subscriptionHistory.fromJson(json[i]);
            subscriptionHistorys.push_back(subscriptionHistory);
        }
    }
}

Json::Value GetApplicationSubscriptionHistoryResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (subscriptionHistorys.size() > 0) {
        for (unsigned i = 0; i < subscriptionHistorys.size(); ++i) {
            json.append(subscriptionHistorys[i].toJson());
        }
    }
    return json;
}

bool GetApplicationSubscriptionHistoryResponse::isValid() const {
    return subscriptionHistorys.size() > 0;
}

const std::vector<SubscriptionHistory>& GetApplicationSubscriptionHistoryResponse::getSubscriptionHistorys() const {
    return subscriptionHistorys;
}
void GetApplicationSubscriptionHistoryResponse::setSubscriptionHistorys(const std::vector<SubscriptionHistory>& subscriptionHistorys) {
    this->subscriptionHistorys = subscriptionHistorys;
}


}
}
