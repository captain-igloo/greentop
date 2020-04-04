/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_TOKENTYPE_H
#define ACCOUNT_ENUM_TOKENTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class TokenType : public Enum<TokenType> {

    public:


        static const std::string BEARER;

        TokenType();

        TokenType(const std::string& v);

        bool operator<(const TokenType& other) const;

        bool operator==(const TokenType& other) const;

        bool operator!=(const TokenType& other) const;
};

}
}

#endif // ACCOUNT_ENUM_TOKENTYPE_H
