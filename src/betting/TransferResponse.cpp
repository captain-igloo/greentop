#include "greentop/betting/TransferResponse.h"

namespace greentop {

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
    Json::Value json;
    if (transactionId != "") {
        json["transactionId"] = transactionId;
    }
    return json;
}

bool TransferResponse::isValid() const {
    return true;
}

const std::string& TransferResponse::getTransactionId() const {
    return transactionId;
}
void TransferResponse::setTransactionId(const std::string& transactionId) {
    this->transactionId = transactionId;
}


}



