#include "greentop/betting/ListEventsRequest.h"

namespace greentop {
ListEventsRequest::ListEventsRequest() {
}

ListEventsRequest::ListEventsRequest(const MarketFilter& filter,
    const std::string& locale) :
    filter(filter),
    locale(locale) {
}

void ListEventsRequest::fromJson(const Json::Value& json) {
    if (json.isMember("filter")) {
        filter.fromJson(json["filter"]);
    }
    if (json.isMember("locale")) {
        locale = json["locale"].asString();
    }
}

Json::Value ListEventsRequest::toJson() const {
    Json::Value json;
    if (filter.isValid()) {
        json["filter"] = filter.toJson();
    }
    if (locale != "") {
        json["locale"] = locale;
    }
    return json;
}

bool ListEventsRequest::isValid() const {
    return filter.isValid();
}

const MarketFilter& ListEventsRequest::getFilter() const {
    return filter;
}
void ListEventsRequest::setFilter(const MarketFilter& filter) {
    this->filter = filter;
}

const std::string& ListEventsRequest::getLocale() const {
    return locale;
}
void ListEventsRequest::setLocale(const std::string& locale) {
    this->locale = locale;
}


}



