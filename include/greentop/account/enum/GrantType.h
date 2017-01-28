/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GRANTTYPE_H
#define GRANTTYPE_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class GrantType : public Enum<GrantType> {

    public:

        /**  */
        static const std::string AUTHORIZATION_CODE;
        /**  */
        static const std::string REFRESH_TOKEN;

        GrantType();

        GrantType(const std::string& v);

        bool operator<(const GrantType& other) const;

        bool operator==(const GrantType& other) const;

        bool operator!=(const GrantType& other) const;
};

}

#endif // GRANTTYPE_H
