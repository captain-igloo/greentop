/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/account/ListAuthorizedWebAppsResponse.h"

namespace greentop {
namespace account {

ListAuthorizedWebAppsResponse::ListAuthorizedWebAppsResponse() {
}

ListAuthorizedWebAppsResponse::ListAuthorizedWebAppsResponse(const std::vector<VendorDetails>& vendorDetailses) :
    vendorDetailses(vendorDetailses) {
}

void ListAuthorizedWebAppsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            VendorDetails vendorDetailse;
            vendorDetailse.fromJson(json[i]);
            vendorDetailses.push_back(vendorDetailse);
        }
    }
}

Json::Value ListAuthorizedWebAppsResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (vendorDetailses.size() > 0) {
        for (unsigned i = 0; i < vendorDetailses.size(); ++i) {
            json.append(vendorDetailses[i].toJson());
        }
    }
    return json;
}

bool ListAuthorizedWebAppsResponse::isValid() const {
    return vendorDetailses.size() > 0;
}

const std::vector<VendorDetails>& ListAuthorizedWebAppsResponse::getVendorDetailses() const {
    return vendorDetailses;
}
void ListAuthorizedWebAppsResponse::setVendorDetailses(const std::vector<VendorDetails>& vendorDetailses) {
    this->vendorDetailses = vendorDetailses;
}


}
}
