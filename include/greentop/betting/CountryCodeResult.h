#ifndef COUNTRYCODERESULT_H
#define COUNTRYCODERESULT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class CountryCodeResult : public JsonMember {
    public:

        CountryCodeResult(const std::string& countryCode = std::string(),
            const uint64_t marketCount = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCountryCode() const;
        void setCountryCode(const std::string& countryCode);

        const uint64_t getMarketCount() const;
        void setMarketCount(const uint64_t marketCount);


    private:
        std::string countryCode;
        uint64_t marketCount;
};

}

#endif // COUNTRYCODERESULT_H


