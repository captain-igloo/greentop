/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETSTATE_H
#define MARKETSTATE_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"

namespace greentop {
/**
 * Market definition
 */
class MarketState : public JsonMember {
    public:
        MarketState();

        MarketState(const std::string& status,
            const Optional<int32_t>& betDelay,
            const Optional<bool>& bspReconciled,
            const Optional<bool>& complete,
            const Optional<bool>& inplay,
            const Optional<int32_t>& numberOfActiveRunners,
            const std::tm& lastMatchTime,
            const Optional<double>& totalMatched,
            const Optional<double>& totalAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const Optional<int32_t>& getBetDelay() const;
        void setBetDelay(const Optional<int32_t>& betDelay);

        const Optional<bool>& getBspReconciled() const;
        void setBspReconciled(const Optional<bool>& bspReconciled);

        const Optional<bool>& getComplete() const;
        void setComplete(const Optional<bool>& complete);

        const Optional<bool>& getInplay() const;
        void setInplay(const Optional<bool>& inplay);

        const Optional<int32_t>& getNumberOfActiveRunners() const;
        void setNumberOfActiveRunners(const Optional<int32_t>& numberOfActiveRunners);

        const std::tm& getLastMatchTime() const;
        void setLastMatchTime(const std::tm& lastMatchTime);

        const Optional<double>& getTotalMatched() const;
        void setTotalMatched(const Optional<double>& totalMatched);

        const Optional<double>& getTotalAvailable() const;
        void setTotalAvailable(const Optional<double>& totalAvailable);


    private:
        /**
         * marketStatus
         */
        std::string status;
        /**
         * betDelay
         */
        Optional<int32_t> betDelay;
        /**
         * bspReconciled
         */
        Optional<bool> bspReconciled;
        /**
         * complete
         */
        Optional<bool> complete;
        /**
         * inplay
         */
        Optional<bool> inplay;
        /**
         * numberActiveOfRunners
         */
        Optional<int32_t> numberOfActiveRunners;
        /**
         * lastMatchTime
         */
        std::tm lastMatchTime;

        Optional<double> totalMatched;
        /**
         * Zero for closed markets
         */
        Optional<double> totalAvailable;
};

}

#endif // MARKETSTATE_H
