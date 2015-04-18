/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTMARKETCATALOGUERESPONSE_H
#define LISTMARKETCATALOGUERESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/MarketCatalogue.h"

namespace greentop {

class ListMarketCatalogueResponse : public JsonResponse {
    public:
        ListMarketCatalogueResponse();

        ListMarketCatalogueResponse(const std::vector<MarketCatalogue>& marketCatalogues);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<MarketCatalogue>& getMarketCatalogues() const;
        void setMarketCatalogues(const std::vector<MarketCatalogue>& marketCatalogues);


    private:
        std::vector<MarketCatalogue> marketCatalogues;
};

}

#endif // LISTMARKETCATALOGUERESPONSE_H


