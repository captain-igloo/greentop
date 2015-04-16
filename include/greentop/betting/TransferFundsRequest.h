#ifndef TRANSFERFUNDSREQUEST_H
#define TRANSFERFUNDSREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/enum/Wallet.h"

namespace greentop {

class TransferFundsRequest : public JsonRequest {
    public:

        TransferFundsRequest(const Wallet& from = Wallet(),
            const Wallet& to = Wallet(),
            const double amount = -1);

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
        Wallet from;
        Wallet to;
        double amount;
};

}

#endif // TRANSFERFUNDSREQUEST_H


