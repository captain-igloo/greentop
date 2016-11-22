/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MENU_MENU_H
#define MENU_MENU_H

#include <json/json.h>
#include <list>
#include <set>

#include "greentop/menu/Node.h"
#include "greentop/LRUCache.h"

namespace greentop {
namespace menu {

class Menu {
    public:
        Menu();

        void fromJson(const Json::Value& json);

        void fromJson(const std::string& json);

        void addNode(const Node& node);

        void addChild(const Node& parentNode, const Node& childNode);

        void removeChildren(const Node& parentNode);

        const std::list<Node>& getChildren(const Node& node) const;

        const Node& getParent(const Node& childNode) const;

        bool hasParent(const Node& childNode) const;

        const Node& getRootNode() const;

        bool hasChild(const Node& parentNode, const Node& childNode);

    protected:
    private:
        Node root;
        std::map<std::string, std::list<Node> > children;
        std::map<std::string, Node*> parents;
        LRUCache<std::string, std::set<std::string>> childrenCache;

        const std::string makeNodeId(const Node& node) const;
        void addParent(Node* parentNode);
};

}
}

#endif // MENU_MENU_H
