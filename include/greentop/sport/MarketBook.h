/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
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
#include "greentop/sport/KeyLineDescription.h"
#include "greentop/sport/Runner.h"
#include "greentop/sport/enum/MarketStatus.h"

namespace greentop {
/**
 * The dynamic data in a market
 */
class MarketBook : public JsonMember {
    public:
        MarketBook();

        MarketBook(const std::string& marketId,
            const Optional<bool>& isMarketDataDelayed,
            const MarketStatus& status = MarketStatus(),
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
            const std::vector<Runner>& runners = std::vector<Runner>(),
            const KeyLineDescription& keyLineDescription = KeyLineDescription());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const Optional<bool>& getIsMarketDataDelayed() const;
        void setIsMarketDataDelayed(const Optional<bool>& isMarketDataDelayed);

        const MarketStatus& getStatus() const;
        void setStatus(const MarketStatus& status);

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

        const KeyLineDescription& getKeyLineDescription() const;
        void setKeyLineDescription(const KeyLineDescription& keyLineDescription);


    private:
        /**
         * The unique identifier for the market
         */
        std::string marketId;
        /**
         * True if the data returned by listMarketBook will be delayed. The data may be delayed
         * because you are not logged in with a funded account or you are using an Application Key
         * that does not allow up to date data.
         */
        Optional<bool> isMarketDataDelayed;
        /**
         * The status of the market, for example ACTIVE, SUSPENDED, SETTLED, etc.
         */
        MarketStatus status;
        /**
         * The number of seconds an order is held until it is submitted into the market. Orders are
         * usually delayed when the market is in-play
         */
        Optional<int32_t> betDelay;
        /**
         * True if the market starting price has been reconciled
         */
        Optional<bool> bspReconciled;

        Optional<bool> complete;
        /**
         * True if the market is currently in play
         */
        Optional<bool> inplay;
        /**
         * The number of selections that could be settled as winners
         */
        Optional<int32_t> numberOfWinners;
        /**
         * The number of runners in the market
         */
        Optional<int32_t> numberOfRunners;
        /**
         * The number of runners that are currently active. An active runner is a selection
         * available for betting
         */
        Optional<int32_t> numberOfActiveRunners;
        /**
         * The most recent time an order was executed
         */
        std::tm lastMatchTime;
        /**
         * The total amount matched. This value is truncated at 2dp.
         */
        Optional<double> totalMatched;
        /**
         * The total amount of orders that remain unmatched. This value is truncated at 2dp.
         */
        Optional<double> totalAvailable;
        /**
         * True if cross matching is enabled for this market.
         */
        Optional<bool> crossMatching;
        /**
         * True if runners in the market can be voided
         */
        Optional<bool> runnersVoidable;
        /**
         * The version of the market. The version increments whenever the market status changes,
         * for example, turning in-play, or suspended when a goal score.
         */
        Optional<int64_t> version;
        /**
         * Information about the runners (selections) in the market.
         */
        std::vector<Runner> runners;
        /**
         * Description of a markets key line for valid market types
         */
        KeyLineDescription keyLineDescription;
};

}

#endif // MARKETBOOK_H
