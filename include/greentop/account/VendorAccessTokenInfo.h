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

        const std::string& getAccessToken() const;
        void setAccessToken(const std::string& accessToken);

        const TokenType& getTokenType() const;
        void setTokenType(const TokenType& tokenType);

        const Optional<int64_t>& getExpiresIn() const;
        void setExpiresIn(const Optional<int64_t>& expiresIn);

        const std::string& getRefreshToken() const;
        void setRefreshToken(const std::string& refreshToken);

        const ApplicationSubscription& getApplicationSubscription() const;
        void setApplicationSubscription(const ApplicationSubscription& applicationSubscription);


    private:
        /**
         * Session token used by web vendors
         */
        std::string accessToken;
        /**
         * Type of the token
         */
        TokenType tokenType;
        /**
         * How long until the token expires
         */
        Optional<int64_t> expiresIn;
        /**
         * Token used to refresh the session token in future
         */
        std::string refreshToken;
        /**
         * Object containing the vendor client id and optionally some subscription information
         */
        ApplicationSubscription applicationSubscription;
};

}
}

#endif // ACCOUNT_VENDORACCESSTOKENINFO_H
