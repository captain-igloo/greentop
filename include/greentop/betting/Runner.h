#ifndef RUNNER_H
#define RUNNER_H

#include <ctime>
#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/betting/ExchangePrices.h"
#include "greentop/betting/Match.h"
#include "greentop/betting/Order.h"
#include "greentop/betting/StartingPrices.h"
#include "greentop/enum/RunnerStatus.h"

namespace greentop {

class Runner : public JsonMember {
    public:
        Runner();

        Runner(const uint64_t selectionId,
            const double handicap,
            const RunnerStatus& status,
            const double adjustmentFactor,
            const double lastPriceTraded = -1,
            const double totalMatched = -1,
            const std::tm& removalDate = std::tm(),
            const StartingPrices& sp = StartingPrices(),
            const ExchangePrices& ex = ExchangePrices(),
            const std::vector<Order>& orders = std::vector<Order>(),
            const std::vector<Match>& matches = std::vector<Match>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const RunnerStatus& getStatus() const;
        void setStatus(const RunnerStatus& status);

        const double getAdjustmentFactor() const;
        void setAdjustmentFactor(const double adjustmentFactor);

        const double getLastPriceTraded() const;
        void setLastPriceTraded(const double lastPriceTraded);

        const double getTotalMatched() const;
        void setTotalMatched(const double totalMatched);

        const std::tm& getRemovalDate() const;
        void setRemovalDate(const std::tm& removalDate);

        const StartingPrices& getSp() const;
        void setSp(const StartingPrices& sp);

        const ExchangePrices& getEx() const;
        void setEx(const ExchangePrices& ex);

        const std::vector<Order>& getOrders() const;
        void setOrders(const std::vector<Order>& orders);

        const std::vector<Match>& getMatches() const;
        void setMatches(const std::vector<Match>& matches);


    private:
        uint64_t selectionId;
        double handicap;
        RunnerStatus status;
        double adjustmentFactor;
        double lastPriceTraded;
        double totalMatched;
        std::tm removalDate;
        StartingPrices sp;
        ExchangePrices ex;
        std::vector<Order> orders;
        std::vector<Match> matches;
};

}

#endif // RUNNER_H


