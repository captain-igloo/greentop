/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STATEMENTLEGACYDATA_H
#define STATEMENTLEGACYDATA_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

class StatementLegacyData : public JsonMember {
    public:

        StatementLegacyData(const Optional<double>& avgPrice = Optional<double>(),
            const Optional<double>& betSize = Optional<double>(),
            const std::string& betType = std::string(),
            const std::string& betCategoryType = std::string(),
            const std::string& commissionRate = std::string(),
            const uint64_t eventId = 0,
            const uint64_t eventTypeId = 0,
            const std::string& fullMarketName = std::string(),
            const Optional<double>& grossBetAmount = Optional<double>(),
            const std::string& marketName = std::string(),
            const std::string& marketType = std::string(),
            const std::tm& placedDate = std::tm(),
            const uint64_t selectionId = 0,
            const std::string& selectionName = std::string(),
            const std::tm& startDate = std::tm(),
            const std::string& transactionType = std::string(),
            const uint64_t transactionId = 0,
            const std::string& winLose = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getAvgPrice() const;
        void setAvgPrice(const Optional<double>& avgPrice);

        const Optional<double>& getBetSize() const;
        void setBetSize(const Optional<double>& betSize);

        const std::string& getBetType() const;
        void setBetType(const std::string& betType);

        const std::string& getBetCategoryType() const;
        void setBetCategoryType(const std::string& betCategoryType);

        const std::string& getCommissionRate() const;
        void setCommissionRate(const std::string& commissionRate);

        const uint64_t getEventId() const;
        void setEventId(const uint64_t eventId);

        const uint64_t getEventTypeId() const;
        void setEventTypeId(const uint64_t eventTypeId);

        const std::string& getFullMarketName() const;
        void setFullMarketName(const std::string& fullMarketName);

        const Optional<double>& getGrossBetAmount() const;
        void setGrossBetAmount(const Optional<double>& grossBetAmount);

        const std::string& getMarketName() const;
        void setMarketName(const std::string& marketName);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const std::tm& getPlacedDate() const;
        void setPlacedDate(const std::tm& placedDate);

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const std::string& getSelectionName() const;
        void setSelectionName(const std::string& selectionName);

        const std::tm& getStartDate() const;
        void setStartDate(const std::tm& startDate);

        const std::string& getTransactionType() const;
        void setTransactionType(const std::string& transactionType);

        const uint64_t getTransactionId() const;
        void setTransactionId(const uint64_t transactionId);

        const std::string& getWinLose() const;
        void setWinLose(const std::string& winLose);


    private:
        Optional<double> avgPrice;
        Optional<double> betSize;
        std::string betType;
        std::string betCategoryType;
        std::string commissionRate;
        uint64_t eventId;
        uint64_t eventTypeId;
        std::string fullMarketName;
        Optional<double> grossBetAmount;
        std::string marketName;
        std::string marketType;
        std::tm placedDate;
        uint64_t selectionId;
        std::string selectionName;
        std::tm startDate;
        std::string transactionType;
        uint64_t transactionId;
        std::string winLose;
};

}

#endif // STATEMENTLEGACYDATA_H


