/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListMarketBookResponse.h"

namespace greentop {

ListMarketBookResponse::ListMarketBookResponse() {
}

ListMarketBookResponse::ListMarketBookResponse(const std::vector<MarketBook>& marketBooks) :
    marketBooks(marketBooks) {
}

void ListMarketBookResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            MarketBook marketBook;
            marketBook.fromJson(json[i]);
            marketBooks.push_back(marketBook);
        }
    }
}

Json::Value ListMarketBookResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (marketBooks.size() > 0) {
        for (unsigned i = 0; i < marketBooks.size(); ++i) {
            json.append(marketBooks[i].toJson());
        }
    }
    return json;
}

bool ListMarketBookResponse::isValid() const {
    return marketBooks.size() > 0;
}

const std::vector<MarketBook>& ListMarketBookResponse::getMarketBooks() const {
    return marketBooks;
}
void ListMarketBookResponse::setMarketBooks(const std::vector<MarketBook>& marketBooks) {
    this->marketBooks = marketBooks;
}


}



