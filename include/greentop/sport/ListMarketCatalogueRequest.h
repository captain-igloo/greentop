/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTMARKETCATALOGUEREQUEST_H
#define LISTMARKETCATALOGUEREQUEST_H

#include <json/json.h>
#include <set>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/sport/MarketFilter.h"
#include "greentop/sport/enum/MarketProjection.h"
#include "greentop/sport/enum/MarketSort.h"

namespace greentop {

class ListMarketCatalogueRequest : public JsonRequest {
    public:
        ListMarketCatalogueRequest();

        ListMarketCatalogueRequest(const MarketFilter& filter,
            const std::set<MarketProjection>& marketProjection = std::set<MarketProjection>(),
            const MarketSort& sort = MarketSort(),
            const Optional<int32_t>& maxResults = Optional<int32_t>(),
            const std::string& locale = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketFilter& getFilter() const;
        void setFilter(const MarketFilter& filter);

        const std::set<MarketProjection>& getMarketProjection() const;
        void setMarketProjection(const std::set<MarketProjection>& marketProjection);

        const MarketSort& getSort() const;
        void setSort(const MarketSort& sort);

        const Optional<int32_t>& getMaxResults() const;
        void setMaxResults(const Optional<int32_t>& maxResults);

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);


    private:
        /**
         * The filter to select desired markets. All markets that match the criteria in the filter
         * are selected.
         */
        MarketFilter filter;
        /**
         * The type and amount of data returned about the market.
         */
        std::set<MarketProjection> marketProjection;
        /**
         * The order of the results. Will default to RANK if not passed
         */
        MarketSort sort;
        /**
         * limit on the total number of results returned, must be greater than 0 and less than or
         * equal to 1000
         */
        Optional<int32_t> maxResults;
        /**
         * The language used for the response. If not specified, the default is returned.
         */
        std::string locale;
};

}

#endif // LISTMARKETCATALOGUEREQUEST_H
