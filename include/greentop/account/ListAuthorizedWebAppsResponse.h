/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTAUTHORIZEDWEBAPPSRESPONSE_H
#define LISTAUTHORIZEDWEBAPPSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/VendorDetails.h"

namespace greentop {

class ListAuthorizedWebAppsResponse : public JsonResponse {
    public:
        ListAuthorizedWebAppsResponse();

        ListAuthorizedWebAppsResponse(const std::vector<VendorDetails>& vendorDetailses);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<VendorDetails>& getVendorDetailses() const;
        void setVendorDetailses(const std::vector<VendorDetails>& vendorDetailses);


    private:

        std::vector<VendorDetails> vendorDetailses;
};

}

#endif // LISTAUTHORIZEDWEBAPPSRESPONSE_H
