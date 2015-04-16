#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

bool login(ExchangeApi& exchangeApi, const std::string& username, const std::string& password) {

    std::cout << "Logging in ... ";

    if (exchangeApi.login(username, password)) {
        std::cout << "SUCCESS" << std::endl << std::endl;
        return true;
    }

    std::cout << "FAILED" << std::endl << std::endl;

    return false;
}

void listEventTypes(ExchangeApi& exchangeApi, ExchangeApi::Exchange exchange) {

    MarketFilter filter;
    ListEventTypesRequest req(filter);

    std::cout << "EVENT TYPES" << std::endl << std::endl;

    if (req.isValid()) {
        ListEventTypesResponse resp = exchangeApi.listEventTypes(exchange, req);

        if (resp.isSuccess()) {

            std::vector<EventTypeResult> eventTypeResults = resp.getEventTypeResults();
            for (unsigned i = 0; i < eventTypeResults.size(); ++i) {
                EventTypeResult etr = eventTypeResults[i];
                EventType et = etr.getEventType();
                std::cout << et.getName() << std::endl;
            }

        } else {
            std::cout << "request failed: " << resp.getFaultCode() << " " << resp.getFaultString() << std::endl;
        }
    } else {
        std::cout << "invalid request: " << req.toString() << std::endl;
    }

    std::cout << std::endl;

}

void listCompetitions(ExchangeApi& exchangeApi, ExchangeApi::Exchange exchange, std::string& eventTypeId) {

    MarketFilter filter;
    std::set<std::string> eventTypeIds = {eventTypeId};
    filter.setEventTypeIds(eventTypeIds);
    ListCompetitionsRequest req(filter);

    std::cout << "COMPETITIONS" << std::endl << std::endl;

    if (req.isValid()) {

        ListCompetitionsResponse resp = exchangeApi.listCompetitions(exchange, req);

        if (resp.isSuccess()) {

            std::vector<CompetitionResult> competitionResults = resp.getCompetitionResults();

            for (unsigned i = 0; i < competitionResults.size(); ++i) {
                Competition competition = competitionResults[i].getCompetition();
                std::cout << competition.getName() << std::endl;
            }

        } else {
            std::cout << "request failed: " << resp.getFaultCode() << " " << resp.getFaultString() << std::endl;
        }
    } else {
        std::cout << "invalid request: " << req.toString() << std::endl;
    }

    std::cout << std::endl;

}

void listEvents(ExchangeApi& exchangeApi, ExchangeApi::Exchange exchange, std::string& eventTypeId) {

    MarketFilter filter;
    std::set<std::string> eventTypeIds = {eventTypeId};
    filter.setEventTypeIds(eventTypeIds);
    filter.setInPlayOnly(true);
    ListEventsRequest req(filter);

    std::cout << "EVENTS" << std::endl << std::endl;

    // std::cout << req.toString() << std::endl;

    if (req.isValid()) {

        ListEventsResponse resp = exchangeApi.listEvents(exchange, req);

        if (resp.isSuccess()) {

            std::vector<EventResult> eventResults = resp.getEventResults();

            for (unsigned i = 0; i < eventResults.size() && i < 10; ++i) {
                Event event = eventResults[i].getEvent();
                std::cout << event.getName() << std::endl;
            }

        } else {
            std::cout << "request failed: " << resp.getFaultCode() << " " << resp.getFaultString() << std::endl;
        }
    } else {
        std::cout << "invalid request: " << req.toString() << std::endl;
    }

    std::cout << std::endl;

}

void listMarketCatalogue(ExchangeApi& exchangeApi, ExchangeApi::Exchange exchange, std::string& eventTypeId) {

    MarketFilter filter;
    std::set<std::string> eventTypeIds = {eventTypeId};
    filter.setEventTypeIds(eventTypeIds);
    filter.setInPlayOnly(true);

    std::set<MarketProjection> marketProjection = {MarketProjection::RUNNER_DESCRIPTION};

    ListMarketCatalogueRequest req1(filter, marketProjection);
    req1.setMaxResults(1);

    std::cout << "MARKET" << std::endl << std::endl;

    if (req1.isValid()) {

        ListMarketCatalogueResponse resp = exchangeApi.listMarketCatalogue(exchange, req1);

        if (resp.isSuccess()) {

            std::vector<MarketCatalogue> marketCatalogues = resp.getMarketCatalogues();

            for (unsigned i = 0; i < marketCatalogues.size(); ++i) {
                std::cout << marketCatalogues[i].getMarketName() << std::endl << std::endl;

                std::set<std::string> marketIds = {marketCatalogues[i].getMarketId()};

                std::set<PriceData> priceData = {PriceData::EX_BEST_OFFERS};
                PriceProjection priceProjection(priceData);
                OrderProjection orderProjection(OrderProjection::EXECUTABLE);
                MatchProjection matchProjection(MatchProjection::ROLLED_UP_BY_AVG_PRICE);

                ListMarketBookRequest req2(marketIds, priceProjection, orderProjection, matchProjection);

                ListMarketBookResponse resp2 = exchangeApi.listMarketBook(exchange, req2);

                std::vector<RunnerCatalog> runners = marketCatalogues[i].getRunners();
                for (unsigned i = 0; i < runners.size(); ++i) {
                    std::cout << runners[i].getRunnerName();

                    for (std::vector<MarketBook>::const_iterator mbIt = resp2.getMarketBooks().begin(); mbIt != resp2.getMarketBooks().end(); ++mbIt) {
                        MarketBook marketBook = *mbIt;
                        for (std::vector<Runner>::const_iterator it = marketBook.getRunners().begin(); it != marketBook.getRunners().end(); ++it) {
                            Runner runner = *it;
                            if (runners[i].getSelectionId() == runner.getSelectionId()) {

                                if (runner.getEx().getAvailableToBack().size() >= 1) {
                                    std::cout << " " << runner.getEx().getAvailableToBack()[0].getPrice();
                                }

                            }
                        }
                    }

                    std::cout << std::endl;
                }

            }

        } else {
            std::cout << "request failed: " << resp.getFaultCode() << " " << resp.getFaultString() << std::endl;
        }
    } else {
        std::cout << "invalid request: " << req1.toString() << std::endl;
    }

}

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <application-key> <username> <password>" << std::endl;
        return 1;
    }

    ExchangeApi::Exchange exchange = ExchangeApi::Exchange::UK;

    ExchangeApi exchangeApi(argv[1]);
    // football
    std::string eventTypeId = "1";

    if (login(exchangeApi, argv[2], argv[3])) {

        listEventTypes(exchangeApi, exchange);

        listCompetitions(exchangeApi, exchange, eventTypeId);

        listEvents(exchangeApi, exchange, eventTypeId);

        listMarketCatalogue(exchangeApi, exchange, eventTypeId);

    }

    return 0;

}
