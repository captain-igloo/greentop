/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketTypesRequest.h"

namespace greentop {
namespace sport {

ListMarketTypesRequest::ListMarketTypesRequest() {
}

ListMarketTypesRequest::ListMarketTypesRequest(const MarketFilter& filter,
    const std::string& locale) :
    filter(filter),
    locale(locale) {
}

void ListMarketTypesRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListMarketTypesRequest::toJson() const {
    Json::Value json(Json::objectValue);
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListMarketTypesRequest::isValid() const {
    return filter.isValid();
}

const MarketFilter& ListMarketTypesRequest::getFilter() const {
    return filter;
}
void ListMarketTypesRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::string& ListMarketTypesRequest::getLocale() const {
    return locale;
}
void ListMarketTypesRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}
}
