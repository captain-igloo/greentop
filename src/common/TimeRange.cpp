/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/common/TimeRange.h"

namespace greentop {


TimeRange::TimeRange(const std::tm& from,
    const std::tm& to) :
    from(from),
    to(to) {
}

void TimeRange::fromJson(const Json::Value& json) {
    if (json.isMember("from")) {
        strptime(json["from"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &from);
    }
    if (json.isMember("to")) {
        strptime(json["to"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &to);
    }
}

Json::Value TimeRange::toJson() const {
    Json::Value json(Json::objectValue);
    if (from.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &from);
        json["from"] = std::string(buffer);
    }
    if (to.tm_year > 0) {
        char buffer[25];
        strftime(buffer, 25,"%Y-%m-%dT%H:%M:%S.000Z", &to);
        json["to"] = std::string(buffer);
    }
    return json;
}

bool TimeRange::isValid() const {
    return true;
}

const std::tm& TimeRange::getFrom() const {
    return from;
}
void TimeRange::setFrom(const std::tm& from) {
    this->from = from;
}

const std::tm& TimeRange::getTo() const {
    return to;
}
void TimeRange::setTo(const std::tm& to) {
    this->to = to;
}


}



