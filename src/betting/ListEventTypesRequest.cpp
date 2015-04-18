/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/ListEventTypesRequest.h"

namespace greentop {
ListEventTypesRequest::ListEventTypesRequest() {
}

ListEventTypesRequest::ListEventTypesRequest(const MarketFilter& filter,
    const std::string& locale) :
    filter(filter),
    locale(locale) {
}

void ListEventTypesRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListEventTypesRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListEventTypesRequest::isValid() const {
    return filter.isValid();
}

const MarketFilter& ListEventTypesRequest::getFilter() const {
    return filter;
}
void ListEventTypesRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::string& ListEventTypesRequest::getLocale() const {
    return locale;
}
void ListEventTypesRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



