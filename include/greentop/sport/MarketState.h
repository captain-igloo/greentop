/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETSTATE_H
#define MARKETSTATE_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Time.h"

namespace greentop {

class MarketState : public JsonMember {
    public:
        MarketState();

        MarketState(const std::string& status,
            const int32_t betDelay,
            const bool bspReconciled,
            const bool complete,
            const bool inplay,
            const int32_t numberOfActiveRunners,
            const std::tm& lastMatchTime,
            const double totalMatched,
            const double totalAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getStatus() const;
        void setStatus(const std::string& status);

        const int32_t getBetDelay() const;
        void setBetDelay(const int32_t betDelay);

        const bool getBspReconciled() const;
        void setBspReconciled(const bool bspReconciled);

        const bool getComplete() const;
        void setComplete(const bool complete);

        const bool getInplay() const;
        void setInplay(const bool inplay);

        const int32_t getNumberOfActiveRunners() const;
        void setNumberOfActiveRunners(const int32_t numberOfActiveRunners);

        const std::tm& getLastMatchTime() const;
        void setLastMatchTime(const std::tm& lastMatchTime);

        const double getTotalMatched() const;
        void setTotalMatched(const double totalMatched);

        const double getTotalAvailable() const;
        void setTotalAvailable(const double totalAvailable);


    private:
        std::string status;
        int32_t betDelay;
        bool bspReconciled;
        bool complete;
        bool inplay;
        int32_t numberOfActiveRunners;
        std::tm lastMatchTime;
        double totalMatched;
        double totalAvailable;
};

}

#endif // MARKETSTATE_H


