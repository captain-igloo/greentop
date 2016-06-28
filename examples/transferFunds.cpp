#include <iostream>

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

        Wallet from(Wallet::UK);
        Wallet to(Wallet::AUSTRALIAN);

        // transfer 10 from UK wallet to AUS wallet
        TransferFundsRequest req(from, to, 10);

        if (req.isValid()) {

            TransferResponse resp = exchangeApi.transferFunds(exchange, req);

            if (resp.isSuccess()) {

                std::cout << "Transaction id: " << resp.getTransactionId() << std::endl;

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




