/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXCHANGEPRICES_H
#define EXCHANGEPRICES_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/sport/PriceSize.h"

namespace greentop {

class ExchangePrices : public JsonMember {
    public:

        ExchangePrices(const std::vector<PriceSize>& availableToBack = std::vector<PriceSize>(),
            const std::vector<PriceSize>& availableToLay = std::vector<PriceSize>(),
            const std::vector<PriceSize>& tradedVolume = std::vector<PriceSize>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<PriceSize>& getAvailableToBack() const;
        void setAvailableToBack(const std::vector<PriceSize>& availableToBack);

        const std::vector<PriceSize>& getAvailableToLay() const;
        void setAvailableToLay(const std::vector<PriceSize>& availableToLay);

        const std::vector<PriceSize>& getTradedVolume() const;
        void setTradedVolume(const std::vector<PriceSize>& tradedVolume);


    private:

        std::vector<PriceSize> availableToBack;

        std::vector<PriceSize> availableToLay;

        std::vector<PriceSize> tradedVolume;
};

}

#endif // EXCHANGEPRICES_H
