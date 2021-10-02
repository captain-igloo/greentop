#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <application key> <username> <password> <event type id>" << std::endl;
        return 1;
    }

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        sport::MarketFilter filter;
        std::set<std::string> eventTypeIds = {argv[4]};
        filter.setEventTypeIds(eventTypeIds);
        sport::ListCompetitionsRequest req(filter);

        if (req.isValid()) {

            sport::ListCompetitionsResponse resp = exchangeApi.listCompetitions(req);

            if (resp.isSuccess()) {

                std::vector<sport::CompetitionResult> competitionResults = resp.getCompetitionResults();

                for (unsigned i = 0; i < competitionResults.size(); ++i) {
                    sport::Competition competition = competitionResults[i].getCompetition();
                    std::cout << competition.getId() << " " << competition.getName() << std::endl;
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


