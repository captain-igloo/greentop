/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_VENDORDETAILS_H
#define ACCOUNT_VENDORDETAILS_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"

namespace greentop {
namespace account {
/**
 * Wrapper object containing vendor name and redirect url
 */
class VendorDetails : public JsonResponse {
    public:
        VendorDetails();

        VendorDetails(const Optional<int64_t>& appVersionId,
            const std::string& vendorName,
            const std::string& redirectUrl = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getAppVersionId() const;
        void setAppVersionId(const Optional<int64_t>& appVersionId);

        const std::string& getVendorName() const;
        void setVendorName(const std::string& vendorName);

        const std::string& getRedirectUrl() const;
        void setRedirectUrl(const std::string& redirectUrl);


    private:
        /**
         * Internal id of the application
         */
        Optional<int64_t> appVersionId;
        /**
         * Vendor name
         */
        std::string vendorName;
        /**
         * URL to be redirected to
         */
        std::string redirectUrl;
};

}
}

#endif // ACCOUNT_VENDORDETAILS_H
