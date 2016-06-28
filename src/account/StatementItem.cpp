/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/StatementItem.h"

namespace greentop {

StatementItem::StatementItem(const std::string& refId,
    const std::tm& itemDate,
    const Optional<double>& amount,
    const Optional<double>& balance,
    const ItemClass& itemClass,
    const std::map<std::string,std::string>& itemClassData,
    const StatementLegacyData& legacyData) :
    refId(refId),
    itemDate(itemDate),
    amount(amount),
    balance(balance),
    itemClass(itemClass),
    itemClassData(itemClassData),
    legacyData(legacyData) {
}

void StatementItem::fromJson(const Json::Value& json) {
    if (json.isMember("refId")) {
        refId = json["refId"].asString();
    }
    if (json.isMember("itemDate")) {
        strptime(json["itemDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &itemDate);
    }
    if (json.isMember("amount")) {
        amount.fromJson(json["amount"]);
    }
    if (json.isMember("balance")) {
        balance.fromJson(json["balance"]);
    }
    if (json.isMember("itemClass")) {
        itemClass = json["itemClass"].asString();
    }
    if (json.isMember("itemClassData")) {
        for (std::string const& key : json["itemClassData"].getMemberNames()) {
            itemClassData[key] = json["itemClassData"][key].asString();
        };
    }
    if (json.isMember("legacyData")) {
        legacyData.fromJson(json["legacyData"]);
    }
}

Json::Value StatementItem::toJson() const {
    Json::Value json(Json::objectValue);
    if (refId != "") {
        json["refId"] = refId;
    }
    if (itemDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &itemDate);
        json["itemDate"] = std::string(buffer);
    }
    if (amount.isValid()) {
        json["amount"] = amount.toJson();
    }
    if (balance.isValid()) {
        json["balance"] = balance.toJson();
    }
    if (itemClass.isValid()) {
        json["itemClass"] = itemClass.getValue();
    }
    if (itemClassData.size() > 0) {
        std::map<std::string, std::string>::const_iterator it;
        for (it = itemClassData.begin(); it != itemClassData.end(); ++it) {
            json["itemClassData"][it->first] = it->second;
        };
    }
    if (legacyData.isValid()) {
        json["legacyData"] = legacyData.toJson();
    }
    return json;
}

bool StatementItem::isValid() const {
    return true;
}

const std::string& StatementItem::getRefId() const {
    return refId;
}
void StatementItem::setRefId(const std::string& refId) {
    this->refId = refId;
}

const std::tm& StatementItem::getItemDate() const {
    return itemDate;
}
void StatementItem::setItemDate(const std::tm& itemDate) {
    this->itemDate = itemDate;
}

const Optional<double>& StatementItem::getAmount() const {
    return amount;
}
void StatementItem::setAmount(const Optional<double>& amount) {
    this->amount = amount;
}

const Optional<double>& StatementItem::getBalance() const {
    return balance;
}
void StatementItem::setBalance(const Optional<double>& balance) {
    this->balance = balance;
}

const ItemClass& StatementItem::getItemClass() const {
    return itemClass;
}
void StatementItem::setItemClass(const ItemClass& itemClass) {
    this->itemClass = itemClass;
}

const std::map<std::string,std::string>& StatementItem::getItemClassData() const {
    return itemClassData;
}
void StatementItem::setItemClassData(const std::map<std::string,std::string>& itemClassData) {
    this->itemClassData = itemClassData;
}

const StatementLegacyData& StatementItem::getLegacyData() const {
    return legacyData;
}
void StatementItem::setLegacyData(const StatementLegacyData& legacyData) {
    this->legacyData = legacyData;
}


}



