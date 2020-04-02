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

        const std::string& getClient_id() const;
        void setClient_id(const std::string& client_id);

        const GrantType& getGrant_type() const;
        void setGrant_type(const GrantType& grant_type);

        const std::string& getCode() const;
        void setCode(const std::string& code);

        const std::string& getClient_secret() const;
        void setClient_secret(const std::string& client_secret);

        const std::string& getRefresh_token() const;
        void setRefresh_token(const std::string& refresh_token);


    private:
        /**
         * The vendor's vendorId
         */
        std::string client_id;
        /**
         * Whether the vendor is using an authorisation code or a refresh token to get a session
         */
        GrantType grant_type;
        /**
         * The authorisation code used to lookup the session to be returned
         */
        std::string code;
        /**
         * The vendor's private key used to verify their identity
         */
        std::string client_secret;
        /**
         * The vendor's refresh token if the grant_type is refresh_token
         */
        std::string refresh_token;
};

}
}

#endif // ACCOUNT_TOKENREQUEST_H
