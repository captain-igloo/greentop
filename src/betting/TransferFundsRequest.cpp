/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/TransferFundsRequest.h"

namespace greentop {

TransferFundsRequest::TransferFundsRequest(const Wallet& from,
    const Wallet& to,
    const double amount) :
    from(from),
    to(to),
    amount(amount) {
}

void TransferFundsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("from")) {
        from = json["from"].asString();
    }
    if (json.isMember("to")) {
        to = json["to"].asString();
    }
    if (json.isMember("amount")) {
        amount = json["amount"].asDouble();
    }
}

Json::Value TransferFundsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (from.isValid()) {
        json["from"] = from.getValue();
    }
    if (to.isValid()) {
        json["to"] = to.getValue();
    }
    if (amount >= 0) {
        json["amount"] = amount;
    }
    return json;
}

bool TransferFundsRequest::isValid() const {
    return true;
}

const Wallet& TransferFundsRequest::getFrom() const {
    return from;
}
void TransferFundsRequest::setFrom(const Wallet& from) {
    this->from = from;
}

const Wallet& TransferFundsRequest::getTo() const {
    return to;
}
void TransferFundsRequest::setTo(const Wallet& to) {
    this->to = to;
}

const double TransferFundsRequest::getAmount() const {
    return amount;
}
void TransferFundsRequest::setAmount(const double amount) {
    this->amount = amount;
}


}



