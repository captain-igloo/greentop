/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef VENDORACCESSTOKENINFO_H
#define VENDORACCESSTOKENINFO_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"
#include "greentop/account/ApplicationSubscription.h"
#include "greentop/account/enum/TokenType.h"

namespace greentop {

/**
 * Wrapper object containing UserVendorSessionToken, RefreshToken and optionally a Subscription Token
 * if one was created
 */
class VendorAccessTokenInfo : public JsonResponse {
    public:
        VendorAccessTokenInfo();

        VendorAccessTokenInfo(const std::string& access_token,
            const TokenType& token_type,
            const int64_t expires_in,
            const std::string& refresh_token,
            const ApplicationSubscription& application_subscription);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getAccess_token() const;
        void setAccess_token(const std::string& access_token);

        const TokenType& getToken_type() const;
        void setToken_type(const TokenType& token_type);

        const int64_t getExpires_in() const;
        void setExpires_in(const int64_t expires_in);

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
        int64_t expires_in;
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

#endif // VENDORACCESSTOKENINFO_H


