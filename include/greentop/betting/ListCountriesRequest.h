/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCOUNTRIESREQUEST_H
#define LISTCOUNTRIESREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/betting/MarketFilter.h"

namespace greentop {

class ListCountriesRequest : public JsonRequest {
    public:
        ListCountriesRequest();

        ListCountriesRequest(const MarketFilter& filter,
            const std::string& locale = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketFilter& getFilter() const;
        void setFilter(const MarketFilter& filter);

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);


    private:
        MarketFilter filter;
        std::string locale;
};

}

#endif // LISTCOUNTRIESREQUEST_H


