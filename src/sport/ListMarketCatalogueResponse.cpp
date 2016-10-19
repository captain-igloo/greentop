/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketCatalogueResponse.h"

namespace greentop {

ListMarketCatalogueResponse::ListMarketCatalogueResponse() {
}

ListMarketCatalogueResponse::ListMarketCatalogueResponse(const std::vector<MarketCatalogue>& marketCatalogues) :
    marketCatalogues(marketCatalogues) {
}

void ListMarketCatalogueResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            MarketCatalogue marketCatalogue;
            marketCatalogue.fromJson(json[i]);
            marketCatalogues.push_back(marketCatalogue);
        }
    }
}

Json::Value ListMarketCatalogueResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (marketCatalogues.size() > 0) {
        for (unsigned i = 0; i < marketCatalogues.size(); ++i) {
            json.append(marketCatalogues[i].toJson());
        }
    }
    return json;
}

bool ListMarketCatalogueResponse::isValid() const {
    return marketCatalogues.size() > 0;
}

const std::vector<MarketCatalogue>& ListMarketCatalogueResponse::getMarketCatalogues() const {
    return marketCatalogues;
}
void ListMarketCatalogueResponse::setMarketCatalogues(const std::vector<MarketCatalogue>& marketCatalogues) {
    this->marketCatalogues = marketCatalogues;
}


}



