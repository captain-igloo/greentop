/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
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
#include "greentop/betting/Runner.h"
#include "greentop/enum/MarketStatus.h"

namespace greentop {

class MarketBook : public JsonMember {
    public:
        MarketBook();

        MarketBook(const std::string& marketId,
            const bool isMarketDataDelayed,
            const MarketStatus& status = MarketStatus(),
            const int betDelay = -1,
            const Optional<bool>& bspReconciled = Optional<bool>(),
            const Optional<bool>& complete = Optional<bool>(),
            const Optional<bool>& inplay = Optional<bool>(),
            const int numberOfWinners = -1,
            const int numberOfRunners = -1,
            const int numberOfActiveRunners = -1,
            const std::tm& lastMatchTime = std::tm(),
            const Optional<double>& totalMatched = Optional<double>(),
            const Optional<double>& totalAvailable = Optional<double>(),
            const Optional<bool>& crossMatching = Optional<bool>(),
            const Optional<bool>& runnersVoidable = Optional<bool>(),
            const uint64_t version = 0,
            const std::vector<Runner>& runners = std::vector<Runner>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const bool getIsMarketDataDelayed() const;
        void setIsMarketDataDelayed(const bool isMarketDataDelayed);

        const MarketStatus& getStatus() const;
        void setStatus(const MarketStatus& status);

        const int getBetDelay() const;
        void setBetDelay(const int betDelay);

        const Optional<bool>& getBspReconciled() const;
        void setBspReconciled(const Optional<bool>& bspReconciled);

        const Optional<bool>& getComplete() const;
        void setComplete(const Optional<bool>& complete);

        const Optional<bool>& getInplay() const;
        void setInplay(const Optional<bool>& inplay);

        const int getNumberOfWinners() const;
        void setNumberOfWinners(const int numberOfWinners);

        const int getNumberOfRunners() const;
        void setNumberOfRunners(const int numberOfRunners);

        const int getNumberOfActiveRunners() const;
        void setNumberOfActiveRunners(const int numberOfActiveRunners);

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

        const uint64_t getVersion() const;
        void setVersion(const uint64_t version);

        const std::vector<Runner>& getRunners() const;
        void setRunners(const std::vector<Runner>& runners);


    private:
        std::string marketId;
        bool isMarketDataDelayed;
        MarketStatus status;
        int betDelay;
        Optional<bool> bspReconciled;
        Optional<bool> complete;
        Optional<bool> inplay;
        int numberOfWinners;
        int numberOfRunners;
        int numberOfActiveRunners;
        std::tm lastMatchTime;
        Optional<double> totalMatched;
        Optional<double> totalAvailable;
        Optional<bool> crossMatching;
        Optional<bool> runnersVoidable;
        uint64_t version;
        std::vector<Runner> runners;
};

}

#endif // MARKETBOOK_H


