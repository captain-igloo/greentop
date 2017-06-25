/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/MarketLicence.h"

namespace greentop {

MarketLicence::MarketLicence() {
}

MarketLicence::MarketLicence(const std::string& wallet,
    const std::string& rules,
    const Optional<bool>& rulesHasDate,
    const std::string& clarifications) :
    wallet(wallet),
    rules(rules),
    rulesHasDate(rulesHasDate),
    clarifications(clarifications) {
}

void MarketLicence::fromJson(const Json::Value& json) {
    if (json.isMember("wallet")) {
        wallet = json["wallet"].asString();
    }
    if (json.isMember("rules")) {
        rules = json["rules"].asString();
    }
    if (json.isMember("rulesHasDate")) {
        rulesHasDate = json["rulesHasDate"].asBool();
    }
    if (json.isMember("clarifications")) {
        clarifications = json["clarifications"].asString();
    }
}

Json::Value MarketLicence::toJson() const {
    Json::Value json(Json::objectValue);
    if (wallet != "") {
        json["wallet"] = wallet;
    }
    if (rules != "") {
        json["rules"] = rules;
    }
    if (rulesHasDate.isValid()) {
        json["rulesHasDate"] = rulesHasDate.toJson();
    }
    if (clarifications != "") {
        json["clarifications"] = clarifications;
    }
    return json;
}

bool MarketLicence::isValid() const {
    return wallet != "";
}

const std::string& MarketLicence::getWallet() const {
    return wallet;
}
void MarketLicence::setWallet(const std::string& wallet) {
    this->wallet = wallet;
}

const std::string& MarketLicence::getRules() const {
    return rules;
}
void MarketLicence::setRules(const std::string& rules) {
    this->rules = rules;
}

const Optional<bool>& MarketLicence::getRulesHasDate() const {
    return rulesHasDate;
}
void MarketLicence::setRulesHasDate(const Optional<bool>& rulesHasDate) {
    this->rulesHasDate = rulesHasDate;
}

const std::string& MarketLicence::getClarifications() const {
    return clarifications;
}
void MarketLicence::setClarifications(const std::string& clarifications) {
    this->clarifications = clarifications;
}


}



