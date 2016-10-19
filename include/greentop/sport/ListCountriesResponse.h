/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTCOUNTRIESRESPONSE_H
#define LISTCOUNTRIESRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/CountryCodeResult.h"

namespace greentop {

class ListCountriesResponse : public JsonResponse {
    public:
        ListCountriesResponse();

        ListCountriesResponse(const std::vector<CountryCodeResult>& countryCodeResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<CountryCodeResult>& getCountryCodeResults() const;
        void setCountryCodeResults(const std::vector<CountryCodeResult>& countryCodeResults);


    private:
        std::vector<CountryCodeResult> countryCodeResults;
};

}

#endif // LISTCOUNTRIESRESPONSE_H


