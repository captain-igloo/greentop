/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_PRICEPROJECTION_H
#define SPORT_PRICEPROJECTION_H

#include <json/json.h>
#include <set>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/ExBestOffersOverrides.h"
#include "greentop/sport/enum/PriceData.h"

namespace greentop {
namespace sport {
/**
 * Selection criteria of the returning price data
 */
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
        /**
         * The basic price data you want to receive in the response.
         */
        std::set<PriceData> priceData;
        /**
         * Options to alter the default representation of best offer prices Applicable to
         * EX_BEST_OFFERS priceData selection
         */
        ExBestOffersOverrides exBestOffersOverrides;
        /**
         * Indicates if the returned prices should include virtual prices. Applicable to
         * EX_BEST_OFFERS and EX_ALL_OFFERS priceData selections, default value is false.
         */
        Optional<bool> virtualise;
        /**
         * Indicates if the volume returned at each price point should be the absolute value or a
         * cumulative sum of volumes available at the price and all better prices. If unspecified
         * defaults to false. Applicable to EX_BEST_OFFERS and EX_ALL_OFFERS price projections. Not
         * supported as yet.
         */
        Optional<bool> rolloverStakes;
};

}
}

#endif // SPORT_PRICEPROJECTION_H
