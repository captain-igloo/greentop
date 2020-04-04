/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETLICENCE_H
#define SPORT_MARKETLICENCE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {
/**
 * Market Licence
 */
class MarketLicence : public JsonMember {
    public:
        MarketLicence();

        MarketLicence(const std::string& wallet,
            const std::string& rules = std::string(),
            const Optional<bool>& rulesHasDate = Optional<bool>(),
            const std::string& clarifications = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getWallet() const;
        void setWallet(const std::string& wallet);

        const std::string& getRules() const;
        void setRules(const std::string& rules);

        const Optional<bool>& getRulesHasDate() const;
        void setRulesHasDate(const Optional<bool>& rulesHasDate);

        const std::string& getClarifications() const;
        void setClarifications(const std::string& clarifications);


    private:
        /**
         * The wallet from which funds will be taken when betting on this market
         */
        std::string wallet;
        /**
         * The rules for this market
         */
        std::string rules;
        /**
         * The market's start date and time are relevant to the rules.
         */
        Optional<bool> rulesHasDate;
        /**
         * Clarifications to the rules for the market
         */
        std::string clarifications;
};

}
}

#endif // SPORT_MARKETLICENCE_H
