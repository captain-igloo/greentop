/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTRUNNERBOOKRESPONSE_H
#define SPORT_LISTRUNNERBOOKRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/MarketBook.h"

namespace greentop {
namespace sport {

class ListRunnerBookResponse : public JsonResponse {
    public:
        ListRunnerBookResponse();

        ListRunnerBookResponse(const std::vector<MarketBook>& marketBooks);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<MarketBook>& getMarketBooks() const;
        void setMarketBooks(const std::vector<MarketBook>& marketBooks);


    private:

        std::vector<MarketBook> marketBooks;
};

}
}

#endif // SPORT_LISTRUNNERBOOKRESPONSE_H
