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

        sport::MarketFilter filter;
        sport::ListEventTypesRequest req(filter);

        if (req.isValid()) {
            sport::ListEventTypesResponse resp = exchangeApi.listEventTypes(req);

            if (resp.isSuccess()) {

                std::vector<sport::EventTypeResult> eventTypeResults = resp.getEventTypeResults();
                for (unsigned i = 0; i < eventTypeResults.size(); ++i) {
                    sport::EventTypeResult etr = eventTypeResults[i];
                    sport::EventType et = etr.getEventType();
                    std::cout << et.getId() << " " << et.getName() << std::endl;
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


