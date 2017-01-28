/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef AUTHORISATIONRESPONSE_H
#define AUTHORISATIONRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {

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

#endif // AUTHORISATIONRESPONSE_H


