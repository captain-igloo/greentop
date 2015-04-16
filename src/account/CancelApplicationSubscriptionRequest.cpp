#include "greentop/account/CancelApplicationSubscriptionRequest.h"

namespace greentop {
CancelApplicationSubscriptionRequest::CancelApplicationSubscriptionRequest() {
}

CancelApplicationSubscriptionRequest::CancelApplicationSubscriptionRequest(const std::string& subscriptionToken) :
    subscriptionToken(subscriptionToken) {
}

void CancelApplicationSubscriptionRequest::fromJson(const Json::Value& json) {
    if (json.isMember("subscriptionToken")) {
        subscriptionToken = json["subscriptionToken"].asString();
    }
}

Json::Value CancelApplicationSubscriptionRequest::toJson() const {
    Json::Value json;
    if (subscriptionToken != "") {
        json["subscriptionToken"] = subscriptionToken;
    }
    return json;
}

bool CancelApplicationSubscriptionRequest::isValid() const {
    return subscriptionToken != "";
}

const std::string& CancelApplicationSubscriptionRequest::getSubscriptionToken() const {
    return subscriptionToken;
}
void CancelApplicationSubscriptionRequest::setSubscriptionToken(const std::string& subscriptionToken) {
    this->subscriptionToken = subscriptionToken;
}


}



