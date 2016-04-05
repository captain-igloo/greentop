/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MENU_NODE_H
#define MENU_NODE_H

#include <ctime>
#include <json/json.h>

namespace greentop {
namespace menu {

class Menu;

class Node {

    public:

        enum class Type { UNKNOWN, GROUP, EVENT_TYPE, EVENT, RACE, MARKET };

        Node();

        Node(Menu* menu);

        virtual void fromJson(const Json::Value& json);
        const std::string& getId() const;
        const std::string& getName() const;
        const Node::Type getType() const;
        const std::list<Node>& getChildren() const;
        const unsigned getExchangeId() const;
        const unsigned getNumberOfWinners() const;
        const std::tm& getMarketStartTime() const;
        bool hasParent() const;
        const Node& getParent() const;

    private:
        Menu* menu;
        std::string id;
        std::string name;
        Node::Type type;
        unsigned exchangeId;
        unsigned numberOfWinners;
        std::tm marketStartTime;

};

}
}

std::istream& operator>>(std::istream& is, greentop::menu::Node& node);

#endif // MENU_NODE_H
