/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef WALLET_H
#define WALLET_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

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

#endif // WALLET_H
