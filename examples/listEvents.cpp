#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <application key> <username> <password> <competition id>" << std::endl;
        return 1;
    }

    ExchangeApi::Exchange exchange = ExchangeApi::Exchange::AUS;

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        MarketFilter filter;
        std::set<std::string> competitionIds = {argv[4]};
        filter.setCompetitionIds(competitionIds);
        ListEventsRequest req(filter);

        if (req.isValid()) {

            ListEventsResponse resp = exchangeApi.listEvents(exchange, req);

            if (resp.isSuccess()) {

                std::vector<EventResult> eventResults = resp.getEventResults();

                for (unsigned i = 0; i < eventResults.size() && i < 10; ++i) {
                    Event event = eventResults[i].getEvent();
                    std::cout << event.getId() << " " << event.getName() << std::endl;
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


