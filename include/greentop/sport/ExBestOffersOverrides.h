/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EXBESTOFFERSOVERRIDES_H
#define EXBESTOFFERSOVERRIDES_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/enum/RollupModel.h"

namespace greentop {

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
        Optional<int32_t> bestPricesDepth;
        RollupModel rollupModel;
        Optional<int32_t> rollupLimit;
        Optional<double> rollupLiabilityThreshold;
        Optional<int32_t> rollupLiabilityFactor;
};

}

#endif // EXBESTOFFERSOVERRIDES_H


