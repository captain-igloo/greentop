/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTFUNDSRESPONSE_H
#define ACCOUNTFUNDSRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"

namespace greentop {
/**
 * Response for retrieving available to bet.
 */
class AccountFundsResponse : public JsonResponse {
    public:

        AccountFundsResponse(const Optional<double>& availableToBetBalance = Optional<double>(),
            const Optional<double>& exposure = Optional<double>(),
            const Optional<double>& retainedCommission = Optional<double>(),
            const Optional<double>& exposureLimit = Optional<double>(),
            const Optional<double>& discountRate = Optional<double>(),
            const Optional<int32_t>& pointsBalance = Optional<int32_t>(),
            const std::string& wallet = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getAvailableToBetBalance() const;
        void setAvailableToBetBalance(const Optional<double>& availableToBetBalance);

        const Optional<double>& getExposure() const;
        void setExposure(const Optional<double>& exposure);

        const Optional<double>& getRetainedCommission() const;
        void setRetainedCommission(const Optional<double>& retainedCommission);

        const Optional<double>& getExposureLimit() const;
        void setExposureLimit(const Optional<double>& exposureLimit);

        const Optional<double>& getDiscountRate() const;
        void setDiscountRate(const Optional<double>& discountRate);

        const Optional<int32_t>& getPointsBalance() const;
        void setPointsBalance(const Optional<int32_t>& pointsBalance);

        const std::string& getWallet() const;
        void setWallet(const std::string& wallet);


    private:
        /**
         * Amount available to bet.
         */
        Optional<double> availableToBetBalance;
        /**
         * Current exposure.
         */
        Optional<double> exposure;
        /**
         * Sum of retained commission.
         */
        Optional<double> retainedCommission;
        /**
         * Exposure limit.
         */
        Optional<double> exposureLimit;
        /**
         * User Discount Rate.
         */
        Optional<double> discountRate;
        /**
         * The Betfair points balance.
         */
        Optional<int32_t> pointsBalance;
        /**
         * The Betfair wallet name.
         */
        std::string wallet;
};

}

#endif // ACCOUNTFUNDSRESPONSE_H
