#include "greentop/betting/ListCountriesResponse.h"

namespace greentop {
ListCountriesResponse::ListCountriesResponse() {
}

ListCountriesResponse::ListCountriesResponse(const std::vector<CountryCodeResult>& countryCodeResults) :
    countryCodeResults(countryCodeResults) {
}

void ListCountriesResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("countryCodeResults")) {
            for (unsigned i = 0; i < json["countryCodeResults"].size(); ++i) {
                CountryCodeResult countryCodeResult;
                countryCodeResult.fromJson(json["countryCodeResults"][i]);
                countryCodeResults.push_back(countryCodeResult);
            };
        }
    }
}

Json::Value ListCountriesResponse::toJson() const {
    Json::Value json;
    if (countryCodeResults.size() > 0) {
        for (unsigned i = 0; i < countryCodeResults.size(); ++i) {
            json["countryCodeResults"].append(countryCodeResults[i].toJson());
        };
    }
    return json;
}

bool ListCountriesResponse::isValid() const {
    return countryCodeResults.size() > 0;
}

const std::vector<CountryCodeResult>& ListCountriesResponse::getCountryCodeResults() const {
    return countryCodeResults;
}
void ListCountriesResponse::setCountryCodeResults(const std::vector<CountryCodeResult>& countryCodeResults) {
    this->countryCodeResults = countryCodeResults;
}


}



