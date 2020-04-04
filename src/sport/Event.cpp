/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/Event.h"

namespace greentop {
namespace sport {


Event::Event(const std::string& id,
    const std::string& name,
    const std::string& countryCode,
    const std::string& timezone,
    const std::string& venue,
    const std::tm& openDate) :
    id(id),
    name(name),
    countryCode(countryCode),
    timezone(timezone),
    venue(venue),
    openDate(openDate) {
}

void Event::fromJson(const Json::Value& json) {
    if (json.isMember("id")) {
        id = json["id"].asString();
    }
    if (json.isMember("name")) {
        name = json["name"].asString();
    }
    if (json.isMember("countryCode")) {
        countryCode = json["countryCode"].asString();
    }
    if (json.isMember("timezone")) {
        timezone = json["timezone"].asString();
    }
    if (json.isMember("venue")) {
        venue = json["venue"].asString();
    }
    if (json.isMember("openDate")) {
        strptime(json["openDate"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &openDate);
    }
}

Json::Value Event::toJson() const {
    Json::Value json(Json::objectValue);
    if (id != "") {
        json["id"] = id;
    }
    if (name != "") {
        json["name"] = name;
    }
    if (countryCode != "") {
        json["countryCode"] = countryCode;
    }
    if (timezone != "") {
        json["timezone"] = timezone;
    }
    if (venue != "") {
        json["venue"] = venue;
    }
    if (openDate.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &openDate);
        json["openDate"] = std::string(buffer);
    }
    return json;
}

bool Event::isValid() const {
    return true;
}

const std::string& Event::getId() const {
    return id;
}
void Event::setId(const std::string& id) {
    this->id = id;
}

const std::string& Event::getName() const {
    return name;
}
void Event::setName(const std::string& name) {
    this->name = name;
}

const std::string& Event::getCountryCode() const {
    return countryCode;
}
void Event::setCountryCode(const std::string& countryCode) {
    this->countryCode = countryCode;
}

const std::string& Event::getTimezone() const {
    return timezone;
}
void Event::setTimezone(const std::string& timezone) {
    this->timezone = timezone;
}

const std::string& Event::getVenue() const {
    return venue;
}
void Event::setVenue(const std::string& venue) {
    this->venue = venue;
}

const std::tm& Event::getOpenDate() const {
    return openDate;
}
void Event::setOpenDate(const std::tm& openDate) {
    this->openDate = openDate;
}


}
}
