/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_EXBESTOFFERSOVERRIDES_H
#define SPORT_EXBESTOFFERSOVERRIDES_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/enum/RollupModel.h"

namespace greentop {
namespace sport {
/**
 * Options to alter the default representation of best offer prices
 */
class ExBestOffersOverrides : public JsonMember {
    public:

        ExBestOffersOverrides(const Optional<int32_t>& bestPricesDepth = Optional<int32_t>(),
            const RollupModel& rollupModel = RollupModel(),
            const Optional<int32_t>& rollupLimit = Optional<int32_t>(),
            const Optional<double>& rollupLiabilityThreshold = Optional<double>(),
            const Optional<int32_t>& rollupLiabilityFactor = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int32_t>& getBestPricesDepth() const;
        void setBestPricesDepth(const Optional<int32_t>& bestPricesDepth);

        const RollupModel& getRollupModel() const;
        void setRollupModel(const RollupModel& rollupModel);

        const Optional<int32_t>& getRollupLimit() const;
        void setRollupLimit(const Optional<int32_t>& rollupLimit);

        const Optional<double>& getRollupLiabilityThreshold() const;
        void setRollupLiabilityThreshold(const Optional<double>& rollupLiabilityThreshold);

        const Optional<int32_t>& getRollupLiabilityFactor() const;
        void setRollupLiabilityFactor(const Optional<int32_t>& rollupLiabilityFactor);


    private:
        /**
         * The maximum number of prices to return on each side for each runner. If unspecified
         * defaults to 3.
         */
        Optional<int32_t> bestPricesDepth;
        /**
         * The model to use when rolling up available sizes. If unspecified defaults to STAKE
         * rollup model with rollupLimit of minimum stake in the specified currency.
         */
        RollupModel rollupModel;
        /**
         * The volume limit to use when rolling up returned sizes. The exact definition of the
         * limit depends on the rollupModel. If no limit is provided it will use minimum stake as
         * default the value. Ignored if no rollup model is specified.
         */
        Optional<int32_t> rollupLimit;
        /**
         * Only applicable when rollupModel is MANAGED_LIABILITY. The rollup model switches from
         * being stake based to liability based at the smallest lay price which is >=
         * rollupLiabilityThreshold.service level default (TBD). Not supported as yet.
         */
        Optional<double> rollupLiabilityThreshold;
        /**
         * Only applicable when rollupModel is MANAGED_LIABILITY. (rollupLiabilityFactor *
         * rollupLimit) is the minimum liabilty the user is deemed to be comfortable with. After
         * the rollupLiabilityThreshold price subsequent volumes will be rolled up to minimum value
         * such that the liability >= the minimum liability.service level default (5). Not
         * supported as yet.
         */
        Optional<int32_t> rollupLiabilityFactor;
};

}
}

#endif // SPORT_EXBESTOFFERSOVERRIDES_H
