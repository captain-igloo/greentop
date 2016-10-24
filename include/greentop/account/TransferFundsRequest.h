/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TRANSFERFUNDSREQUEST_H
#define TRANSFERFUNDSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/account/enum/Wallet.h"

namespace greentop {

class TransferFundsRequest : public JsonRequest {
    public:
        TransferFundsRequest();

        TransferFundsRequest(const Wallet& from,
            const Wallet& to,
            const double amount);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Wallet& getFrom() const;
        void setFrom(const Wallet& from);

        const Wallet& getTo() const;
        void setTo(const Wallet& to);

        const double getAmount() const;
        void setAmount(const double amount);


    private:
        /**
         * Source wallet
         */
        Wallet from;
        /**
         * Destination wallet
         */
        Wallet to;
        /**
         * Amount to transfer
         */
        double amount;
};

}

#endif // TRANSFERFUNDSREQUEST_H


