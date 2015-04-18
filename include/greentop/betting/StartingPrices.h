/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STARTINGPRICES_H
#define STARTINGPRICES_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/betting/PriceSize.h"

namespace greentop {

class StartingPrices : public JsonMember {
    public:

        StartingPrices(const double nearPrice = -1,
            const double farPrice = -1,
            const std::vector<PriceSize>& backStakeTaken = std::vector<PriceSize>(),
            const std::vector<PriceSize>& layLiabilityTaken = std::vector<PriceSize>(),
            const double actualSP = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getNearPrice() const;
        void setNearPrice(const double nearPrice);

        const double getFarPrice() const;
        void setFarPrice(const double farPrice);

        const std::vector<PriceSize>& getBackStakeTaken() const;
        void setBackStakeTaken(const std::vector<PriceSize>& backStakeTaken);

        const std::vector<PriceSize>& getLayLiabilityTaken() const;
        void setLayLiabilityTaken(const std::vector<PriceSize>& layLiabilityTaken);

        const double getActualSP() const;
        void setActualSP(const double actualSP);


    private:
        double nearPrice;
        double farPrice;
        std::vector<PriceSize> backStakeTaken;
        std::vector<PriceSize> layLiabilityTaken;
        double actualSP;
};

}

#endif // STARTINGPRICES_H


