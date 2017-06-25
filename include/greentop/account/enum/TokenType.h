/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

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

#endif // TOKENTYPE_H
