/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListCurrentOrdersRequest.h"

namespace greentop {
namespace sport {


ListCurrentOrdersRequest::ListCurrentOrdersRequest(const std::set<std::string>& betIds,
    const std::set<std::string>& marketIds,
    const OrderProjection& orderProjection,
    const std::set<std::string>& customerOrderRefs,
    const std::set<std::string>& customerStrategyRefs,
    const common::TimeRange& placedDateRange,
    const common::TimeRange& dateRange,
    const OrderBy& orderBy,
    const SortDir& sortDir,
    const Optional<int32_t>& fromRecord,
    const Optional<int32_t>& recordCount) :
    betIds(betIds),
    marketIds(marketIds),
    orderProjection(orderProjection),
    customerOrderRefs(customerOrderRefs),
    customerStrategyRefs(customerStrategyRefs),
    placedDateRange(placedDateRange),
    dateRange(dateRange),
    orderBy(orderBy),
    sortDir(sortDir),
    fromRecord(fromRecord),
    recordCount(recordCount) {
}

void ListCurrentOrdersRequest::fromJson(const Json::Value& json) {
    if (json.isMember("betIds")) {
        for (unsigned i = 0; i < json["betIds"].size(); ++i) {
            betIds.insert(json["betIds"][i].asString());
        }
    }
    if (json.isMember("marketIds")) {
        for (unsigned i = 0; i < json["marketIds"].size(); ++i) {
            marketIds.insert(json["marketIds"][i].asString());
        }
    }
    if (json.isMember("orderProjection")) {
        orderProjection = json["orderProjection"].asString();
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
    if (json.isMember("placedDateRange")) {
        placedDateRange.fromJson(json["placedDateRange"]);
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
        for (std::set<std::string>::const_iterator it = betIds.begin(); it != betIds.end(); ++it) {
            json["betIds"].append(*it);
        }
    }
    if (marketIds.size() > 0) {
        for (std::set<std::string>::const_iterator it = marketIds.begin(); it != marketIds.end(); ++it) {
            json["marketIds"].append(*it);
        }
    }
    if (orderProjection.isValid()) {
        json["orderProjection"] = orderProjection.getValue();
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
    if (placedDateRange.isValid()) {
        json["placedDateRange"] = placedDateRange.toJson();
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
    if (fromRecord.isValid()) {
        json["fromRecord"] = fromRecord.toJson();
    }
    if (recordCount.isValid()) {
        json["recordCount"] = recordCount.toJson();
    }
    return json;
}

bool ListCurrentOrdersRequest::isValid() const {
    return true;
}

const std::set<std::string>& ListCurrentOrdersRequest::getBetIds() const {
    return betIds;
}
void ListCurrentOrdersRequest::setBetIds(const std::set<std::string>& betIds) {
    this->betIds = betIds;
}

const std::set<std::string>& ListCurrentOrdersRequest::getMarketIds() const {
    return marketIds;
}
void ListCurrentOrdersRequest::setMarketIds(const std::set<std::string>& marketIds) {
    this->marketIds = marketIds;
}

const OrderProjection& ListCurrentOrdersRequest::getOrderProjection() const {
    return orderProjection;
}
void ListCurrentOrdersRequest::setOrderProjection(const OrderProjection& orderProjection) {
    this->orderProjection = orderProjection;
}

const std::set<std::string>& ListCurrentOrdersRequest::getCustomerOrderRefs() const {
    return customerOrderRefs;
}
void ListCurrentOrdersRequest::setCustomerOrderRefs(const std::set<std::string>& customerOrderRefs) {
    this->customerOrderRefs = customerOrderRefs;
}

const std::set<std::string>& ListCurrentOrdersRequest::getCustomerStrategyRefs() const {
    return customerStrategyRefs;
}
void ListCurrentOrdersRequest::setCustomerStrategyRefs(const std::set<std::string>& customerStrategyRefs) {
    this->customerStrategyRefs = customerStrategyRefs;
}

const common::TimeRange& ListCurrentOrdersRequest::getPlacedDateRange() const {
    return placedDateRange;
}
void ListCurrentOrdersRequest::setPlacedDateRange(const common::TimeRange& placedDateRange) {
    this->placedDateRange = placedDateRange;
}

const common::TimeRange& ListCurrentOrdersRequest::getDateRange() const {
    return dateRange;
}
void ListCurrentOrdersRequest::setDateRange(const common::TimeRange& dateRange) {
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

const Optional<int32_t>& ListCurrentOrdersRequest::getFromRecord() const {
    return fromRecord;
}
void ListCurrentOrdersRequest::setFromRecord(const Optional<int32_t>& fromRecord) {
    this->fromRecord = fromRecord;
}

const Optional<int32_t>& ListCurrentOrdersRequest::getRecordCount() const {
    return recordCount;
}
void ListCurrentOrdersRequest::setRecordCount(const Optional<int32_t>& recordCount) {
    this->recordCount = recordCount;
}


}
}
