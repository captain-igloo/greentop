/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef COUNTRYCODERESULT_H
#define COUNTRYCODERESULT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * CountryCode Result
 */
class CountryCodeResult : public JsonMember {
    public:

        CountryCodeResult(const std::string& countryCode = std::string(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCountryCode() const;
        void setCountryCode(const std::string& countryCode);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        /**
         * Country Code
         */
        std::string countryCode;
        /**
         * Count of markets associated with this Country Code
         */
        Optional<int32_t> marketCount;
};

}

#endif // COUNTRYCODERESULT_H


