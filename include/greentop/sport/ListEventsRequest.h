/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTEVENTSREQUEST_H
#define LISTEVENTSREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/sport/MarketFilter.h"

namespace greentop {

class ListEventsRequest : public JsonRequest {
    public:
        ListEventsRequest();

        ListEventsRequest(const MarketFilter& filter,
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

#endif // LISTEVENTSREQUEST_H


