/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CURRENCYRATE_H
#define CURRENCYRATE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Currency rate
 */
class CurrencyRate : public JsonMember {
    public:

        CurrencyRate(const std::string& currencyCode = std::string(),
            const Optional<double>& rate = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCurrencyCode() const;
        void setCurrencyCode(const std::string& currencyCode);

        const Optional<double>& getRate() const;
        void setRate(const Optional<double>& rate);


    private:
        /**
         * Three letter ISO 4217 code
         */
        std::string currencyCode;
        /**
         * Exchange rate for the currency specified in the request
         */
        Optional<double> rate;
};

}

#endif // CURRENCYRATE_H


