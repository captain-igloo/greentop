/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
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
        MarketFilter filter;
        std::set<MarketProjection> marketProjection;
        MarketSort sort;
        Optional<int32_t> maxResults;
        std::string locale;
};

}

#endif // LISTMARKETCATALOGUEREQUEST_H


