/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_AUTHORISATIONRESPONSE_H
#define ACCOUNT_AUTHORISATIONRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {
namespace account {
/**
 * Wrapper object containing authorisation code and redirect URL for web vendors
 */
class AuthorisationResponse : public JsonResponse {
    public:
        AuthorisationResponse();

        AuthorisationResponse(const std::string& authorisationCode,
            const std::string& redirectUrl);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getAuthorisationCode() const;
        void setAuthorisationCode(const std::string& authorisationCode);

        const std::string& getRedirectUrl() const;
        void setRedirectUrl(const std::string& redirectUrl);


    private:
        /**
         * The authorisation code
         */
        std::string authorisationCode;
        /**
         * URL to redirect the user to the vendor page
         */
        std::string redirectUrl;
};

}
}

#endif // ACCOUNT_AUTHORISATIONRESPONSE_H
