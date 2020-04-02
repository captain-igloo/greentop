/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_LISTCURRENCYRATESREQUEST_H
#define ACCOUNT_LISTCURRENCYRATESREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {
namespace account {

class ListCurrencyRatesRequest : public JsonRequest {
    public:

        ListCurrencyRatesRequest(const std::string& fromCurrency = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getFromCurrency() const;
        void setFromCurrency(const std::string& fromCurrency);


    private:
        /**
         * The currency from which the rates are computed. GBP is used if no value is passed
         */
        std::string fromCurrency;
};

}
}

#endif // ACCOUNT_LISTCURRENCYRATESREQUEST_H
