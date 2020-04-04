/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListRunnerBookResponse.h"

namespace greentop {
namespace sport {

ListRunnerBookResponse::ListRunnerBookResponse() {
}

ListRunnerBookResponse::ListRunnerBookResponse(const std::vector<MarketBook>& marketBooks) :
    marketBooks(marketBooks) {
}

void ListRunnerBookResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            MarketBook marketBook;
            marketBook.fromJson(json[i]);
            marketBooks.push_back(marketBook);
        }
    }
}

Json::Value ListRunnerBookResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (marketBooks.size() > 0) {
        for (unsigned i = 0; i < marketBooks.size(); ++i) {
            json.append(marketBooks[i].toJson());
        }
    }
    return json;
}

bool ListRunnerBookResponse::isValid() const {
    return marketBooks.size() > 0;
}

const std::vector<MarketBook>& ListRunnerBookResponse::getMarketBooks() const {
    return marketBooks;
}
void ListRunnerBookResponse::setMarketBooks(const std::vector<MarketBook>& marketBooks) {
    this->marketBooks = marketBooks;
}


}
}
