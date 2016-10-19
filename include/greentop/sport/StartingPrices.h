/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STARTINGPRICES_H
#define STARTINGPRICES_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/PriceSize.h"

namespace greentop {

class StartingPrices : public JsonMember {
    public:

        StartingPrices(const Optional<double>& nearPrice = Optional<double>(),
            const Optional<double>& farPrice = Optional<double>(),
            const std::vector<PriceSize>& backStakeTaken = std::vector<PriceSize>(),
            const std::vector<PriceSize>& layLiabilityTaken = std::vector<PriceSize>(),
            const Optional<double>& actualSP = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getNearPrice() const;
        void setNearPrice(const Optional<double>& nearPrice);

        const Optional<double>& getFarPrice() const;
        void setFarPrice(const Optional<double>& farPrice);

        const std::vector<PriceSize>& getBackStakeTaken() const;
        void setBackStakeTaken(const std::vector<PriceSize>& backStakeTaken);

        const std::vector<PriceSize>& getLayLiabilityTaken() const;
        void setLayLiabilityTaken(const std::vector<PriceSize>& layLiabilityTaken);

        const Optional<double>& getActualSP() const;
        void setActualSP(const Optional<double>& actualSP);


    private:
        Optional<double> nearPrice;
        Optional<double> farPrice;
        std::vector<PriceSize> backStakeTaken;
        std::vector<PriceSize> layLiabilityTaken;
        Optional<double> actualSP;
};

}

#endif // STARTINGPRICES_H


