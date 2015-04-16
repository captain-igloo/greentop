#ifndef LISTMARKETBOOKRESPONSE_H
#define LISTMARKETBOOKRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/MarketBook.h"

namespace greentop {

class ListMarketBookResponse : public JsonResponse {
    public:
        ListMarketBookResponse();

        ListMarketBookResponse(const std::vector<MarketBook>& marketBooks);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<MarketBook>& getMarketBooks() const;
        void setMarketBooks(const std::vector<MarketBook>& marketBooks);


    private:
        std::vector<MarketBook> marketBooks;
};

}

#endif // LISTMARKETBOOKRESPONSE_H


