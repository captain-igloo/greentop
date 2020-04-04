/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/TransferResponse.h"

namespace greentop {
namespace account {

TransferResponse::TransferResponse() {
}

TransferResponse::TransferResponse(const std::string& transactionId) :
    transactionId(transactionId) {
}

void TransferResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("transactionId")) {
            transactionId = json["transactionId"].asString();
        }
    }
}

Json::Value TransferResponse::toJson() const {
    Json::Value json(Json::objectValue);
    if (transactionId != "") {
        json["transactionId"] = transactionId;
    }
    return json;
}

bool TransferResponse::isValid() const {
    return transactionId != "";
}

const std::string& TransferResponse::getTransactionId() const {
    return transactionId;
}
void TransferResponse::setTransactionId(const std::string& transactionId) {
    this->transactionId = transactionId;
}


}
}
