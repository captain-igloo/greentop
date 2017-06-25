/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
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
#include "greentop/account/enum/ItemClass.h"

namespace greentop {
/**
 * Summary of a cleared order.
 */
class StatementItem : public JsonMember {
    public:

        StatementItem(const std::string& refId = std::string(),
            const std::tm& itemDate = std::tm(),
            const Optional<double>& amount = Optional<double>(),
            const Optional<double>& balance = Optional<double>(),
            const ItemClass& itemClass = ItemClass(),
            const std::map<std::string, std::string> itemClassData = std::map<std::string, std::string>(),
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

        const std::map<std::string, std::string>& getItemClassData() const;
        void setItemClassData(const std::map<std::string, std::string>& itemClassData);

        const StatementLegacyData& getLegacyData() const;
        void setLegacyData(const StatementLegacyData& legacyData);


    private:
        /**
         * An external reference, eg. equivalent to betId in the case of an exchange bet statement
         * item.
         */
        std::string refId;
        /**
         * The date and time of the statement item, eg. equivalent to settledData for an exchange
         * bet statement item. (in ISO-8601 format, not translated)
         */
        std::tm itemDate;
        /**
         * The amount of money the balance is adjusted by
         */
        Optional<double> amount;
        /**
         * Account balance.
         */
        Optional<double> balance;
        /**
         * Class of statement item. This value will determine which set of keys will be included in
         * itemClassData
         */
        ItemClass itemClass;
        /**
         * Key value pairs describing the current statement item. The set of keys will be
         * determined by the itemClass
         */
        std::map<std::string, std::string> itemClassData;
        /**
         * Set of fields originally returned from APIv6. Provided to facilitate migration from
         * APIv6 to API-NG, and ultimately onto itemClass and itemClassData
         */
        StatementLegacyData legacyData;
};

}

#endif // STATEMENTITEM_H
