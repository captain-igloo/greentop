/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_WALLET_H
#define ACCOUNT_ENUM_WALLET_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class Wallet : public Enum<Wallet> {

    public:


        static const std::string UK;

        static const std::string AUSTRALIAN;

        Wallet();

        Wallet(const std::string& v);

        bool operator<(const Wallet& other) const;

        bool operator==(const Wallet& other) const;

        bool operator!=(const Wallet& other) const;
};

}
}

#endif // ACCOUNT_ENUM_WALLET_H
