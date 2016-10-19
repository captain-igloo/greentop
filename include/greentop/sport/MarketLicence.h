/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETLICENCE_H
#define MARKETLICENCE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

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
        std::string wallet;
        std::string rules;
        Optional<bool> rulesHasDate;
        std::string clarifications;
};

}

#endif // MARKETLICENCE_H


