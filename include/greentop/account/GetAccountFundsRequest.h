/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETACCOUNTFUNDSREQUEST_H
#define ACCOUNT_GETACCOUNTFUNDSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/account/enum/Wallet.h"

namespace greentop {
namespace account {

class GetAccountFundsRequest : public JsonRequest {
    public:

        GetAccountFundsRequest(const Wallet& wallet = Wallet());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Wallet& getWallet() const;
        void setWallet(const Wallet& wallet);


    private:
        /**
         * Name of the wallet in question.
         */
        Wallet wallet;
};

}
}

#endif // ACCOUNT_GETACCOUNTFUNDSREQUEST_H
