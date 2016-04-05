/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include <json/json.h>
#include <stdexcept>

#include "greentop/menu/Menu.h"
#include "greentop/menu/Node.h"

namespace greentop {
namespace menu {

Node::Node() {
}

Node::Node(Menu* menu) : menu(menu) {
}

void Node::fromJson(const Json::Value& json) {

    id = "";
    if (json.isMember("id")) {
        id = json["id"].asString();
    }

    name = "";
    if (json.isMember("name")) {
        name = json["name"].asString();
    }

    exchangeId = -1;
    if (json.isMember("exchangeId")) {
        std::string id = json["exchangeId"].asString();
        exchangeId = atoi(id.c_str());
    }

    numberOfWinners = 0;
    if (json.isMember("numberOfWinners")) {
        std::string s = json["numberOfWinners"].asString();
        numberOfWinners = atoi(s.c_str());
    }

    if (json.isMember("marketStartTime")) {
        strptime(json["marketStartTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &marketStartTime);
    }

    type = Node::Type::UNKNOWN;
    if (json.isMember("type")) {
        std::string jsonType = json["type"].asString();

        if (jsonType == "GROUP") {
            type = Node::Type::GROUP;
        } else if (jsonType == "EVENT_TYPE") {
            type = Node::Type::EVENT_TYPE;
        } else if (jsonType == "EVENT") {
            type = Node::Type::EVENT;
        } else if (jsonType == "RACE") {
            type = Node::Type::RACE;
        } else if (jsonType == "MARKET") {
            type = Node::Type::MARKET;
        } else {
            throw std::runtime_error("Invalid type: " + jsonType);
        }
    }

    menu->removeChildren(*this);
    if (json.isMember("children")) {
        for (unsigned i = 0; i < json["children"].size(); ++i) {
            Node node(menu);
            node.fromJson(json["children"][i]);
            menu->addChild(*this, node);
        }
    }

}

const std::string& Node::getId() const {
    return id;
}

const std::string& Node::getName() const {
    return name;
}

const Node::Type Node::getType() const {
    return type;
}

const unsigned Node::getExchangeId() const {
    return exchangeId;
}

const unsigned Node::getNumberOfWinners() const {
    return numberOfWinners;
}

const std::tm& Node::getMarketStartTime() const {
    return marketStartTime;
}

const std::list<Node>& Node::getChildren() const {
    return menu->getChildren(*this);
}

bool Node::hasParent() const {
    return menu->hasParent(*this);
}

const Node& Node::getParent() const {
    return menu->getParent(*this);
}

}
}

std::istream& operator>>(std::istream& is, greentop::menu::Node& node) {
    Json::Value json;
    is >> json;
    node.fromJson(json);
    return is;
}
