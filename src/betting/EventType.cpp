#include "greentop/betting/EventType.h"

namespace greentop {

EventType::EventType(const std::string& id,
    const std::string& name) :
    id(id),
    name(name) {
}

void EventType::fromJson(const Json::Value& json) {
    if (json.isMember("id")) {
        id = json["id"].asString();
    }
    if (json.isMember("name")) {
        name = json["name"].asString();
    }
}

Json::Value EventType::toJson() const {
    Json::Value json;
    if (id != "") {
        json["id"] = id;
    }
    if (name != "") {
        json["name"] = name;
    }
    return json;
}

bool EventType::isValid() const {
    return true;
}

const std::string& EventType::getId() const {
    return id;
}
void EventType::setId(const std::string& id) {
    this->id = id;
}

const std::string& EventType::getName() const {
    return name;
}
void EventType::setName(const std::string& name) {
    this->name = name;
}


}



