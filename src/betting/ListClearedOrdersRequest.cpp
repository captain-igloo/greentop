/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ListClearedOrdersRequest.h"

namespace greentop {
ListClearedOrdersRequest::ListClearedOrdersRequest()  : fromRecord(0), recordCount(0){
}

ListClearedOrdersRequest::ListClearedOrdersRequest(const BetStatus& betStatus,
    const std::vector<std::string>& eventTypeIds,
    const std::vector<std::string>& eventIds,
    const std::vector<std::string>& marketIds,
    const std::vector<RunnerId>& runnerIds,
    const std::vector<std::string>& betIds,
    const Side& side,
    const TimeRange& settledDateRange,
    const GroupBy& groupBy,
    const Optional<bool>& includeItemDescription,
    const std::string& locale,
    const uint64_t fromRecord,
    const uint64_t recordCount) :
    betStatus(betStatus),
    eventTypeIds(eventTypeIds),
    eventIds(eventIds),
    marketIds(marketIds),
    runnerIds(runnerIds),
    betIds(betIds),
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
            eventTypeIds.push_back(json["eventTypeIds"][i].asString());
        };
    }
    if (json.isMember("eventIds")) {
        for (unsigned i = 0; i < json["eventIds"].size(); ++i) {
            eventIds.push_back(json["eventIds"][i].asString());
        };
    }
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.push_back(json["marketIds"][i].asString());
        };
    }
    if (json.isMember("runnerIds")) {
        for (unsigned i = 0; i < json["runnerIds"].size(); ++i) {
                RunnerId runnerId;
                runnerId.fromJson(json["runnerIds"][i]);
                runnerIds.push_back(runnerId);
            };
    }
    if (json.isMember("betIds")) {
        for (unsigned i = 0; i < json["betIds"].size(); ++i) {
            betIds.push_back(json["betIds"][i].asString());
        };
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
        includeItemDescription.fromJson(json["includeItemDescription"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
    if (json.isMember("fromRecord")) {
        fromRecord = json["fromRecord"].asUInt64();
    }
    if (json.isMember("recordCount")) {
        recordCount = json["recordCount"].asUInt64();
    }
}

Json::Value ListClearedOrdersRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (betStatus.isValid()) {
        json["betStatus"] = betStatus.getValue();
    }
    if (eventTypeIds.size() > 0) {
        for (unsigned i = 0; i < eventTypeIds.size(); ++i) {
            json["eventTypeIds"].append(eventTypeIds[i]);
        };
    }
    if (eventIds.size() > 0) {
        for (unsigned i = 0; i < eventIds.size(); ++i) {
            json["eventIds"].append(eventIds[i]);
        };
    }
    if (marketIds.size() > 0) {
        for (unsigned i = 0; i < marketIds.size(); ++i) {
            json["marketIds"].append(marketIds[i]);
        };
    }
    if (runnerIds.size() > 0) {
        for (unsigned i = 0; i < runnerIds.size(); ++i) {
            json["runnerIds"].append(runnerIds[i].toJson());
        };
    }
    if (betIds.size() > 0) {
        for (unsigned i = 0; i < betIds.size(); ++i) {
            json["betIds"].append(betIds[i]);
        };
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
    if (fromRecord > 0) {
        json["fromRecord"] = fromRecord;
    }
    if (recordCount > 0) {
        json["recordCount"] = recordCount;
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

const std::vector<std::string>& ListClearedOrdersRequest::getEventTypeIds() const {
    return eventTypeIds;
}
void ListClearedOrdersRequest::setEventTypeIds(const std::vector<std::string>& eventTypeIds) {
    this->eventTypeIds = eventTypeIds;
}

const std::vector<std::string>& ListClearedOrdersRequest::getEventIds() const {
    return eventIds;
}
void ListClearedOrdersRequest::setEventIds(const std::vector<std::string>& eventIds) {
    this->eventIds = eventIds;
}

const std::vector<std::string>& ListClearedOrdersRequest::getMarketIds() const {
    return marketIds;
}
void ListClearedOrdersRequest::setMarketIds(const std::vector<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const std::vector<RunnerId>& ListClearedOrdersRequest::getRunnerIds() const {
    return runnerIds;
}
void ListClearedOrdersRequest::setRunnerIds(const std::vector<RunnerId>& runnerIds) {
    this->runnerIds = runnerIds;
}

const std::vector<std::string>& ListClearedOrdersRequest::getBetIds() const {
    return betIds;
}
void ListClearedOrdersRequest::setBetIds(const std::vector<std::string>& betIds) {
    this->betIds = betIds;
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

const uint64_t ListClearedOrdersRequest::getFromRecord() const {
    return fromRecord;
}
void ListClearedOrdersRequest::setFromRecord(const uint64_t fromRecord) {
    this->fromRecord = fromRecord;
}

const uint64_t ListClearedOrdersRequest::getRecordCount() const {
    return recordCount;
}
void ListClearedOrdersRequest::setRecordCount(const uint64_t recordCount) {
    this->recordCount = recordCount;
}


}



