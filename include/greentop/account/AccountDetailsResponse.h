#ifndef ACCOUNTDETAILSRESPONSE_H
#define ACCOUNTDETAILSRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {

class AccountDetailsResponse : public JsonResponse {
    public:

        AccountDetailsResponse(const std::string& currencyCode = std::string(),
            const std::string& firstName = std::string(),
            const std::string& lastName = std::string(),
            const std::string& localeCode = std::string(),
            const std::string& region = std::string(),
            const std::string& timezone = std::string(),
            const double discountRate = -1,
            const uint64_t pointsBalance = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getCurrencyCode() const;
        void setCurrencyCode(const std::string& currencyCode);

        const std::string& getFirstName() const;
        void setFirstName(const std::string& firstName);

        const std::string& getLastName() const;
        void setLastName(const std::string& lastName);

        const std::string& getLocaleCode() const;
        void setLocaleCode(const std::string& localeCode);

        const std::string& getRegion() const;
        void setRegion(const std::string& region);

        const std::string& getTimezone() const;
        void setTimezone(const std::string& timezone);

        const double getDiscountRate() const;
        void setDiscountRate(const double discountRate);

        const uint64_t getPointsBalance() const;
        void setPointsBalance(const uint64_t pointsBalance);


    private:
        std::string currencyCode;
        std::string firstName;
        std::string lastName;
        std::string localeCode;
        std::string region;
        std::string timezone;
        double discountRate;
        uint64_t pointsBalance;
};

}

#endif // ACCOUNTDETAILSRESPONSE_H


