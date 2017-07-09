#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <application-key> <username> <password>" << std::endl;
        return 1;
    }

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        BetStatus betStatus(BetStatus::SETTLED);

        ListClearedOrdersRequest req(betStatus);
        req.setFromRecord(0);
        req.setRecordCount(5);

        if (req.isValid()) {

            ClearedOrderSummaryReport resp = exchangeApi.listClearedOrders(req);

            if (resp.isSuccess()) {

                std::vector<ClearedOrderSummary> clearedOrders = resp.getClearedOrders();

                for (unsigned i = 0; i < clearedOrders.size(); ++i) {
                    std::cout << "Bet id: " << clearedOrders[i].getBetId() << std::endl;
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

