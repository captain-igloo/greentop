#include <iostream>
#include <fstream>

#include "greentop/ExchangeApi.h"

#include "greentop/menu/Menu.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <application key> <username> <password>" << std::endl;
        return 1;
    }

    ExchangeApi::Exchange exchange = ExchangeApi::Exchange::AUS;

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        std::string filename = "menu.json";
        exchangeApi.refreshMenu(filename);

        std::list<menu::Node> children = exchangeApi.getMenu().getRootNode().getChildren();

        for (auto it1 = children.begin(); it1 != children.end(); ++it1) {
            std::cout << it1->getName() << std::endl;

            std::list<menu::Node> grandChildren = it1->getChildren();

            for (auto it2 = grandChildren.begin(); it2 != grandChildren.end(); ++it2) {
                std::cout << "    " << it2->getName() << std::endl;
            }
        }

    } else {
        std::cout << "failed to log in" << std::endl;
    }

}



