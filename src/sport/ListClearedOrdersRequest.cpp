/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListClearedOrdersRequest.h"

namespace greentop {

ListClearedOrdersRequest::ListClearedOrdersRequest() {
}

ListClearedOrdersRequest::ListClearedOrdersRequest(const BetStatus& betStatus,
    const std::set<std::string>& eventTypeIds,
    const std::set<std::string>& eventIds,
    const std::set<std::string>& marketIds,
    const std::vector<RunnerId>& runnerIds,
    const std::set<std::string>& betIds,
    const std::set<std::string>& customerOrderRefs,
    const std::set<std::string>& customerStrategyRefs,
    const Side& side,
    const TimeRange& settledDateRange,
    const GroupBy& groupBy,
    const Optional<bool>& includeItemDescription,
    const std::string& locale,
    const Optional<int32_t>& fromRecord,
    const Optional<int32_t>& recordCount) :
    betStatus(betStatus),
    eventTypeIds(eventTypeIds),
    eventIds(eventIds),
    marketIds(marketIds),
    runnerIds(runnerIds),
    betIds(betIds),
    customerOrderRefs(customerOrderRefs),
    customerStrategyRefs(customerStrategyRefs),
    side(side),
    settledDateRange(settledDateRange),
    groupBy(groupBy),
    includeItemDescription(includeItemDescription),
    locale(locale),
    fromRecord(fromRecord),
    recordCount(recordCount) {
}

void ListClearedOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("betStatus")) {
        betStatus = json["betStatus"].asString();
    }
    if (json.isMember("eventTypeIds")) {
        for (unsigned i = 0; i < json["eventTypeIds"].size(); ++i) {
            eventTypeIds.insert(json["eventTypeIds"][i].asString());
        }
    }
    if (json.isMember("eventIds")) {
        for (unsigned i = 0; i < json["eventIds"].size(); ++i) {
            eventIds.insert(json["eventIds"][i].asString());
        }
    }
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        }
    }
    if (json.isMember("runnerIds")) {
        for (unsigned i = 0; i < json["runnerIds"].size(); ++i) {
            RunnerId runnerId;
            runnerId.fromJson(json["runnerIds"][i]);
            runnerIds.push_back(runnerId);
        }
    }
    if (json.isMember("betIds")) {
        for (unsigned i = 0; i < json["betIds"].size(); ++i) {
            betIds.insert(json["betIds"][i].asString());
        }
    }
    if (json.isMember("customerOrderRefs")) {
        for (unsigned i = 0; i < json["customerOrderRefs"].size(); ++i) {
            customerOrderRefs.insert(json["customerOrderRefs"][i].asString());
        }
    }
    if (json.isMember("customerStrategyRefs")) {
        for (unsigned i = 0; i < json["customerStrategyRefs"].size(); ++i) {
            customerStrategyRefs.insert(json["customerStrategyRefs"][i].asString());
        }
    }
    if (json.isMember("side")) {
        side = json["side"].asString();
    }
    if (json.isMember("settledDateRange")) {
        settledDateRange.fromJson(json["settledDateRange"]);
    }
    if (json.isMember("groupBy")) {
        groupBy = json["groupBy"].asString();
    }
    if (json.isMember("includeItemDescription")) {
        includeItemDescription = json["includeItemDescription"].asBool();
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
    if (json.isMember("fromRecord")) {
        fromRecord = json["fromRecord"].asInt();
    }
    if (json.isMember("recordCount")) {
        recordCount = json["recordCount"].asInt();
    }
}

Json::Value ListClearedOrdersRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (betStatus.isValid()) {
        json["betStatus"] = betStatus.getValue();
    }
    if (eventTypeIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = eventTypeIds.begin(); it != eventTypeIds.end(); ++it) {
            json["eventTypeIds"].append(*it);
        }
    }
    if (eventIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = eventIds.begin(); it != eventIds.end(); ++it) {
            json["eventIds"].append(*it);
        }
    }
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        }
    }
    if (runnerIds.size() > 0) {
        for (unsigned i = 0; i < runnerIds.size(); ++i) {
            json["runnerIds"].append(runnerIds[i].toJson());
        }
    }
    if (betIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = betIds.begin(); it != betIds.end(); ++it) {
            json["betIds"].append(*it);
        }
    }
    if (customerOrderRefs.size() > 0) {
        for (std::set<std::string>::const_iterator it = customerOrderRefs.begin(); it != customerOrderRefs.end(); ++it) {
            json["customerOrderRefs"].append(*it);
        }
    }
    if (customerStrategyRefs.size() > 0) {
        for (std::set<std::string>::const_iterator it = customerStrategyRefs.begin(); it != customerStrategyRefs.end(); ++it) {
            json["customerStrategyRefs"].append(*it);
        }
    }
    if (side.isValid()) {
        json["side"] = side.getValue();
    }
    if (settledDateRange.isValid()) {
        json["settledDateRange"] = settledDateRange.toJson();
    }
    if (groupBy.isValid()) {
        json["groupBy"] = groupBy.getValue();
    }
    if (includeItemDescription.isValid()) {
        json["includeItemDescription"] = includeItemDescription.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    if (fromRecord.isValid()) {
        json["fromRecord"] = fromRecord.toJson();
    }
    if (recordCount.isValid()) {
        json["recordCount"] = recordCount.toJson();
    }
    return json;
}

