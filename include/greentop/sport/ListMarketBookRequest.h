/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTMARKETBOOKREQUEST_H
#define LISTMARKETBOOKREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/sport/PriceProjection.h"
#include "greentop/sport/enum/MatchProjection.h"
#include "greentop/sport/enum/OrderProjection.h"

namespace greentop {

class ListMarketBookRequest : public JsonRequest {
    public:
        ListMarketBookRequest();

        ListMarketBookRequest(const std::vector<std::string>& marketIds,
            const PriceProjection& priceProjection = PriceProjection(),
            const OrderProjection& orderProjection = OrderProjection(),
            const MatchProjection& matchProjection = MatchProjection(),
            const std::string& currencyCode = std::string(),
            const std::string& locale = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<std::string>& getMarketIds() const;
        void setMarketIds(const std::vector<std::string>& marketIds);

        const PriceProjection& getPriceProjection() const;
        void setPriceProjection(const PriceProjection& priceProjection);

        const OrderProjection& getOrderProjection() const;
        void setOrderProjection(const OrderProjection& orderProjection);

        const MatchProjection& getMatchProjection() const;
        void setMatchProjection(const MatchProjection& matchProjection);

        const std::string& getCurrencyCode() const;
        void setCurrencyCode(const std::string& currencyCode);

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);


    private:
        /**
         * One or more market ids. The number of markets returned depends on the amount of data you
         * request via the price projection.
         */
        std::vector<std::string> marketIds;
        /**
         * The projection of price data you want to receive in the response.
         */
        PriceProjection priceProjection;
        /**
         * The orders you want to receive in the response.
         */
        OrderProjection orderProjection;
        /**
         * If you ask for orders, specifies the representation of matches.
         */
        MatchProjection matchProjection;
        /**
         * A Betfair standard currency code. If not specified, the default currency code is used.
         */
        std::string currencyCode;
        /**
         * The language used for the response. If not specified, the default is returned.
         */
        std::string locale;
};

}

#endif // LISTMARKETBOOKREQUEST_H


