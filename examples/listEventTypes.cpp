#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <application-key> <username> <password>" << std::endl;
        return 1;
    }

    Exchange exchange = Exchange::AUS;

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        MarketFilter filter;
        ListEventTypesRequest req(filter);

        if (req.isValid()) {
            ListEventTypesResponse resp = exchangeApi.listEventTypes(exchange, req);

            if (resp.isSuccess()) {

                std::vector<EventTypeResult> eventTypeResults = resp.getEventTypeResults();
                for (unsigned i = 0; i < eventTypeResults.size(); ++i) {
                    EventTypeResult etr = eventTypeResults[i];
                    EventType et = etr.getEventType();
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


