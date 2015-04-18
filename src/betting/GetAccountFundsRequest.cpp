/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/GetAccountFundsRequest.h"

namespace greentop {

GetAccountFundsRequest::GetAccountFundsRequest(const Wallet& wallet) :
    wallet(wallet) {
}

void GetAccountFundsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("wallet")) {
        wallet = json["wallet"].asString();
    }
}

Json::Value GetAccountFundsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (wallet.isValid()) {
        json["wallet"] = wallet.getValue();
    }
    return json;
}

bool GetAccountFundsRequest::isValid() const {
    return true;
}

const Wallet& GetAccountFundsRequest::getWallet() const {
    return wallet;
}
void GetAccountFundsRequest::setWallet(const Wallet& wallet) {
    this->wallet = wallet;
}


}



