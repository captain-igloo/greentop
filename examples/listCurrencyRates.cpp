#include <iostream>
#include <vector>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <application-key> <username> <password>" << std::endl;
        return 1;
    }

    Exchange exchange = Exchange::UK;

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        ListCurrencyRatesRequest req("GBP");

        ListCurrencyRatesResponse resp = exchangeApi.listCurrencyRates(exchange, req);

        if (resp.isSuccess()) {

            std::vector<CurrencyRate> rates = resp.getCurrencyRates();

            for (unsigned i = 0; i < rates.size(); ++i) {
                CurrencyRate rate = rates[i];
                std::cout << rate.getCurrencyCode() << " " << rate.getRate() << std::endl;
            }

        }

    }

}


