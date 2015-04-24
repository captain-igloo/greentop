#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <application-key> <username> <password>" << std::endl;
        return 1;
    }

    ExchangeApi::Exchange exchange = ExchangeApi::Exchange::UK;

    ExchangeApi exchangeApi(argv[1]);

    if (exchangeApi.login(argv[2], argv[3])) {

        GetAccountStatementRequest gasr;
        gasr.setFromRecord(0);

        if (gasr.isValid()) {

            AccountStatementReport asr = exchangeApi.getAccountStatement(exchange, gasr);

            if (asr.isSuccess()) {

                std::vector<StatementItem> items = asr.getAccountStatement();

                for (unsigned i = 0; i < items.size(); ++i) {
                    StatementItem item = items[i];
                    
                    StatementLegacyData legacyData = item.getLegacyData();

                    std::cout << legacyData.getMarketName() << " / " << legacyData.getSelectionName() <<
                        " " << legacyData.getBetType() << " amount: " << legacyData.getBetSize() <<
                        " price: " << legacyData.getAvgPrice() << " " << legacyData.getWinLose() << std::endl;
                }

            } else {
                std::cout << "request failed: " << asr.getFaultCode() << " " << asr.getFaultString() << std::endl;
            }
        } else {
            std::cout << "invalid request" << std::endl;
        }
    } else {
        std::cout << "failed to log in" << std::endl;
    }

    return 0;
}


