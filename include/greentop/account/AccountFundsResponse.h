/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNTFUNDSRESPONSE_H
#define ACCOUNTFUNDSRESPONSE_H

#include <json/json.h>

#include "greentop/JsonResponse.h"

namespace greentop {

class AccountFundsResponse : public JsonResponse {
    public:

        AccountFundsResponse(const double availableToBetBalance = -1,
            const double exposure = -1,
            const double retainedCommission = -1,
            const double exposureLimit = -1,
            const double discountRate = -1,
            const uint64_t pointsBalance = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getAvailableToBetBalance() const;
        void setAvailableToBetBalance(const double availableToBetBalance);

        const double getExposure() const;
        void setExposure(const double exposure);

        const double getRetainedCommission() const;
        void setRetainedCommission(const double retainedCommission);

        const double getExposureLimit() const;
        void setExposureLimit(const double exposureLimit);

        const double getDiscountRate() const;
        void setDiscountRate(const double discountRate);

        const uint64_t getPointsBalance() const;
        void setPointsBalance(const uint64_t pointsBalance);


    private:
        double availableToBetBalance;
        double exposure;
        double retainedCommission;
        double exposureLimit;
        double discountRate;
        uint64_t pointsBalance;
};

}

#endif // ACCOUNTFUNDSRESPONSE_H


