/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCURRENCYRATESRESPONSE_H
#define LISTCURRENCYRATESRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/CurrencyRate.h"

namespace greentop {

class ListCurrencyRatesResponse : public JsonResponse {
    public:
        ListCurrencyRatesResponse();

        ListCurrencyRatesResponse(const std::vector<CurrencyRate>& currencyRates);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<CurrencyRate>& getCurrencyRates() const;
        void setCurrencyRates(const std::vector<CurrencyRate>& currencyRates);


    private:
        std::vector<CurrencyRate> currencyRates;
};

}

#endif // LISTCURRENCYRATESRESPONSE_H


