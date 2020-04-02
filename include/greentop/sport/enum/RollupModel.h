/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_ENUM_ROLLUPMODEL_H
#define SPORT_ENUM_ROLLUPMODEL_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {
namespace sport {

class RollupModel : public Enum<RollupModel> {

    public:

        /**
         * The volumes will be rolled up to the minimum value which is >= rollupLimit.
         */
        static const std::string STAKE;
        /**
         * The volumes will be rolled up to the minimum value where the payout( price * volume ) is
         * >= rollupLimit. On a LINE market, volumes will be rolled up where payout( 2.0 * volume )
         * is >= rollupLimit.
         */
        static const std::string PAYOUT;
        /**
         * The volumes will be rolled up to the minimum value which is >= rollupLimit, until a lay
         * price threshold. There after, the volumes will be rolled up to the minimum value such
         * that the liability >= a minimum liability. Not supported as yet.
         */
        static const std::string MANAGED_LIABILITY;
        /**
         * No rollup will be applied. However the volumes will be filtered by currency specific
         * minimum stake unless overridden specifically for the channel.
         */
        static const std::string NONE;

        RollupModel();

        RollupModel(const std::string& v);

        bool operator<(const RollupModel& other) const;

        bool operator==(const RollupModel& other) const;

        bool operator!=(const RollupModel& other) const;
};

}
}

#endif // SPORT_ENUM_ROLLUPMODEL_H
