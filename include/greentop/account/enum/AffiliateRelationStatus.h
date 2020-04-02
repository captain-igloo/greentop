/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_ENUM_AFFILIATERELATIONSTATUS_H
#define ACCOUNT_ENUM_AFFILIATERELATIONSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace account {

class AffiliateRelationStatus : public Enum<AffiliateRelationStatus> {

    public:

        /**
         * Provided vendor client ID is not valid
         */
        static const std::string INVALID_USER;
        /**
         * Vendor client ID valid and affiliated
         */
        static const std::string AFFILIATED;
        /**
         * Vendor client ID valid but not affiliated
         */
        static const std::string NOT_AFFILIATED;

        AffiliateRelationStatus();

        AffiliateRelationStatus(const std::string& v);

        bool operator<(const AffiliateRelationStatus& other) const;

        bool operator==(const AffiliateRelationStatus& other) const;

        bool operator!=(const AffiliateRelationStatus& other) const;
};

}
}

#endif // ACCOUNT_ENUM_AFFILIATERELATIONSTATUS_H
