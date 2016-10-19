/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListCompetitionsRequest.h"

namespace greentop {

ListCompetitionsRequest::ListCompetitionsRequest() {
}

ListCompetitionsRequest::ListCompetitionsRequest(const MarketFilter& filter,
    const std::string& locale) :
    filter(filter),
    locale(locale) {
}

void ListCompetitionsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListCompetitionsRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListCompetitionsRequest::isValid() const {
    return filter.isValid();
}

const MarketFilter& ListCompetitionsRequest::getFilter() const {
    return filter;
}
void ListCompetitionsRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::string& ListCompetitionsRequest::getLocale() const {
    return locale;
}
void ListCompetitionsRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



