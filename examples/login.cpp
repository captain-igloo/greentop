#include <iostream>

#include "greentop/ExchangeApi.h"

using namespace greentop;

int main(int argc, char* argv[]) {
 
    if (argc != 3 && argc != 4 && argc != 5) {
        std::cerr << "Usage: " << std::endl << argv[0] << " <application key> <username> <password>" << std::endl
            << " OR" << std::endl
            << argv[0] << " <username> <password> <certificate filename> <key filename>" << std::endl
            << " OR" << std::endl
            << argv[0] << " <application key> <SSO token>" << std::endl;
        return 1;
    }

    bool result = false;
    
    if (argc == 3) {
        // login has been performed by some other means eg using the "interactive login" described in the documentation.
        ExchangeApi exchangeApi(argv[1]);
        exchangeApi.setSsoid(argv[2]);
        // we don't know whether or not the token is valid, assume it is.
        result = true;
    } else if (argc == 4) {
        ExchangeApi exchangeApi(argv[1]);
        result = exchangeApi.login(argv[2], argv[3]);
    } else if (argc == 5) {
        ExchangeApi exchangeApi;
        result = exchangeApi.login(argv[1], argv[2], argv[3], argv[4]);
    }
    
    if (result) {
        std::cerr << "SUCCESS" << std::endl;
    } else {
        std::cerr << "FAILED" << std::endl;
    }
    
    return 0;
}