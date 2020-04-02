/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_LISTAUTHORIZEDWEBAPPSRESPONSE_H
#define ACCOUNT_LISTAUTHORIZEDWEBAPPSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/account/VendorDetails.h"

namespace greentop {
namespace account {

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
}

#endif // ACCOUNT_LISTAUTHORIZEDWEBAPPSRESPONSE_H
