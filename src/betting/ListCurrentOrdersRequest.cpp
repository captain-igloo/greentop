/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ListCurrentOrdersRequest.h"

namespace greentop {

ListCurrentOrdersRequest::ListCurrentOrdersRequest(const std::vector<std::string>& betIds,
    const std::vector<std::string>& marketIds,
    const OrderProjection& orderProjection,
    const TimeRange& dateRange,
    const OrderBy& orderBy,
    const SortDir& sortDir,
    const int fromRecord,
    const int recordCount) :
    betIds(betIds),
    marketIds(marketIds),
    orderProjection(orderProjection),
    dateRange(dateRange),
    orderBy(orderBy),
    sortDir(sortDir),
    fromRecord(fromRecord),
    recordCount(recordCount) {
}

void ListCurrentOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("betIds")) {
        for (unsigned i = 0; i < json["betIds"].size(); ++i) {
            betIds.push_back(json["betIds"][i].asString());
        };
    }
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.push_back(json["marketIds"][i].asString());
        };
    }
    if (json.isMember("orderProjection")) {
        orderProjection = json["orderProjection"].asString();
    }
    if (json.isMember("dateRange")) {
        dateRange.fromJson(json["dateRange"]);
    }
    if (json.isMember("orderBy")) {
        orderBy = json["orderBy"].asString();
    }
    if (json.isMember("sortDir")) {
        sortDir = json["sortDir"].asString();
    }
    if (json.isMember("fromRecord")) {
        fromRecord = json["fromRecord"].asInt();
    }
    if (json.isMember("recordCount")) {
        recordCount = json["recordCount"].asInt();
    }
}

Json::Value ListCurrentOrdersRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (betIds.size() > 0) {
        for (unsigned i = 0; i < betIds.size(); ++i) {
            json["betIds"].append(betIds[i]);
        };
    }
    if (marketIds.size() > 0) {
        for (unsigned i = 0; i < marketIds.size(); ++i) {
            json["marketIds"].append(marketIds[i]);
        };
    }
    if (orderProjection.isValid()) {
        json["orderProjection"] = orderProjection.getValue();
    }
    if (dateRange.isValid()) {
        json["dateRange"] = dateRange.toJson();
    }
    if (orderBy.isValid()) {
        json["orderBy"] = orderBy.getValue();
    }
    if (sortDir.isValid()) {
        json["sortDir"] = sortDir.getValue();
    }
    if (fromRecord >= 0) {
        json["fromRecord"] = fromRecord;
    }
    if (recordCount >= 0) {
        json["recordCount"] = recordCount;
    }
    return json;
}

bool ListCurrentOrdersRequest::isValid() const {
    return true;
}

const std::vector<std::string>& ListCurrentOrdersRequest::getBetIds() const {
    return betIds;
}
void ListCurrentOrdersRequest::setBetIds(const std::vector<std::string>& betIds) {
    this->betIds = betIds;
}

const std::vector<std::string>& ListCurrentOrdersRequest::getMarketIds() const {
    return marketIds;
}
void ListCurrentOrdersRequest::setMarketIds(const std::vector<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const OrderProjection& ListCurrentOrdersRequest::getOrderProjection() const {
    return orderProjection;
}
void ListCurrentOrdersRequest::setOrderProjection(const OrderProjection& orderProjection) {
    this->orderProjection = orderProjection;
}

const TimeRange& ListCurrentOrdersRequest::getDateRange() const {
    return dateRange;
}
void ListCurrentOrdersRequest::setDateRange(const TimeRange& dateRange) {
    this->dateRange = dateRange;
}

const OrderBy& ListCurrentOrdersRequest::getOrderBy() const {
    return orderBy;
}
void ListCurrentOrdersRequest::setOrderBy(const OrderBy& orderBy) {
    this->orderBy = orderBy;
}

const SortDir& ListCurrentOrdersRequest::getSortDir() const {
    return sortDir;
}
void ListCurrentOrdersRequest::setSortDir(const SortDir& sortDir) {
    this->sortDir = sortDir;
}

const int ListCurrentOrdersRequest::getFromRecord() const {
    return fromRecord;
}
void ListCurrentOrdersRequest::setFromRecord(const int fromRecord) {
    this->fromRecord = fromRecord;
}

const int ListCurrentOrdersRequest::getRecordCount() const {
    return recordCount;
}
void ListCurrentOrdersRequest::setRecordCount(const int recordCount) {
    this->recordCount = recordCount;
}


}



