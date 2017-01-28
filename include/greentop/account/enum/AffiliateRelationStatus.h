/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef AFFILIATERELATIONSTATUS_H
#define AFFILIATERELATIONSTATUS_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class AffiliateRelationStatus : public Enum<AffiliateRelationStatus> {

    public:

        /** Provided vendor client ID is not valid */
        static const std::string INVALID_USER;
        /** Vendor client ID valid and affiliated */
        static const std::string AFFILIATED;
        /** Vendor client ID valid but not affiliated */
        static const std::string NOT_AFFILIATED;

        AffiliateRelationStatus();

        AffiliateRelationStatus(const std::string& v);

        bool operator<(const AffiliateRelationStatus& other) const;

        bool operator==(const AffiliateRelationStatus& other) const;

        bool operator!=(const AffiliateRelationStatus& other) const;
};

}

#endif // AFFILIATERELATIONSTATUS_H
