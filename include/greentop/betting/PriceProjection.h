/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PRICEPROJECTION_H
#define PRICEPROJECTION_H

#include <json/json.h>
#include <set>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/betting/ExBestOffersOverrides.h"
#include "greentop/enum/PriceData.h"

namespace greentop {

class PriceProjection : public JsonMember {
    public:

        PriceProjection(const std::set<PriceData>& priceData = std::set<PriceData>(),
            const ExBestOffersOverrides& exBestOffersOverrides = ExBestOffersOverrides(),
            const Optional<bool>& virtualise = Optional<bool>(),
            const Optional<bool>& rolloverStakes = Optional<bool>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::set<PriceData>& getPriceData() const;
        void setPriceData(const std::set<PriceData>& priceData);

        const ExBestOffersOverrides& getExBestOffersOverrides() const;
        void setExBestOffersOverrides(const ExBestOffersOverrides& exBestOffersOverrides);

        const Optional<bool>& getVirtualise() const;
        void setVirtualise(const Optional<bool>& virtualise);

        const Optional<bool>& getRolloverStakes() const;
        void setRolloverStakes(const Optional<bool>& rolloverStakes);


    private:
        std::set<PriceData> priceData;
        ExBestOffersOverrides exBestOffersOverrides;
        Optional<bool> virtualise;
        Optional<bool> rolloverStakes;
};

}

#endif // PRICEPROJECTION_H


