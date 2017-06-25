/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTEVENTTYPESREQUEST_H
#define LISTEVENTTYPESREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/sport/MarketFilter.h"

namespace greentop {

class ListEventTypesRequest : public JsonRequest {
    public:
        ListEventTypesRequest();

        ListEventTypesRequest(const MarketFilter& filter,
            const std::string& locale = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketFilter& getFilter() const;
        void setFilter(const MarketFilter& filter);

        const std::string& getLocale() const;
        void setLocale(const std::string& locale);


    private:
        /**
         * The filter to select desired markets. All markets that match the criteria in the filter
         * are selected.
         */
        MarketFilter filter;
        /**
         * The language used for the response. If not specified, the default is returned.
         */
        std::string locale;
};

}

#endif // LISTEVENTTYPESREQUEST_H