bool ListClearedOrdersRequest::isValid() const {
    return betStatus.isValid();
}

const BetStatus& ListClearedOrdersRequest::getBetStatus() const {
    return betStatus;
}
void ListClearedOrdersRequest::setBetStatus(const BetStatus& betStatus) {
    this->betStatus = betStatus;
}

const std::set<std::string>& ListClearedOrdersRequest::getEventTypeIds() const {
    return eventTypeIds;
}
void ListClearedOrdersRequest::setEventTypeIds(const std::set<std::string>& eventTypeIds) {
    this->eventTypeIds = eventTypeIds;
}

const std::set<std::string>& ListClearedOrdersRequest::getEventIds() const {
    return eventIds;
}
void ListClearedOrdersRequest::setEventIds(const std::set<std::string>& eventIds) {
    this->eventIds = eventIds;
}

const std::set<std::string>& ListClearedOrdersRequest::getMarketIds() const {
    return marketIds;
}
void ListClearedOrdersRequest::setMarketIds(const std::set<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const std::vector<RunnerId>& ListClearedOrdersRequest::getRunnerIds() const {
    return runnerIds;
}
void ListClearedOrdersRequest::setRunnerIds(const std::vector<RunnerId>& runnerIds) {
    this->runnerIds = runnerIds;
}

const std::set<std::string>& ListClearedOrdersRequest::getBetIds() const {
    return betIds;
}
void ListClearedOrdersRequest::setBetIds(const std::set<std::string>& betIds) {
    this->betIds = betIds;
}

const std::set<std::string>& ListClearedOrdersRequest::getCustomerOrderRefs() const {
    return customerOrderRefs;
}
void ListClearedOrdersRequest::setCustomerOrderRefs(const std::set<std::string>& customerOrderRefs) {
    this->customerOrderRefs = customerOrderRefs;
}

const std::set<std::string>& ListClearedOrdersRequest::getCustomerStrategyRefs() const {
    return customerStrategyRefs;
}
void ListClearedOrdersRequest::setCustomerStrategyRefs(const std::set<std::string>& customerStrategyRefs) {
    this->customerStrategyRefs = customerStrategyRefs;
}

const Side& ListClearedOrdersRequest::getSide() const {
    return side;
}
void ListClearedOrdersRequest::setSide(const Side& side) {
    this->side = side;
}

const TimeRange& ListClearedOrdersRequest::getSettledDateRange() const {
    return settledDateRange;
}
void ListClearedOrdersRequest::setSettledDateRange(const TimeRange& settledDateRange) {
    this->settledDateRange = settledDateRange;
}

const GroupBy& ListClearedOrdersRequest::getGroupBy() const {
    return groupBy;
}
void ListClearedOrdersRequest::setGroupBy(const GroupBy& groupBy) {
    this->groupBy = groupBy;
}

const Optional<bool>& ListClearedOrdersRequest::getIncludeItemDescription() const {
    return includeItemDescription;
}
void ListClearedOrdersRequest::setIncludeItemDescription(const Optional<bool>& includeItemDescription) {
    this->includeItemDescription = includeItemDescription;
}

const std::string& ListClearedOrdersRequest::getLocale() const {
    return locale;
}
void ListClearedOrdersRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}

const Optional<int32_t>& ListClearedOrdersRequest::getFromRecord() const {
    return fromRecord;
}
void ListClearedOrdersRequest::setFromRecord(const Optional<int32_t>& fromRecord) {
    this->fromRecord = fromRecord;
}

const Optional<int32_t>& ListClearedOrdersRequest::getRecordCount() const {
    return recordCount;
}
void ListClearedOrdersRequest::setRecordCount(const Optional<int32_t>& recordCount) {
    this->recordCount = recordCount;
}


}



