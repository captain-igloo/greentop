/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETDESCRIPTION_H
#define MARKETDESCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/MarketLineRangeInfo.h"
#include "greentop/sport/PriceLadderDescription.h"
#include "greentop/sport/enum/MarketBettingType.h"

namespace greentop {
/**
 * Market definition
 */
class MarketDescription : public JsonMember {
    public:
        MarketDescription();

        MarketDescription(const Optional<bool>& persistenceEnabled,
            const Optional<bool>& bspMarket,
            const std::tm& marketTime,
            const std::tm& suspendTime,
            const std::tm& settleTime = std::tm(),
            const MarketBettingType& bettingType = MarketBettingType(),
            const Optional<bool>& turnInPlayEnabled = Optional<bool>(),
            const std::string& marketType = std::string(),
            const std::string& regulator = std::string(),
            const Optional<double>& marketBaseRate = Optional<double>(),
            const Optional<bool>& discountAllowed = Optional<bool>(),
            const std::string& wallet = std::string(),
            const std::string& rules = std::string(),
            const Optional<bool>& rulesHasDate = Optional<bool>(),
            const std::string& clarifications = std::string(),
            const Optional<double>& eachWayDivisor = Optional<double>(),
            const MarketLineRangeInfo& lineRangeInfo = MarketLineRangeInfo(),
            const std::string& raceType = std::string(),
            const PriceLadderDescription& priceLadderDescription = PriceLadderDescription());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<bool>& getPersistenceEnabled() const;
        void setPersistenceEnabled(const Optional<bool>& persistenceEnabled);

        const Optional<bool>& getBspMarket() const;
        void setBspMarket(const Optional<bool>& bspMarket);

        const std::tm& getMarketTime() const;
        void setMarketTime(const std::tm& marketTime);

        const std::tm& getSuspendTime() const;
        void setSuspendTime(const std::tm& suspendTime);

        const std::tm& getSettleTime() const;
        void setSettleTime(const std::tm& settleTime);

        const MarketBettingType& getBettingType() const;
        void setBettingType(const MarketBettingType& bettingType);

        const Optional<bool>& getTurnInPlayEnabled() const;
        void setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const std::string& getRegulator() const;
        void setRegulator(const std::string& regulator);

        const Optional<double>& getMarketBaseRate() const;
        void setMarketBaseRate(const Optional<double>& marketBaseRate);

        const Optional<bool>& getDiscountAllowed() const;
        void setDiscountAllowed(const Optional<bool>& discountAllowed);

        const std::string& getWallet() const;
        void setWallet(const std::string& wallet);

        const std::string& getRules() const;
        void setRules(const std::string& rules);

        const Optional<bool>& getRulesHasDate() const;
        void setRulesHasDate(const Optional<bool>& rulesHasDate);

        const std::string& getClarifications() const;
        void setClarifications(const std::string& clarifications);

        const Optional<double>& getEachWayDivisor() const;
        void setEachWayDivisor(const Optional<double>& eachWayDivisor);

        const MarketLineRangeInfo& getLineRangeInfo() const;
        void setLineRangeInfo(const MarketLineRangeInfo& lineRangeInfo);

        const std::string& getRaceType() const;
        void setRaceType(const std::string& raceType);

        const PriceLadderDescription& getPriceLadderDescription() const;
        void setPriceLadderDescription(const PriceLadderDescription& priceLadderDescription);


    private:
        /**
         * persistenceMarket
         */
        Optional<bool> persistenceEnabled;
        /**
         * bspMarket
         */
        Optional<bool> bspMarket;
        /**
         * marketTime
         */
        std::tm marketTime;
        /**
         * marketSuspendTime
         */
        std::tm suspendTime;
        /**
         * settled time
         */
        std::tm settleTime;
        /**
         * bettingType
         */
        MarketBettingType bettingType;
        /**
         * canTurnInPlay
         */
        Optional<bool> turnInPlayEnabled;
        /**
         * market base type
         */
        std::string marketType;
        /**
         * the market regulator
         */
        std::string regulator;

        Optional<double> marketBaseRate;

        Optional<bool> discountAllowed;

        std::string wallet;

        std::string rules;

        Optional<bool> rulesHasDate;

        std::string clarifications;
        /**
         * Each Way Divisor for E/W markets
         */
        Optional<double> eachWayDivisor;
        /**
         * Line range info for Line markets and some variants of Handicap markets
         */
        MarketLineRangeInfo lineRangeInfo;
        /**
         * An external identifier of a race type
         */
        std::string raceType;
        /**
         * Details about the price ladder in use for this market.
         */
        PriceLadderDescription priceLadderDescription;
};

}

#endif // MARKETDESCRIPTION_H
