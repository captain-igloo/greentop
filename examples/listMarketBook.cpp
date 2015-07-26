#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <application key> <username> <password> <market id>" << std::endl;
        return 1;
    }

    ExchangeApi::Exchange exchange = ExchangeApi::Exchange::AUS;

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        std::set<std::string> marketIds = {argv[4]};
        std::set<PriceData> priceData = {PriceData::EX_BEST_OFFERS};
        PriceProjection priceProjection(priceData);
        OrderProjection orderProjection(OrderProjection::EXECUTABLE);
        MatchProjection matchProjection(MatchProjection::ROLLED_UP_BY_AVG_PRICE);

        ListMarketBookRequest req(marketIds, priceProjection, orderProjection, matchProjection);

        ListMarketBookResponse resp = exchangeApi.listMarketBook(exchange, req);

        if (resp.isSuccess()) {

            for (auto &marketBook : resp.getMarketBooks()) {

                for (auto &runner : marketBook.getRunners()) {

                    if (runner.getEx().getAvailableToBack().size() >= 1) {
                        std::cout << runner.getSelectionId() << " "
                            << runner.getEx().getAvailableToBack()[0].getPrice() << std::endl;
                    }

                }
            }

        } else {
            std::cout << "request failed: " << resp.getFaultCode() << " " << resp.getFaultString() << std::endl;
        }

    } else {
        std::cout << "failed to log in" << std::endl;
    }

}


