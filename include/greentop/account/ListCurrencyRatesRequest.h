/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCURRENCYRATESREQUEST_H
#define LISTCURRENCYRATESREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

class ListCurrencyRatesRequest : public JsonRequest {
    public:

        ListCurrencyRatesRequest(const std::string& fromCurrency = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getFromCurrency() const;
        void setFromCurrency(const std::string& fromCurrency);


    private:
        std::string fromCurrency;
};

}

#endif // LISTCURRENCYRATESREQUEST_H


