/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListCountriesRequest.h"

namespace greentop {

ListCountriesRequest::ListCountriesRequest() {
}

ListCountriesRequest::ListCountriesRequest(const MarketFilter& filter,
    const std::string& locale) :
    filter(filter),
    locale(locale) {
}

void ListCountriesRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListCountriesRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListCountriesRequest::isValid() const {
    return filter.isValid();
}

const MarketFilter& ListCountriesRequest::getFilter() const {
    return filter;
}
void ListCountriesRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::string& ListCountriesRequest::getLocale() const {
    return locale;
}
void ListCountriesRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



