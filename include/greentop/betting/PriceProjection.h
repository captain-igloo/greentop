/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PRICEPROJECTION_H
#define PRICEPROJECTION_H

#include <json/json.h>
#include <set>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonMember.h"
#include "greentop/betting/ExBestOffersOverrides.h"
#include "greentop/enum/PriceData.h"

namespace greentop {

class PriceProjection : public JsonMember {
    public:

        PriceProjection(const std::set<PriceData>& priceData = std::set<PriceData>(),
            const ExBestOffersOverrides& exBestOffersOverrides = ExBestOffersOverrides(),
            const BoolJsonMember& virtualise = BoolJsonMember(),
            const BoolJsonMember& rolloverStakes = BoolJsonMember());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::set<PriceData>& getPriceData() const;
        void setPriceData(const std::set<PriceData>& priceData);

        const ExBestOffersOverrides& getExBestOffersOverrides() const;
        void setExBestOffersOverrides(const ExBestOffersOverrides& exBestOffersOverrides);

        const BoolJsonMember& getVirtualise() const;
        void setVirtualise(const BoolJsonMember& virtualise);

        const BoolJsonMember& getRolloverStakes() const;
        void setRolloverStakes(const BoolJsonMember& rolloverStakes);


    private:
        std::set<PriceData> priceData;
        ExBestOffersOverrides exBestOffersOverrides;
        BoolJsonMember virtualise;
        BoolJsonMember rolloverStakes;
};

}

#endif // PRICEPROJECTION_H


