/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTDETAILSRESPONSE_H
#define ACCOUNTDETAILSRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Response for Account details.
 */
class AccountDetailsResponse : public JsonResponse {
    public:

        AccountDetailsResponse(const std::string& currencyCode = std::string(),
            const std::string& firstName = std::string(),
            const std::string& lastName = std::string(),
            const std::string& localeCode = std::string(),
            const std::string& region = std::string(),
            const std::string& timezone = std::string(),
            const Optional<double>& discountRate = Optional<double>(),
            const Optional<int32_t>& pointsBalance = Optional<int32_t>(),
            const std::string& countryCode = std::string());

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

        const Optional<double>& getDiscountRate() const;
        void setDiscountRate(const Optional<double>& discountRate);

        const Optional<int32_t>& getPointsBalance() const;
        void setPointsBalance(const Optional<int32_t>& pointsBalance);

        const std::string& getCountryCode() const;
        void setCountryCode(const std::string& countryCode);


    private:
        /**
         * Default user currency Code.
         */
        std::string currencyCode;
        /**
         * First Name.
         */
        std::string firstName;
        /**
         * Last Name.
         */
        std::string lastName;
        /**
         * Locale Code.
         */
        std::string localeCode;
        /**
         * Region.
         */
        std::string region;
        /**
         * User Time Zone.
         */
        std::string timezone;
        /**
         * User Discount Rate.
         */
        Optional<double> discountRate;
        /**
         * The Betfair points balance.
         */
        Optional<int32_t> pointsBalance;
        /**
         * Country Code.
         */
        std::string countryCode;
};

}

#endif // ACCOUNTDETAILSRESPONSE_H


