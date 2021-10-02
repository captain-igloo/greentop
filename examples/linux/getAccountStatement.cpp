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

        account::GetAccountStatementRequest gasr;
        gasr.setFromRecord(0);

        if (gasr.isValid()) {

            account::AccountStatementReport asr = exchangeApi.getAccountStatement(gasr);

            if (asr.isSuccess()) {

                std::vector<account::StatementItem> items = asr.getAccountStatement();

                for (unsigned i = 0; i < items.size(); ++i) {
                    account::StatementItem item = items[i];

                    account::StatementLegacyData legacyData = item.getLegacyData();

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


