/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETDESCRIPTION_H
#define MARKETDESCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonMember.h"
#include "greentop/enum/MarketBettingType.h"

namespace greentop {

class MarketDescription : public JsonMember {
    public:
        MarketDescription();

        MarketDescription(const BoolJsonMember& persistenceEnabled,
            const BoolJsonMember& bspMarket,
            const std::tm& marketTime,
            const std::tm& suspendTime,
            const std::tm& settleTime,
            const MarketBettingType& bettingType,
            const BoolJsonMember& turnInPlayEnabled,
            const std::string& marketType,
            const std::string& regulator,
            const double marketBaseRate,
            const BoolJsonMember& discountAllowed,
            const std::string& wallet = std::string(),
            const std::string& rules = std::string(),
            const BoolJsonMember& rulesHasDate = BoolJsonMember(),
            const std::string& clarifications = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const BoolJsonMember& getPersistenceEnabled() const;
        void setPersistenceEnabled(const BoolJsonMember& persistenceEnabled);

        const BoolJsonMember& getBspMarket() const;
        void setBspMarket(const BoolJsonMember& bspMarket);

        const std::tm& getMarketTime() const;
        void setMarketTime(const std::tm& marketTime);

        const std::tm& getSuspendTime() const;
        void setSuspendTime(const std::tm& suspendTime);

        const std::tm& getSettleTime() const;
        void setSettleTime(const std::tm& settleTime);

        const MarketBettingType& getBettingType() const;
        void setBettingType(const MarketBettingType& bettingType);

        const BoolJsonMember& getTurnInPlayEnabled() const;
        void setTurnInPlayEnabled(const BoolJsonMember& turnInPlayEnabled);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const std::string& getRegulator() const;
        void setRegulator(const std::string& regulator);

        const double getMarketBaseRate() const;
        void setMarketBaseRate(const double marketBaseRate);

        const BoolJsonMember& getDiscountAllowed() const;
        void setDiscountAllowed(const BoolJsonMember& discountAllowed);

        const std::string& getWallet() const;
        void setWallet(const std::string& wallet);

        const std::string& getRules() const;
        void setRules(const std::string& rules);

        const BoolJsonMember& getRulesHasDate() const;
        void setRulesHasDate(const BoolJsonMember& rulesHasDate);

        const std::string& getClarifications() const;
        void setClarifications(const std::string& clarifications);


    private:
        BoolJsonMember persistenceEnabled;
        BoolJsonMember bspMarket;
        std::tm marketTime;
        std::tm suspendTime;
        std::tm settleTime;
        MarketBettingType bettingType;
        BoolJsonMember turnInPlayEnabled;
        std::string marketType;
        std::string regulator;
        double marketBaseRate;
        BoolJsonMember discountAllowed;
        std::string wallet;
        std::string rules;
        BoolJsonMember rulesHasDate;
        std::string clarifications;
};

}

#endif // MARKETDESCRIPTION_H


