/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_TOKENREQUEST_H
#define ACCOUNT_TOKENREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"
#include "greentop/account/enum/GrantType.h"

namespace greentop {
namespace account {

class TokenRequest : public JsonRequest {
    public:
        TokenRequest();

        TokenRequest(const std::string& clientId,
            const GrantType& grantType,
            const std::string& code = std::string(),
            const std::string& clientSecret = std::string(),
            const std::string& refreshToken = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getClientId() const;
        void setClientId(const std::string& clientId);

        const GrantType& getGrantType() const;
        void setGrantType(const GrantType& grantType);

        const std::string& getCode() const;
        void setCode(const std::string& code);

        const std::string& getClientSecret() const;
        void setClientSecret(const std::string& clientSecret);

        const std::string& getRefreshToken() const;
        void setRefreshToken(const std::string& refreshToken);


    private:
        /**
         * The vendor's vendorId
         */
        std::string clientId;
        /**
         * Whether the vendor is using an authorisation code or a refresh token to get a session
         */
        GrantType grantType;
        /**
         * The authorisation code used to lookup the session to be returned
         */
        std::string code;
        /**
         * The vendor's private key used to verify their identity
         */
        std::string clientSecret;
        /**
         * The vendor's refresh token if the grant_type is refresh_token
         */
        std::string refreshToken;
};

}
}

#endif // ACCOUNT_TOKENREQUEST_H
