/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ListApplicationSubscriptionTokensResponse.h"

namespace greentop {
namespace account {

ListApplicationSubscriptionTokensResponse::ListApplicationSubscriptionTokensResponse() {
}

ListApplicationSubscriptionTokensResponse::ListApplicationSubscriptionTokensResponse(const std::vector<ApplicationSubscription>& applicationSubscriptions) :
    applicationSubscriptions(applicationSubscriptions) {
}

void ListApplicationSubscriptionTokensResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            ApplicationSubscription applicationSubscription;
            applicationSubscription.fromJson(json[i]);
            applicationSubscriptions.push_back(applicationSubscription);
        }
    }
}

Json::Value ListApplicationSubscriptionTokensResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (applicationSubscriptions.size() > 0) {
        for (unsigned i = 0; i < applicationSubscriptions.size(); ++i) {
            json.append(applicationSubscriptions[i].toJson());
        }
    }
    return json;
}

bool ListApplicationSubscriptionTokensResponse::isValid() const {
    return applicationSubscriptions.size() > 0;
}

const std::vector<ApplicationSubscription>& ListApplicationSubscriptionTokensResponse::getApplicationSubscriptions() const {
    return applicationSubscriptions;
}
void ListApplicationSubscriptionTokensResponse::setApplicationSubscriptions(const std::vector<ApplicationSubscription>& applicationSubscriptions) {
    this->applicationSubscriptions = applicationSubscriptions;
}


}
}
