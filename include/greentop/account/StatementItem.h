/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STATEMENTITEM_H
#define STATEMENTITEM_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/account/StatementLegacyData.h"
#include "greentop/enum/ItemClass.h"

namespace greentop {

class StatementItem : public JsonMember {
    public:

        StatementItem(const std::string& refId = std::string(),
            const std::tm& itemDate = std::tm(),
            const Optional<double>& amount = Optional<double>(),
            const Optional<double>& balance = Optional<double>(),
            const ItemClass& itemClass = ItemClass(),
            const std::map<std::string,std::string>& itemClassData = std::map<std::string,std::string>(),
            const StatementLegacyData& legacyData = StatementLegacyData());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getRefId() const;
        void setRefId(const std::string& refId);

        const std::tm& getItemDate() const;
        void setItemDate(const std::tm& itemDate);

        const Optional<double>& getAmount() const;
        void setAmount(const Optional<double>& amount);

        const Optional<double>& getBalance() const;
        void setBalance(const Optional<double>& balance);

        const ItemClass& getItemClass() const;
        void setItemClass(const ItemClass& itemClass);

        const std::map<std::string,std::string>& getItemClassData() const;
        void setItemClassData(const std::map<std::string,std::string>& itemClassData);

        const StatementLegacyData& getLegacyData() const;
        void setLegacyData(const StatementLegacyData& legacyData);


    private:
        std::string refId;
        std::tm itemDate;
        Optional<double> amount;
        Optional<double> balance;
        ItemClass itemClass;
        std::map<std::string,std::string> itemClassData;
        StatementLegacyData legacyData;
};

}

#endif // STATEMENTITEM_H


