#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <application key> <username> <password> <market id>" << std::endl;
        return 1;
    }

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        std::vector<std::string> marketIds = {argv[4]};
        std::set<sport::PriceData> priceData = {sport::PriceData::EX_BEST_OFFERS};
        sport::PriceProjection priceProjection(priceData);
        sport::OrderProjection orderProjection(sport::OrderProjection::EXECUTABLE);
        sport::MatchProjection matchProjection(sport::MatchProjection::ROLLED_UP_BY_AVG_PRICE);

        sport::ListMarketBookRequest req(marketIds, priceProjection, orderProjection, matchProjection);

        sport::ListMarketBookResponse resp = exchangeApi.listMarketBook(req);

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


