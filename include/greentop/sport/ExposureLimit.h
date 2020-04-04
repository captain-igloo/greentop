/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_EXPOSURELIMIT_H
#define SPORT_EXPOSURELIMIT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/LimitBreachAction.h"

namespace greentop {
namespace sport {
/**
 * Exposure limit and limit breach action. Not populating one of total or matched parameters
 * indicates that no limit should be set for that exposure value. A special use of this type is
 * when none of its parameters are populated, this can be used to override default limit to "no
 * limit" for a specific instance of market group (see setExposureLimitForMarketGroup operation)
 */
class ExposureLimit : public JsonMember {
    public:

        ExposureLimit(const Optional<double>& matched = Optional<double>(),
            const Optional<double>& total = Optional<double>(),
            const LimitBreachAction& limitBreachAction = LimitBreachAction());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getMatched() const;
        void setMatched(const Optional<double>& matched);

        const Optional<double>& getTotal() const;
        void setTotal(const Optional<double>& total);

        const LimitBreachAction& getLimitBreachAction() const;
        void setLimitBreachAction(const LimitBreachAction& limitBreachAction);


    private:
        /**
         * Set a limit on matched bet exposure on market group
         */
        Optional<double> matched;
        /**
         * Set a limit on total (matched + unmatched) bet exposure on market group
         */
        Optional<double> total;

        LimitBreachAction limitBreachAction;
};

}
}

#endif // SPORT_EXPOSURELIMIT_H
