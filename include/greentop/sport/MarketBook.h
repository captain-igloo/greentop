/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETBOOK_H
#define MARKETBOOK_H

#include <ctime>
#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/Runner.h"

namespace greentop {

class MarketBook : public JsonMember {
    public:
        MarketBook();

        MarketBook(const std::string& marketId,
            const bool isMarketDataDelayed,
            const std::string& status = std::string(),
            const Optional<int32_t>& betDelay = Optional<int32_t>(),
            const Optional<bool>& bspReconciled = Optional<bool>(),
            const Optional<bool>& complete = Optional<bool>(),
            const Optional<bool>& inplay = Optional<bool>(),
            const Optional<int32_t>& numberOfWinners = Optional<int32_t>(),
            const Optional<int32_t>& numberOfRunners = Optional<int32_t>(),
            const Optional<int32_t>& numberOfActiveRunners = Optional<int32_t>(),
            const std::tm& lastMatchTime = std::tm(),
            const Optional<double>& totalMatched = Optional<double>(),
            const Optional<double>& totalAvailable = Optional<double>(),
            const Optional<bool>& crossMatching = Optional<bool>(),
            const Optional<bool>& runnersVoidable = Optional<bool>(),
            const Optional<int64_t>& version = Optional<int64_t>(),
            const std::vector<Runner>& runners = std::vector<Runner>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const bool getIsMarketDataDelayed() const;
        void setIsMarketDataDelayed(const bool isMarketDataDelayed);

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

        const Optional<int32_t>& getNumberOfWinners() const;
        void setNumberOfWinners(const Optional<int32_t>& numberOfWinners);

        const Optional<int32_t>& getNumberOfRunners() const;
        void setNumberOfRunners(const Optional<int32_t>& numberOfRunners);

        const Optional<int32_t>& getNumberOfActiveRunners() const;
        void setNumberOfActiveRunners(const Optional<int32_t>& numberOfActiveRunners);

        const std::tm& getLastMatchTime() const;
        void setLastMatchTime(const std::tm& lastMatchTime);

        const Optional<double>& getTotalMatched() const;
        void setTotalMatched(const Optional<double>& totalMatched);

        const Optional<double>& getTotalAvailable() const;
        void setTotalAvailable(const Optional<double>& totalAvailable);

        const Optional<bool>& getCrossMatching() const;
        void setCrossMatching(const Optional<bool>& crossMatching);

        const Optional<bool>& getRunnersVoidable() const;
        void setRunnersVoidable(const Optional<bool>& runnersVoidable);

        const Optional<int64_t>& getVersion() const;
        void setVersion(const Optional<int64_t>& version);

        const std::vector<Runner>& getRunners() const;
        void setRunners(const std::vector<Runner>& runners);


    private:
        std::string marketId;
        bool isMarketDataDelayed;
        std::string status;
        Optional<int32_t> betDelay;
        Optional<bool> bspReconciled;
        Optional<bool> complete;
        Optional<bool> inplay;
        Optional<int32_t> numberOfWinners;
        Optional<int32_t> numberOfRunners;
        Optional<int32_t> numberOfActiveRunners;
        std::tm lastMatchTime;
        Optional<double> totalMatched;
        Optional<double> totalAvailable;
        Optional<bool> crossMatching;
        Optional<bool> runnersVoidable;
        Optional<int64_t> version;
        std::vector<Runner> runners;
};

}

#endif // MARKETBOOK_H


