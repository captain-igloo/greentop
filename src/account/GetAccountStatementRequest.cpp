/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/GetAccountStatementRequest.h"

namespace greentop {

GetAccountStatementRequest::GetAccountStatementRequest(const std::string& locale,
    const int fromRecord,
    const int recordCount,
    const TimeRange& itemDateRange,
    const IncludeItem& includeItem,
    const Wallet& wallet) :
    locale(locale),
    fromRecord(fromRecord),
    recordCount(recordCount),
    itemDateRange(itemDateRange),
    includeItem(includeItem),
    wallet(wallet) {
}

void GetAccountStatementRequest::fromJson(const Json::Value& json) {
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
    if (json.isMember("fromRecord")) {
        fromRecord = json["fromRecord"].asInt();
    }
    if (json.isMember("recordCount")) {
        recordCount = json["recordCount"].asInt();
    }
    if (json.isMember("itemDateRange")) {
        itemDateRange.fromJson(json["itemDateRange"]);
    }
    if (json.isMember("includeItem")) {
        includeItem = json["includeItem"].asString();
    }
    if (json.isMember("wallet")) {
        wallet = json["wallet"].asString();
    }
}

Json::Value GetAccountStatementRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (locale != "") {
        json["locale"] = locale;
    }
    if (fromRecord >= 0) {
        json["fromRecord"] = fromRecord;
    }
    if (recordCount >= 0) {
        json["recordCount"] = recordCount;
    }
    if (itemDateRange.isValid()) {
        json["itemDateRange"] = itemDateRange.toJson();
    }
    if (includeItem.isValid()) {
        json["includeItem"] = includeItem.getValue();
    }
    if (wallet.isValid()) {
        json["wallet"] = wallet.getValue();
    }
    return json;
}

bool GetAccountStatementRequest::isValid() const {
    return true;
}

const std::string& GetAccountStatementRequest::getLocale() const {
    return locale;
}
void GetAccountStatementRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}

const int GetAccountStatementRequest::getFromRecord() const {
    return fromRecord;
}
void GetAccountStatementRequest::setFromRecord(const int fromRecord) {
    this->fromRecord = fromRecord;
}

const int GetAccountStatementRequest::getRecordCount() const {
    return recordCount;
}
void GetAccountStatementRequest::setRecordCount(const int recordCount) {
    this->recordCount = recordCount;
}

const TimeRange& GetAccountStatementRequest::getItemDateRange() const {
    return itemDateRange;
}
void GetAccountStatementRequest::setItemDateRange(const TimeRange& itemDateRange) {
    this->itemDateRange = itemDateRange;
}

const IncludeItem& GetAccountStatementRequest::getIncludeItem() const {
    return includeItem;
}
void GetAccountStatementRequest::setIncludeItem(const IncludeItem& includeItem) {
    this->includeItem = includeItem;
}

const Wallet& GetAccountStatementRequest::getWallet() const {
    return wallet;
}
void GetAccountStatementRequest::setWallet(const Wallet& wallet) {
    this->wallet = wallet;
}


}



