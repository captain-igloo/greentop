/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ListAccountSubscriptionTokensResponse.h"

namespace greentop {
namespace account {

ListAccountSubscriptionTokensResponse::ListAccountSubscriptionTokensResponse() {
}

ListAccountSubscriptionTokensResponse::ListAccountSubscriptionTokensResponse(const std::vector<AccountSubscription>& accountSubscriptions) :
    accountSubscriptions(accountSubscriptions) {
}

void ListAccountSubscriptionTokensResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            AccountSubscription accountSubscription;
            accountSubscription.fromJson(json[i]);
            accountSubscriptions.push_back(accountSubscription);
        }
    }
}

Json::Value ListAccountSubscriptionTokensResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (accountSubscriptions.size() > 0) {
        for (unsigned i = 0; i < accountSubscriptions.size(); ++i) {
            json.append(accountSubscriptions[i].toJson());
        }
    }
    return json;
}

bool ListAccountSubscriptionTokensResponse::isValid() const {
    return accountSubscriptions.size() > 0;
}

const std::vector<AccountSubscription>& ListAccountSubscriptionTokensResponse::getAccountSubscriptions() const {
    return accountSubscriptions;
}
void ListAccountSubscriptionTokensResponse::setAccountSubscriptions(const std::vector<AccountSubscription>& accountSubscriptions) {
    this->accountSubscriptions = accountSubscriptions;
}


}
}
