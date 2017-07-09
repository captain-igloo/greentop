#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <application key> <username> <password> <event id>" << std::endl;
        return 1;
    }

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        MarketFilter filter;
        std::set<std::string> eventIds = {argv[4]};
        filter.setEventIds(eventIds);

        std::set<MarketProjection> marketProjection = {MarketProjection::RUNNER_DESCRIPTION, MarketProjection::MARKET_START_TIME};
        ListMarketCatalogueRequest req(filter, marketProjection);
        req.setMaxResults(1000);

        if (req.isValid()) {

            ListMarketCatalogueResponse resp = exchangeApi.listMarketCatalogue(req);

            if (resp.isSuccess()) {

                std::vector<MarketCatalogue> marketCatalogues = resp.getMarketCatalogues();

                for (unsigned i = 0; i < marketCatalogues.size(); ++i) {
                    std::cout << marketCatalogues[i].getMarketId() << " " << marketCatalogues[i].getMarketName() << std::endl;
                }

            } else {
                std::cout << "request failed: " << resp.getFaultCode() << " " << resp.getFaultString() << std::endl;
            }
        } else {
            std::cout << "invalid request: " << req.toString() << std::endl;
        }

    } else {
        std::cout << "failed to log in" << std::endl;
    }

}


