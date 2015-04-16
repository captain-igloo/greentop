#ifndef MARKETBOOK_H
#define MARKETBOOK_H

#include <ctime>
#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonMember.h"
#include "greentop/betting/Runner.h"
#include "greentop/enum/MarketStatus.h"

namespace greentop {

class MarketBook : public JsonMember {
    public:
        MarketBook();

        MarketBook(const std::string& marketId,
            const BoolJsonMember& isMarketDataDelayed,
            const MarketStatus& status = MarketStatus(),
            const int betDelay = -1,
            const BoolJsonMember& bspReconciled = BoolJsonMember(),
            const BoolJsonMember& complete = BoolJsonMember(),
            const BoolJsonMember& inplay = BoolJsonMember(),
            const int numberOfWinners = -1,
            const int numberOfRunners = -1,
            const int numberOfActiveRunners = -1,
            const std::tm& lastMatchTime = std::tm(),
            const double totalMatched = -1,
            const double totalAvailable = -1,
            const BoolJsonMember& crossMatching = BoolJsonMember(),
            const BoolJsonMember& runnersVoidable = BoolJsonMember(),
            const uint64_t version = 0,
            const std::vector<Runner>& runners = std::vector<Runner>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const BoolJsonMember& getIsMarketDataDelayed() const;
        void setIsMarketDataDelayed(const BoolJsonMember& isMarketDataDelayed);

        const MarketStatus& getStatus() const;
        void setStatus(const MarketStatus& status);

        const int getBetDelay() const;
        void setBetDelay(const int betDelay);

        const BoolJsonMember& getBspReconciled() const;
        void setBspReconciled(const BoolJsonMember& bspReconciled);

        const BoolJsonMember& getComplete() const;
        void setComplete(const BoolJsonMember& complete);

        const BoolJsonMember& getInplay() const;
        void setInplay(const BoolJsonMember& inplay);

        const int getNumberOfWinners() const;
        void setNumberOfWinners(const int numberOfWinners);

        const int getNumberOfRunners() const;
        void setNumberOfRunners(const int numberOfRunners);

        const int getNumberOfActiveRunners() const;
        void setNumberOfActiveRunners(const int numberOfActiveRunners);

        const std::tm& getLastMatchTime() const;
        void setLastMatchTime(const std::tm& lastMatchTime);

        const double getTotalMatched() const;
        void setTotalMatched(const double totalMatched);

        const double getTotalAvailable() const;
        void setTotalAvailable(const double totalAvailable);

        const BoolJsonMember& getCrossMatching() const;
        void setCrossMatching(const BoolJsonMember& crossMatching);

        const BoolJsonMember& getRunnersVoidable() const;
        void setRunnersVoidable(const BoolJsonMember& runnersVoidable);

        const uint64_t getVersion() const;
        void setVersion(const uint64_t version);

        const std::vector<Runner>& getRunners() const;
        void setRunners(const std::vector<Runner>& runners);


    private:
        std::string marketId;
        BoolJsonMember isMarketDataDelayed;
        MarketStatus status;
        int betDelay;
        BoolJsonMember bspReconciled;
        BoolJsonMember complete;
        BoolJsonMember inplay;
        int numberOfWinners;
        int numberOfRunners;
        int numberOfActiveRunners;
        std::tm lastMatchTime;
        double totalMatched;
        double totalAvailable;
        BoolJsonMember crossMatching;
        BoolJsonMember runnersVoidable;
        uint64_t version;
        std::vector<Runner> runners;
};

}

#endif // MARKETBOOK_H


