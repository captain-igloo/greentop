#ifndef CURRENCYRATE_H
#define CURRENCYRATE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class CurrencyRate : public JsonMember {
    public:

        CurrencyRate(const std::string& currencyCode = std::string(),
            const double rate = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCurrencyCode() const;
        void setCurrencyCode(const std::string& currencyCode);

        const double getRate() const;
        void setRate(const double rate);


    private:
        std::string currencyCode;
        double rate;
};

}

#endif // CURRENCYRATE_H


