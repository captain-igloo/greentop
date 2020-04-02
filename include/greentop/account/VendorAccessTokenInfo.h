/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_VENDORACCESSTOKENINFO_H
#define ACCOUNT_VENDORACCESSTOKENINFO_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"
#include "greentop/account/ApplicationSubscription.h"
#include "greentop/account/enum/TokenType.h"

namespace greentop {
namespace account {
/**
 * Wrapper object containing UserVendorSessionToken, RefreshToken and optionally a Subscription
 * Token if one was created
 */
class VendorAccessTokenInfo : public JsonResponse {
    public:
        VendorAccessTokenInfo();

        VendorAccessTokenInfo(const std::string& accessToken,
            const TokenType& tokenType,
            const Optional<int64_t>& expiresIn,
            const std::string& refreshToken,
            const ApplicationSubscription& applicationSubscription);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getAccess_token() const;
        void setAccess_token(const std::string& access_token);

        const TokenType& getToken_type() const;
        void setToken_type(const TokenType& token_type);

        const Optional<int64_t>& getExpires_in() const;
        void setExpires_in(const Optional<int64_t>& expires_in);

        const std::string& getRefresh_token() const;
        void setRefresh_token(const std::string& refresh_token);

        const ApplicationSubscription& getApplication_subscription() const;
        void setApplication_subscription(const ApplicationSubscription& application_subscription);


    private:
        /**
         * Session token used by web vendors
         */
        std::string access_token;
        /**
         * Type of the token
         */
        TokenType token_type;
        /**
         * How long until the token expires
         */
        Optional<int64_t> expires_in;
        /**
         * Token used to refresh the session token in future
         */
        std::string refresh_token;
        /**
         * Object containing the vendor client id and optionally some subscription information
         */
        ApplicationSubscription application_subscription;
};

}
}

#endif // ACCOUNT_VENDORACCESSTOKENINFO_H
