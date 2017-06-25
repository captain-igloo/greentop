/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListVenuesResponse.h"

namespace greentop {

ListVenuesResponse::ListVenuesResponse() {
}

ListVenuesResponse::ListVenuesResponse(const std::vector<VenueResult>& venueResults) :
    venueResults(venueResults) {
}

void ListVenuesResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            VenueResult venueResult;
            venueResult.fromJson(json[i]);
            venueResults.push_back(venueResult);
        }
    }
}

Json::Value ListVenuesResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (venueResults.size() > 0) {
        for (unsigned i = 0; i < venueResults.size(); ++i) {
            json.append(venueResults[i].toJson());
        }
    }
    return json;
}

bool ListVenuesResponse::isValid() const {
    return venueResults.size() > 0;
}

const std::vector<VenueResult>& ListVenuesResponse::getVenueResults() const {
    return venueResults;
}
void ListVenuesResponse::setVenueResults(const std::vector<VenueResult>& venueResults) {
    this->venueResults = venueResults;
}


}



