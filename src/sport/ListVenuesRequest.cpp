/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListVenuesRequest.h"

namespace greentop {

ListVenuesRequest::ListVenuesRequest() {
}

ListVenuesRequest::ListVenuesRequest(const MarketFilter& filter,
    const std::string& locale) :
    filter(filter),
    locale(locale) {
}

void ListVenuesRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListVenuesRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListVenuesRequest::isValid() const {
    return filter.isValid();
}

const MarketFilter& ListVenuesRequest::getFilter() const {
    return filter;
}
void ListVenuesRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::string& ListVenuesRequest::getLocale() const {
    return locale;
}
void ListVenuesRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



