/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETACCOUNTFUNDSREQUEST_H
#define GETACCOUNTFUNDSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/enum/Wallet.h"

namespace greentop {

class GetAccountFundsRequest : public JsonRequest {
    public:

        GetAccountFundsRequest(const Wallet& wallet = Wallet());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Wallet& getWallet() const;
        void setWallet(const Wallet& wallet);


    private:
        Wallet wallet;
};

}

#endif // GETACCOUNTFUNDSREQUEST_H


