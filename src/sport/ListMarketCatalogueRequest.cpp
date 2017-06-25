/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketCatalogueRequest.h"

namespace greentop {

ListMarketCatalogueRequest::ListMarketCatalogueRequest() {
}

ListMarketCatalogueRequest::ListMarketCatalogueRequest(const MarketFilter& filter,
    const std::set<MarketProjection>& marketProjection,
    const MarketSort& sort,
    const Optional<int32_t>& maxResults,
    const std::string& locale) :
    filter(filter),
    marketProjection(marketProjection),
    sort(sort),
    maxResults(maxResults),
    locale(locale) {
}

void ListMarketCatalogueRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("marketProjection")) {
        for (unsigned i = 0; i < json["marketProjection"].size(); ++i) {
            marketProjection.insert(json["marketProjection"][i].asString());
        }
    }
    if (json.isMember("sort")) {
        sort = json["sort"].asString();
    }
    if (json.isMember("maxResults")) {
        maxResults = json["maxResults"].asInt();
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListMarketCatalogueRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (marketProjection.size() > 0) {
        for (std::set<MarketProjection>::const_iterator it = marketProjection.begin(); it != marketProjection.end(); ++it) {
            MarketProjection marketProjection(*it);
            json["marketProjection"].append(marketProjection.getValue());
        }
    }
    if (sort.isValid()) {
        json["sort"] = sort.getValue();
    }
    if (maxResults.isValid()) {
        json["maxResults"] = maxResults.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListMarketCatalogueRequest::isValid() const {
    return filter.isValid() && maxResults.isValid();
}

const MarketFilter& ListMarketCatalogueRequest::getFilter() const {
    return filter;
}
void ListMarketCatalogueRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::set<MarketProjection>& ListMarketCatalogueRequest::getMarketProjection() const {
    return marketProjection;
}
void ListMarketCatalogueRequest::setMarketProjection(const std::set<MarketProjection>& marketProjection) {
    this->marketProjection = marketProjection;
}

const MarketSort& ListMarketCatalogueRequest::getSort() const {
    return sort;
}
void ListMarketCatalogueRequest::setSort(const MarketSort& sort) {
    this->sort = sort;
}

const Optional<int32_t>& ListMarketCatalogueRequest::getMaxResults() const {
    return maxResults;
}
void ListMarketCatalogueRequest::setMaxResults(const Optional<int32_t>& maxResults) {
    this->maxResults = maxResults;
}

const std::string& ListMarketCatalogueRequest::getLocale() const {
    return locale;
}
void ListMarketCatalogueRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



