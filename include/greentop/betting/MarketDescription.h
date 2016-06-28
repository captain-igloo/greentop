/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETDESCRIPTION_H
#define MARKETDESCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/enum/MarketBettingType.h"

namespace greentop {

class MarketDescription : public JsonMember {
    public:
        MarketDescription();

        MarketDescription(const bool persistenceEnabled,
            const bool bspMarket,
            const std::tm& marketTime,
            const std::tm& suspendTime,
            const std::tm& settleTime = std::tm(),
            const MarketBettingType& bettingType = MarketBettingType(),
            const bool turnInPlayEnabled = false,
            const std::string& marketType = std::string(),
            const std::string& regulator = std::string(),
            const double marketBaseRate = -1,
            const bool discountAllowed = false,
            const std::string& wallet = std::string(),
            const std::string& rules = std::string(),
            const Optional<bool>& rulesHasDate = Optional<bool>(),
            const std::string& clarifications = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const bool getPersistenceEnabled() const;
        void setPersistenceEnabled(const bool persistenceEnabled);

        const bool getBspMarket() const;
        void setBspMarket(const bool bspMarket);

        const std::tm& getMarketTime() const;
        void setMarketTime(const std::tm& marketTime);

        const std::tm& getSuspendTime() const;
        void setSuspendTime(const std::tm& suspendTime);

        const std::tm& getSettleTime() const;
        void setSettleTime(const std::tm& settleTime);

        const MarketBettingType& getBettingType() const;
        void setBettingType(const MarketBettingType& bettingType);

        const bool getTurnInPlayEnabled() const;
        void setTurnInPlayEnabled(const bool turnInPlayEnabled);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const std::string& getRegulator() const;
        void setRegulator(const std::string& regulator);

        const double getMarketBaseRate() const;
        void setMarketBaseRate(const double marketBaseRate);

        const bool getDiscountAllowed() const;
        void setDiscountAllowed(const bool discountAllowed);

        const std::string& getWallet() const;
        void setWallet(const std::string& wallet);

        const std::string& getRules() const;
        void setRules(const std::string& rules);

        const Optional<bool>& getRulesHasDate() const;
        void setRulesHasDate(const Optional<bool>& rulesHasDate);

        const std::string& getClarifications() const;
        void setClarifications(const std::string& clarifications);


    private:
        bool persistenceEnabled;
        bool bspMarket;
        std::tm marketTime;
        std::tm suspendTime;
        std::tm settleTime;
        MarketBettingType bettingType;
        bool turnInPlayEnabled;
        std::string marketType;
        std::string regulator;
        double marketBaseRate;
        bool discountAllowed;
        std::string wallet;
        std::string rules;
        Optional<bool> rulesHasDate;
        std::string clarifications;
};

}

#endif // MARKETDESCRIPTION_H


